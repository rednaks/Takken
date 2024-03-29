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
  connect(gaussienFiltreAction, SIGNAL(triggered()), this, SLOT(gaussienClicked()));
  connect(medianFiltreAction, SIGNAL(triggered()), this, SLOT(medianClicked()));
  connect(blurFiltreAction, SIGNAL(triggered()), this, SLOT(blurClicked()));
  connect(boxFiltreAction, SIGNAL(triggered()), this, SLOT(boxClicked()));
  connect(sep2DFiltreAction, SIGNAL(triggered()), this, SLOT(sep2DClicked()));
  connect(laplacienFiltreAction, SIGNAL(triggered()), this, SLOT(laplacienClicked()));
  connect(filtre2DFiltreAction, SIGNAL(triggered()), this, SLOT(filtre2DClicked()));
  connect(bilateralFiltreAction, SIGNAL(triggered()), this, SLOT(bilateralClicked()));


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
  connect(faceDetectAction, SIGNAL(triggered()), this, SLOT(faceDetectClicked()));
  connect(featureFindAction, SIGNAL(triggered()), this, SLOT(featureFindClicked()));
  //Ajout des action du menu Segmentation
  splitAndMergeSegAction = segMenu->addAction("Split And Merge");
  growinRegionSegAction = segMenu->addAction("Growing Region");
  thresholdingSegAction = segMenu->addAction("Thresholding");

  //Les connexion menu segmentation
  connect(thresholdingSegAction, SIGNAL(triggered()), this, SLOT(thresholdingClicked()));


  

  //Ajout des action du menu Help
  aboutHelpAction = helpMenu->addAction("About US");
  aboutQtAction = helpMenu->addAction("About Qt");

  //Les connexions menu help
  connect(aboutHelpAction, SIGNAL(triggered()), this, SLOT(aboutUsClicked()));
  connect(aboutQtAction, SIGNAL(triggered()), this, SLOT(aboutQtClicked()));

  //Associer la barre de menu à la fenetre
  setMenuBar(menuBar);

  mImageScene = new GraphicScene;
  mImageScene->setMinimumWidth(600);
  mImageScene->setAlignment(Qt::AlignCenter);


  mFiltre = new Filtre(src);
  bruitWidget = new filtre::BruitageWidget(this);
  sideBarWidgets.push_back(bruitWidget);
  gaussienWidget = new filtre::GaussienWidget(this);
  sideBarWidgets.push_back(gaussienWidget);
  medianWidget = new filtre::MedianWidget(this);
  sideBarWidgets.push_back(medianWidget);
  blurWidget = new filtre::BlurWidget(this);
  sideBarWidgets.push_back(blurWidget);
  boxFiltreWidget = new filtre::BoxFiltreWidget(this);
  sideBarWidgets.push_back(boxFiltreWidget);
  sepFilter2DWidget = new filtre::SepFilter2DWidget(this);
  sideBarWidgets.push_back(sepFilter2DWidget);
  laplacientWidget = new filtre::LaplacienWidget(this);
  sideBarWidgets.push_back(laplacientWidget);
  filtre2DWidget = new filtre::Filter2DWidget(this);
  sideBarWidgets.push_back(filtre2DWidget);
  bilateralWidget = new filtre::BilateralWidget(this);
  sideBarWidgets.push_back(bilateralWidget);


  mFeature = new Features(src);
  featureDetectWidget = new feature::FeatureDetectWidget(this);
  sideBarWidgets.push_back(featureDetectWidget);
  faceDetectWidget = new feature::FaceDetectWidget(this);
  sideBarWidgets.push_back(faceDetectWidget);
  featureFindWidget = new feature::FeatureFindWidget(this);
  sideBarWidgets.push_back(featureFindWidget);
  

  m = new Morphologie(src);
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
  splitter->addWidget(mImageScene);
  for(std::vector<QWidget*>::iterator iter = sideBarWidgets.begin(); iter != sideBarWidgets.end(); iter++)
    splitter->addWidget(*iter);

  setCentralWidget(splitter);
  //
  this->resize(800, 600);
  this->setWindowTitle(QString("Takken - mVision"));
}

MainWindow::~MainWindow(){ 
  delete menuBar;

}

QImage const MainWindow::Mat2QImage(const cv::Mat& src){
  return (QImage(src.data, src.cols, src.rows, src.step, QImage::Format_RGB888)).rgbSwapped();
                                
}

void MainWindow::updateImage(){

  QImage *img;
  if(this->currentWidget >= BRUIT_WIDGET && this->currentWidget <= BILATERAL_WIDGET)
    img = new QImage(Mat2QImage(mFiltre->out));
  else if(this->currentWidget >= FEATURE_DETECT_WIDGET && this->currentWidget <= FEATURE_FIND_WIDGET)
    img = new QImage(Mat2QImage(mFeature->out));
  else if(this->currentWidget >= EROSION_WIDGET && this->currentWidget <= GRADIENT_WIDGET)
    img = new QImage(Mat2QImage(m->dst));
  else if(this->currentWidget >= SPLIT_AND_MERGE_WIDGET && this->currentWidget <= THRESHOLDING_WIDGET)
    img = new QImage(Mat2QImage(mSegmentation->dst));



  /*
   * On doit retirer le splash de la mImage::mScene avant de
   * de la repaindre, car repaindre la scène revient à dértuire tout
   * les objects qui sont dans la scène
   */
  mImageScene->hideSplash(); 
  mImageScene->setImage(*img);
  delete img;
  }

