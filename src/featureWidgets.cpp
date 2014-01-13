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

#include "featureWidgets.h"
#include "mainWindow.h"

using namespace feature;

/************************ BEGIN featureDetect  widget ****************************/
FeatureDetectWidget::FeatureDetectWidget(MainWindow *parent)
	:AbstractWidget(parent) {

  algoComboBox = new QComboBox;
  algoComboBox->addItem(QString("Harris"));
  algoComboBox->addItem(QString("SIFT"));
  algoComboBox->addItem(QString("SURF"));
  connect(algoComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updateVal(int)));

  algoLabel = new QLabel(QString("Algo :"));

  precisionSlider = new QSlider;
  precisionSlider->setMinimum(400);
  precisionSlider->setMaximum(800);
  precisionSlider->setValue(400);
  connect(precisionSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

  precisionLabel = new QLabel(QString("Precision : %1").arg(precisionSlider->value()));

 
  QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(new QLabel("Feature Detect"), new QLabel(""));
  formLayout->addRow(algoLabel, algoComboBox);
  formLayout->addRow(precisionSlider, precisionLabel);
  formLayout->addRow(new QLabel(""), mAboutPushButton);

  
	mDoc = new QString();
	updateDoc();
  
  this->setLayout(formLayout);
  this->hide();

}

FeatureDetectWidget::~FeatureDetectWidget() { }

void FeatureDetectWidget::updateVal(int){
  precisionLabel->setText(QString("Precision : %1").arg(precisionSlider->value()));
  this->parent->mFeature->featureDetect(algoComboBox->currentIndex(), precisionSlider->value());
	updateDoc();
  this->parent->updateImage();
 }

void FeatureDetectWidget::updateDoc(){

  switch(algoComboBox->currentIndex()){
  case 0:
  *mDoc = (QString(QString::fromUtf8("L’idée de Harris est la suivante : au niveau de ces pixels caractéristiques (qu’il nomme “corners” : coins, angles), l’intensité de l’image va varier de manière importante dans plusieurs directions. On va donc regarder la variation d’intensité de l’image autour de chaque pixel.")));
  break;
  case 1:
  *mDoc = (QString(QString::fromUtf8("scale-invariant feature transform (SIFT), que l'on peut traduire par « transformation de caractéristiques visuelles invariante à l'échelle », est un algorithme utilisé dans le domaine de la vision par ordinateur pour détecter et identifier les éléments similaires entre différentes images numériques (éléments de paysages, objets, personnes, etc.). Il a été développé en 1999 par le chercheur David Lowe.")));
  break;
  case 2:
  *mDoc = (QString(QString::fromUtf8("Speeded Up Robust Features (SURF),m’approche proposée utilise une approximation de la matrice hessienne afin de détecter les structures de types « blobs». Elle utilise des images intégrales afin de diminuer fortement les temps de calculs car elles permettent le calcul rapide des convolutions avec les approximations de types « box-filters ». ")));
  break;
  }

}

/***********************  END featureDectect Widget ****************************/
/************************ BEGIN faceDetect widget ****************************/

FaceDetectWidget::FaceDetectWidget(MainWindow *parent):AbstractWidget(parent) {
   
  b=new QPushButton;
  b->setText("Detect");
  connect(b, SIGNAL(clicked()), this, SLOT(updateVal(int)));


  QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(new QLabel("Face Detect"), new QLabel(""));
  formLayout->addRow(b);
   formLayout->addRow(new QLabel(""), mAboutPushButton);

  mDoc = new QString(QString::fromUtf8("Un classificateur Haar est une approche de l'apprentissage automatique pour la détection d'objet visuel développé à l'origine par Viola et Jones. Il était initialement prévu pour la reconnaissance faciale, mais peut être utilisé pour n'importe quel objet. La puissance du classificateur Haar, c'est qu'il va rapidement rejeter les régions qui ont très peu de chances de contenir l'objet. Elle le fait en faisant usage de la cascade de classificateurs. Dans cette cascade, les premières étapes seront rapidement rejeter la majorité des faux régions et la détection d'objets peuvent se déplacer vers d'autres régions. Les étapes ultérieures nécessitent toutefois des efforts de plus en plus de calcul afin de rejeter la région. "));

  this->setLayout(formLayout);
  this->hide();
  }

FaceDetectWidget::~FaceDetectWidget() { }


void FaceDetectWidget::updateVal(int){
  
  this->parent->mFeature->faceDetect();
  this->parent->updateImage();


}


/***********************  END faceDetect Widget ****************************/

/************************ BEGIN featureFind widget ****************************/

FeatureFindWidget::FeatureFindWidget(MainWindow *parent):AbstractWidget(parent) {
  LoadLabel= new QLabel(QString("2nd image")) ;
  b=new QPushButton;
  b->setText("Load");
  connect(b, SIGNAL(clicked()), this, SLOT(updateVal(int)));


  QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(new QLabel("Feature Find"), new QLabel(""));
  formLayout->addRow(LoadLabel);
  formLayout->addRow(b);
  formLayout->addRow(new QLabel(""), mAboutPushButton);

  mDoc = new QString(QString::fromUtf8("L'analyse locale d'une image et qui caractérisent le contenu visuel de cette image de la façon la plus indépendante possible de l'échelle (« zoom » et résolution du capteur), du cadrage, de l'angle d'observation et de l'exposition (luminosité)."));

  this->setLayout(formLayout);
  this->hide();
  }

FeatureFindWidget::~FeatureFindWidget() { }


void FeatureFindWidget::updateVal(int){
  QString fname = QFileDialog::getOpenFileName(this, "Open File", "", tr("Images (*.jpg *.png)"));
  if(fname.length() == 0)
  return;
  cv::Mat obj = cv::imread(fname.toStdString());
  this->parent->mFeature->featureFind(obj);
  this->parent->updateImage();
  
}

/***********************  END featureFind Widget ****************************/

