 /**
 * This file is under MIT Licence
 * Copyright (C) 2013 Alexandre BM <s@rednaks.tn>
 *   
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *   
 * The above copyright notice and this permission notice shall be included in all copies
 * or substantial portions of the Software.
 *   
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "mainWindow.h"


MainWindow::MainWindow(){

  // Création de la barre de menu
  menuBar = new QMenuBar(this);
  
  // Ajout des menu
  fileMenu = menuBar->addMenu(tr("&File"));
  editMenu = menuBar->addMenu(tr("&Edit"));
  filtresMenu = menuBar->addMenu(tr("&Filtres"));
  caracterisationMenu = menuBar->addMenu(QString::fromUtf8("&Caractérisation"));
  morphMathMenu = menuBar->addMenu(QString::fromUtf8("&Morph. Mathématique"));
  segMenu = menuBar->addMenu(tr("&Segmentation"));
  helpMenu = menuBar->addMenu(tr("&Help"));


  //Ajout des actions du menu File
  openFileAction = fileMenu->addAction("Ouvrir");
  saveFileAction = fileMenu->addAction("Save");
  saveAsFileAction = fileMenu->addAction("Save As");
  quitFileAction = fileMenu->addAction("Quit");

  //Les connexion
  connect(openFileAction, SIGNAL(triggered()), this, SLOT(openImage()));

  //Ajout des action du menu Filtres
  bruitFiltreAction = filtresMenu->addAction("Bruit: set et poivre");
  gaussienFiltreAction = filtresMenu->addAction("Gaussien");
  medianFiltreAction = filtresMenu->addAction("Median");
  blurFiltreAction = filtresMenu->addAction("Blur");
  boxFiltreAction = filtresMenu->addAction("Box");
  sep2DFiltreAction = filtresMenu->addAction("Sep 2D");
  laplacienFiltreAction = filtresMenu->addAction("Laplacien");
  filtre2DFiltreAction = filtresMenu->addAction("Filtre 2D");
  bilateralFiltreAction = filtresMenu->addAction("Bilateral");

  //Les connexion filtres
  connect(bruitFiltreAction, SIGNAL(triggered()), this, SLOT(bruitClicked()));

  //Ajout des action du menu Morphologie Mathématique 
  erosionMorphAction = morphMathMenu->addAction("Erosion");
  dilatationMorphAction = morphMathMenu->addAction("Dilatation");
  ouvertureMorphAction = morphMathMenu->addAction("Ouverture");
  fermetureMorphAction = morphMathMenu->addAction("Fermeture");
  gradientMorphAction = morphMathMenu->addAction("Gradient");

  //Les connexions
  connect(erosionMorphAction, SIGNAL(triggered()), this, SLOT(erosionClicked()));
  connect(dilatationMorphAction, SIGNAL(triggered()), this, SLOT(dilatationClicked()));
  connect(ouvertureMorphAction, SIGNAL(triggered()), this, SLOT(ouvertureClicked()));
  connect(fermetureMorphAction, SIGNAL(triggered()), this, SLOT(fermetureClicked()));
  connect(gradientMorphAction, SIGNAL(triggered()), this, SLOT(gradientClicked()));

  //Ajout des actions du menu Caractérisation 
  featureDetectAction = caracterisationMenu->addAction("Feature Detect");
  faceDetectAction = caracterisationMenu->addAction("Face Detect");
  featureFindAction = caracterisationMenu->addAction("Feature Find");

  //Les connexion pour le menu caractérisation 
  connect(featureDetectAction, SIGNAL(triggered()), this, SLOT(featureDetectClicked()));

  //Ajout des action du menu Segmentation
  splitAndMergeSegAction = segMenu->addAction("Split And Merge");
  growinRegionSegAction = segMenu->addAction("Growing Region");
  thresholdingSegAction = segMenu->addAction("Thresholding");

  //Les connexion menu segmentation
  connect(thresholdingSegAction, SIGNAL(triggered()), this, SLOT(thresholdingClicked()));


  

  //Ajout des action du menu Help
  aboutHelpAction = helpMenu->addAction("About");

  //Associer la barre de menu à la fenetre
  setMenuBar(menuBar);

  imageDispLabel = new QLabel;
  imageDispLabel->setAlignment(Qt::AlignCenter);
  imageDispLabel->setMinimumWidth(600);
  imageDispLabel->setStyleSheet(QString("QLabel { background: #687074}"));


  mFiltre = new Filtre;
  bruitWidget = new filtre::BruitageWidget(this);
  sideBarWidgets.push_back(bruitWidget);

  mFeature = new Features;
  featureDetectWidget = new feature::FeatureDetectWidget(this);
  sideBarWidgets.push_back(featureDetectWidget);

  m = new Morphologie;
  erosionWidget = new morphologie::ErosionWidget(this);
  sideBarWidgets.push_back(erosionWidget);
  dilatationWidget = new morphologie::DilatationWidget(this);
  sideBarWidgets.push_back(dilatationWidget);
  ouvertureWidget  = new morphologie::OuvertureWidget(this);
  sideBarWidgets.push_back(ouvertureWidget);
  fermetureWidget  = new morphologie::FermetureWidget(this);
  sideBarWidgets.push_back(fermetureWidget);
  gradientWidget   = new morphologie::GradientWidget(this);
  sideBarWidgets.push_back(gradientWidget);

  mSegmentation = new Segmentation;
  thresholdingWidget = new segmentation::ThresholdingWidget(this);
  sideBarWidgets.push_back(thresholdingWidget);

  splitter = new QSplitter;
  splitter->setOrientation(Qt::Horizontal);
  splitter->addWidget(imageDispLabel);
  for(std::vector<QWidget*>::iterator iter = sideBarWidgets.begin(); iter != sideBarWidgets.end(); iter++)
    splitter->addWidget(*iter);

  setCentralWidget(splitter);
  //
  this->resize(800, 600);
}

MainWindow::~MainWindow(){ 
  delete menuBar;

}

QImage const MainWindow::Mat2QImage(const cv::Mat& src){
  return (QImage(src.data, src.cols, src.rows, src.step, QImage::Format_RGB888)).rgbSwapped();
                                
}

void MainWindow::updateImage(){

  QImage *img;
  if(this->currentWidget == BRUIT_WIDGET)
    img = new QImage(Mat2QImage(mFiltre->out));
  else if(this->currentWidget >= FEATURE_DETECT_WIDGET && this->currentWidget <= FEATURE_FIND_WIDGET)
    img = new QImage(Mat2QImage(mFiltre->out));
  else if(this->currentWidget >= EROSION_WIDGET && this->currentWidget <= GRADIENT_WIDGET)
    img = new QImage(Mat2QImage(m->dst));
  else if(this->currentWidget >= SPLIT_AND_MERGE_WIDGET && this->currentWidget <= THRESHOLDING_WIDGET)
    img = new QImage(Mat2QImage(mSegmentation->dst));

  imageDispLabel->setPixmap(QPixmap::fromImage(*img));
  }

void MainWindow::openImage(){
  QString fname = QFileDialog::getOpenFileName(this, "Open File", "", tr("Images (*.jpg *.png)"));
  if(fname.length() == 0)
    return;
  src = cv::imread(fname.toStdString());
  QImage img(Mat2QImage(src));
  imageDispLabel->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::loadWidget(int widget){

  this->currentWidget = widget;
  hideAllSideBarWidgets();

  switch(widget){

    case BRUIT_WIDGET:
      bruitWidget->show();
      break;
    case FEATURE_DETECT_WIDGET:
      featureDetectWidget->show();
      break;
    case EROSION_WIDGET:
      erosionWidget->show();
      break;
    case DILATATION_WIDGET:
      dilatationWidget->show();
      break;
    case OUVERTURE_WIDGET:
      ouvertureWidget->show();
      break;
    case FERMETURE_WIDGET:
      fermetureWidget->show();
      break;
    case GRADIENT_WIDGET:
      gradientWidget->show();
      break;
    case THRESHOLDING_WIDGET:
      thresholdingWidget->show();
      break;

  }

}

bool MainWindow::checkImageLoaded(){
  if(src.empty()){
    int res = QMessageBox::warning(this, "mVision", "Vous devez ouvrir une image tout d'abord, \nvoulez vous le faire maintemant ?",
        QMessageBox::Yes,  QMessageBox::No);

   if(res == QMessageBox::Yes){
     openImage();
     return true;
   }
   else
     return false;
  }

  return true;

}

void MainWindow::bruitClicked(){
  if(!checkImageLoaded())
    return;
  if(mFiltre->image.empty())
    mFiltre->image = this->src;

  loadWidget(BRUIT_WIDGET);

}

void MainWindow::featureDetectClicked(){
  if(!checkImageLoaded())
    return;
  if(mFeature->img.empty())
    mFeature->img = this->src;
  
  loadWidget(FEATURE_DETECT_WIDGET);

}

void MainWindow::erosionClicked(){
  if(!checkImageLoaded())
    return;

  if(m->src.empty())
    m->src = this->src;

  loadWidget(EROSION_WIDGET);

}

void MainWindow::dilatationClicked(){
  if(!checkImageLoaded())
    return;

  if(m->src.empty())
    m->src = this->src;

  loadWidget(DILATATION_WIDGET);

}

void MainWindow::ouvertureClicked(){
  if(!checkImageLoaded())
    return;

  if(m->src.empty())
    m->src = this->src;

  loadWidget(OUVERTURE_WIDGET);

}

void MainWindow::fermetureClicked(){
  if(!checkImageLoaded())
    return;

  if(m->src.empty())
    m->src = this->src;

  loadWidget(FERMETURE_WIDGET);

}

void MainWindow::gradientClicked(){
  if(!checkImageLoaded())
    return;

  if(m->src.empty())
    m->src = this->src;

  loadWidget(GRADIENT_WIDGET);

}

void MainWindow::thresholdingClicked(){
  if(!checkImageLoaded())
    return;

  if(mSegmentation->src.empty())
    mSegmentation->src = this->src;

  loadWidget(THRESHOLDING_WIDGET);
}

void MainWindow::hideAllSideBarWidgets(){
  for(std::vector<QWidget *>::iterator iter = sideBarWidgets.begin(); iter != sideBarWidgets.end(); iter++)
    (*iter)->hide();
}