void MainWindow::setSplashText(const QString &aString){
  mImageScene->setSplashText(aString);
}

void MainWindow::showSplash(){
  mImageScene->showSplash();
}

void MainWindow::hideSplash(){
  mImageScene->hideSplash();
}

bool MainWindow::splashIsVisible(){
  return mImageScene->splashIsVisible();
}

void MainWindow::openImage(){
  QString fname = QFileDialog::getOpenFileName(this, "Open File", "", tr("Images (*.jpg *.png)"));
  if(fname.length() == 0)
    return;
  src = cv::imread(fname.toStdString());
  QImage img(Mat2QImage(src));
  mImageScene->setImage(img);
}

void MainWindow::loadWidget(int widget){

  this->currentWidget = widget;
  hideAllSideBarWidgets();

  switch(widget){

    case BRUIT_WIDGET:
      bruitWidget->show();
      break;
    case GAUSSIEN_WIDGET:
      gaussienWidget->show();
      break;
    case MEDIAN_WIDGET:
      medianWidget->show();
      break;
    case BLUR_WIDGET:
      blurWidget->show();
      break;
    case BOX_WIDGET:
      boxFiltreWidget->show();
      break;
    case SEP_2D_WIDGET:
      sepFilter2DWidget->show();
      break;
    case LAPLACIEN_WIDGET:
      laplacientWidget->show();
      break;
    case FILTRE_2D_WIDGET:
      filtre2DWidget->show();
      break;
    case BILATERAL_WIDGET:
      bilateralWidget->show();
      break;
    case FEATURE_DETECT_WIDGET:
      featureDetectWidget->show();
      break;
    case FACE_DETECT_WIDGET:
      faceDetectWidget->show();
      break;
    case FEATURE_FIND_WIDGET:
      featureFindWidget->show();
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

  loadWidget(BRUIT_WIDGET);

}

void MainWindow::gaussienClicked(){
  if(!checkImageLoaded())
    return;

  loadWidget(GAUSSIEN_WIDGET);
}

void MainWindow::medianClicked(){
  if(!checkImageLoaded())
    return;
  
  loadWidget(MEDIAN_WIDGET);
}

void MainWindow::blurClicked(){
  if(!checkImageLoaded())
    return;
  
  loadWidget(BLUR_WIDGET);
}

void MainWindow::boxClicked(){
  if(!checkImageLoaded())
    return;

  loadWidget(BOX_WIDGET);
}

void MainWindow::sep2DClicked(){
  if(!checkImageLoaded())
    return;

  loadWidget(SEP_2D_WIDGET);
}

void MainWindow::laplacienClicked(){
  if(!checkImageLoaded())
    return;

  loadWidget(LAPLACIEN_WIDGET);
}

void MainWindow::filtre2DClicked(){
  if(!checkImageLoaded())
    return;
  loadWidget(FILTRE_2D_WIDGET);
}
void MainWindow::bilateralClicked(){
  if(!checkImageLoaded())
    return;

  loadWidget(BILATERAL_WIDGET);
}

void MainWindow::featureDetectClicked(){
  if(!checkImageLoaded())
    return;

    
  loadWidget(FEATURE_DETECT_WIDGET);

}


void MainWindow::faceDetectClicked(){
  if(!checkImageLoaded())
    return;

  
  loadWidget(FACE_DETECT_WIDGET);

}


void MainWindow::featureFindClicked(){
  if(!checkImageLoaded())
    return;
  
    
  loadWidget(FEATURE_FIND_WIDGET);

}

void MainWindow::erosionClicked(){
  if(!checkImageLoaded())
    return;

  loadWidget(EROSION_WIDGET);

}

void MainWindow::dilatationClicked(){
  if(!checkImageLoaded())
    return;

  loadWidget(DILATATION_WIDGET);

}

void MainWindow::ouvertureClicked(){
  if(!checkImageLoaded())
    return;

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

  loadWidget(GRADIENT_WIDGET);

}

void MainWindow::thresholdingClicked(){
  if(!checkImageLoaded())
    return;

  if(mSegmentation->src.empty())
    mSegmentation->src = this->src;

  loadWidget(THRESHOLDING_WIDGET);
}

void MainWindow::aboutUsClicked(){
  QMessageBox::about(this, QString("Takken"), QString::fromUtf8("<strong>mVision - Takken</strong> a été réalisé par :<br/><strong>Emna Fraj</strong><br/><strong>Amine Akrout</strong><br/><strong>Hermann Fotso</strong><br/><strong>Skander BM</strong>"));
}

void MainWindow::aboutQtClicked(){
  QMessageBox::aboutQt(this);
}

void MainWindow::hideAllSideBarWidgets(){
  for(std::vector<QWidget *>::iterator iter = sideBarWidgets.begin(); iter != sideBarWidgets.end(); iter++)
    (*iter)->hide();
}
