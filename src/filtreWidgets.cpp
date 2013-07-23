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

#include "filtreWidgets.h"
#include "mainWindow.h"

using namespace filtre;

/******************** Begin Bruitage Widget *****************************/
BruitageWidget::BruitageWidget(MainWindow* parent){

  this->parent = parent;
  densiteSlider = new QSlider;
  densiteSlider->setOrientation(Qt::Horizontal);
  densiteSlider->setMinimum(0);
  densiteSlider->setMaximum(50);
  connect(densiteSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

  densiteSpinBox = new QSpinBox;
  densiteSpinBox->setMinimum(0);
  densiteSpinBox->setMaximum(50);
  connect(densiteSpinBox, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

  densiteLabel = new QLabel(QString::fromUtf8("Densité :"));

  QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(densiteLabel, new QLabel(""));
  formLayout->addRow(densiteSlider, densiteSpinBox);

  this->setLayout(formLayout);
  this->hide();

}

BruitageWidget::~BruitageWidget(){ }

void BruitageWidget::updateVal(int v){
  printf("Val : %d\n",v);
  densiteSpinBox->setValue(v);
  densiteSlider->setValue(v);
  this->parent->mFiltre->bruit_sel_poivre(v);
  this->parent->updateImage();

}

/******************** END Bruitage Widget *****************************/

/******************** BEGIN Bilateral Widget ***********************************/
BilateralWidget::BilateralWidget(MainWindow* parent){
this->parent=parent;
diametreSlider= new QSlider;
diametreSlider->setOrientation(Qt::Horizontal);
diametreSlider->setMinimum(1);
diametreSlider->setMaximum(10);
connect(diametreSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

diametreLabel = new QLabel (QString::fromUtf8("Diametre :"));

SigmaColorSlider = new QSlider;
SigmaColorSlider->setOrientation(Qt::Horizontal);
SigmaColorSlider->setMinimum(0);
SigmaColorSlider->setMaximum(100);
connect(SigmaColorSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

SigmaColorLabel = new QLabel(QString::fromUtf8("SigmaColor :"));


SigmaSpaceSlider = new QSlider;
SigmaSpaceSlider->setOrientation(Qt::Horizontal);
SigmaSpaceSlider->setMinimum(0);
SigmaSpaceSlider->setMaximum(100);
connect(SigmaSpaceSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

SigmaSpaceLabel = new QLabel(QString::fromUtf8("SigmaColor :"));

QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(diametreLabel, new QLabel(""));
  formLayout->addRow(diametreSlider);
  formLayout->addRow(sigmaColorLabel, new QLabel(""));
  formLayout->addRow(sigmaColorSlider);
  formLayout->addRow(sigmaSpaceLabel, new QLabel(""));
  formLayout->addRow(sigmaSpaceSlider);

  this->setLayout(formLayout);
  this->hide();


}

BilateralWidget::~BilateralWidget(){}

void BilateralWidget::updateVal(int v){
    printf("Val : %d\n",v);
    this->parent->mFiltre->bilateralFiltre(diametreSlider->value(),SigmaColorSlider->value(),SigmaSpaceSlider->value());
    this->parent->updateImage();
}
/******************** END Bilateral Widget  ***********************************/

/******************** BEGIN Blur Widget ***********************************/
BlurWidget::BlurWidget(MainWindow* parent){
this->parent = parent;
noyauSlider = new QSlider;
noyauSlider->setOrientation(Qt::Horizontal);
noyauSlider->setMinimum(1);
noyauSlider->setMaximum(40);
connect(noyauSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));


noyauSpinBox= new QSpinBox;
noyauSpinBox->setMinimum(1);
noyauSpinBox->setMaximum(40);
connect(noyauSpinBox, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

noyauLabel =new QLabel(QString::fromUtf8("Noyau:"));


  QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(noyauLabel, new QLabel(""));
  formLayout->addRow(noyauSlider, noyauSpinBox);


  this->setLayout(formLayout);
  this->hide();
}

BlurWidget::~BlurWidget(){ }

void BlurWidget::updateVal(int v){
printf("Val : %d\n",v);
  noyauSpinBox->setValue(v);
  noyauSlider->setValue(v);
  this->parent->mFiltre->blurFiltre(Size(v,v));
  this->parent->updateImage();
}
/******************** END Blur Widget  ***********************************/

/******************** BEGIN Median Widget ***********************************/

MedianWidget::MedianWidget(MainWindow* parent){
this->parent = parent;
noyauSlider = new QSlider;
noyauSlider->setOrientation(Qt::Horizontal);
noyauSlider->setMinimum(1);
noyauSlider->setMaximum(41);
noyauSlider->setSingleStep(2);
connect(noyauSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

noyauLabel =new QLabel(QString::fromUtf8("Noyau:"));


  QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(noyauLabel, new QLabel(""));
  formLayout->addRow(noyauSlider);


  this->setLayout(formLayout);
  this->hide();
}

MedianWidget::~MedianWidget(){}

void MedianWidget::updateVal(int v){
printf("Val : %d\n",v);
  noyauSlider->setValue(v);
  this->parent->mFiltre->medianFiltre(v);
  this->parent->updateImage();
}


/******************** END  Median Widget  ***********************************/

/******************** BEGIN boxFiltre Widget ***********************************/
BoxFiltreWidget::BoxFiltreWidget(MainWindow* parent){
this->parent = parent;
noyauSlider = new QSlider;
noyauSlider->setOrientation(Qt::Horizontal);
noyauSlider->setMinimum(1);
noyauSlider->setMaximum(40);
connect(noyauSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));


noyauSpinBox= new QSpinBox;
noyauSpinBox->setMinimum(1);
noyauSpinBox->setMaximum(40);
connect(noyauSpinBox, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

noyauLabel =new QLabel(QString::fromUtf8("Noyau:"));


  QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(noyauLabel, new QLabel(""));
  formLayout->addRow(noyauSlider, noyauSpinBox);


  this->setLayout(formLayout);
  this->hide();
}

BoxFiltreWidget::~BoxFiltreWidget(){ }

void BoxFiltreWidget::updateVal(int v){
printf("Val : %d\n",v);
  noyauSpinBox->setValue(v);
  noyauSlider->setValue(v);
  this->parent->mFiltre->boxFiltre(Size(v,v));
  this->parent->updateImage();
}

/******************** END boxFiltre Widget  ***********************************/

/******************** BEGIN Gaussien Widget ***********************************/

GaussienWidget::GaussienWidget(MainWindow* parent){
this->parent=parent;
noyauSlider= new QSlider;
noyauSlider->setOrientation(Qt::Horizontal);
noyauSlider->setMinimum(1);
noyauSlider->setMaximum(41);
noyauSlider->setSingleStep(2);
connect(noyauSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

noyauLabel = new QLabel (QString::fromUtf8("taille du noyau :"));

SigmaXSlider = new QSlider;
SigmaXSlider->setOrientation(Qt::Horizontal);
SigmaXSlider->setMinimum(0);
SigmaXSlider->setMaximum(10);
connect(SigmaXSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

SigmaXLabel = new QLabel(QString::fromUtf8("Deviation par rapport a x :"));


SigmaYSlider = new QSlider;
SigmaYSlider->setOrientation(Qt::Horizontal);
SigmaYSlider->setMinimum(0);
SigmaYSlider->setMaximum(10);
connect(SigmaYSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal()));

SigmaYLabel = new QLabel(QString::fromUtf8("Deviation par rapport a y :"));

QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(noyauLabel, new QLabel(""));
  formLayout->addRow(noyauSlider);
  formLayout->addRow(sigmaXLabel, new QLabel(""));
  formLayout->addRow(sigmaXSlider);
  formLayout->addRow(sigmaYLabel, new QLabel(""));
  formLayout->addRow(sigmaYSlider);

  this->setLayout(formLayout);
  this->hide();


}

GaussienWidget::~GaussienWidget(){}

void GaussienWidget::updateVal(int v){
    printf("Val : %d\n",v);
    this->parent->mFiltre->gaussienFiltre(Size (noyauSlider->value(),noyauSlider->value()),SigmaXSlider->value(),SigmaYSlider->value());
    this->parent->updateImage();
}

/******************** END Gaussien Widget  ***********************************/

/******************** BEGIN Laplacien Widget ***********************************/
LaplacienWidget::LaplacienWidget(MainWindow* parent){
this->parent=parent;
noyauGaussSlider= new QSlider;
noyauGaussSlider->setOrientation(Qt::Horizontal);
noyauGaussSlider->setMinimum(1);
noyauGaussSlider->setMaximum(41);
noyauGaussSlider->setSingleStep(2);
connect(noyauGaussSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

noyauGaussLabel = new QLabel (QString::fromUtf8("noyau gaussien :"));

noyauLaplaceSlider = new QSlider;
noyauLaplaceSlider->setOrientation(Qt::Horizontal);
noyauLaplaceSlider->setMinimum(1);
noyauLaplaceSlider->setMaximum(9);
noyauLaplaceSlider->setSingleStep(2);
connect(noyauLaplaceSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

noyauLaplaceLabel = new QLabel(QString::fromUtf8("noyau laplacien :"));

QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(noyauGaussLabel, new QLabel(""));
  formLayout->addRow(noyauGaussSlider);
  formLayout->addRow(noyauLaplaceLabel, new QLabel(""));
  formLayout->addRow(noyauLaplaceSlider);

  this->setLayout(formLayout);
  this->hide();


}

LaplacienWidget::~LaplacienWidget(){}

void LaplacienWidget::updateVal(int v){
    printf("Val : %d\n",v);
    this->parent->mFiltre->LaplacienFiltre(Size(noyauGaussSlider->value(),noyauGaussSlider->value()),noyauLaplaceSlider->value());
    this->parent->updateImage();

}
/******************** END Laplacien Widget  ***********************************/

/******************** BEGIN Filtre2D Widget ***********************************/
Filter2DWidget::Filter2DWidget(MainWindow* parent){
this->parent = parent;
noyauSlider = new QSlider;
noyauSlider->setOrientation(Qt::Horizontal);
noyauSlider->setMinimum(1);
noyauSlider->setMaximum(40);
connect(noyauSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));


noyauSpinBox= new QSpinBox;
noyauSpinBox->setMinimum(1);
noyauSpinBox->setMaximum(40);
connect(noyauSpinBox, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

noyauLabel =new QLabel(QString::fromUtf8("Noyau:"));


  QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(noyauLabel, new QLabel(""));
  formLayout->addRow(noyauSlider, noyauSpinBox);


  this->setLayout(formLayout);
  this->hide();
}

Filter2DWidget::~Filter2DWidget(){}

void Filter2DWidget::updateVal(int v){
printf("Val : %d\n",v);
  noyauSpinBox->setValue(v);
  noyauSlider->setValue(v);
  this->parent->mFiltre->filter2DFiltre(v);
  this->parent->updateImage();
}

/******************** END Filtre2D Widget  ***********************************/
/******************** BEGIN SepFilter Widget ***********************************/
sepFilter2DWidget::sepFilter2DWidget(MainWindow* parent){
this->parent=parent;
noyauLigneSlider= new QSlider;
noyauLigneSlider->setOrientation(Qt::Horizontal);
noyauLigneSlider->setMinimum(1);
noyauLigneSlider->setMaximum(20);
connect(noyauLigneSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

noyauLigneLabel = new QLabel (QString::fromUtf8("noyau des lignes :"));

noyauColonneSlider = new QSlider;
noyauColonneSlider->setOrientation(Qt::Horizontal);
noyauColonneSlider->setMinimum(0);
noyauColonneSlider->setMaximum(100);
connect(noyauColonneSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

noyauColonneLabel = new QLabel(QString::fromUtf8("noyau des colonnes :"));

QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(noyauLigneLabel, new QLabel(""));
  formLayout->addRow(noyauLigneSlider);
  formLayout->addRow(noyauColonneLabel, new QLabel(""));
  formLayout->addRow(noyauColonneSlider);

  this->setLayout(formLayout);
  this->hide();


}

sepFilter2DWidget::~sepFilter2DWidget(){}

void sepFilter2DWidget::updateVal(int v){
    printf("Val : %d\n",v);
    this->parent->mFiltre->sepFilter2DFiltre(noyauLigneSlider->value(),noyauColonneSlider->value());
    this->parent->updateImage();
}
/******************** END SepFilter Widget  ***********************************/

