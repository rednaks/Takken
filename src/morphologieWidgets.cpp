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
#include "morphologieWidgets.h"
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace morphologie;

/************************ Erosion Widget BEGIN **************************/
ErosionWidget::ErosionWidget(MainWindow *parent){

  this->parent = parent;
  elemComboBox = new QComboBox;
  elemComboBox->addItem(QString("Rectangle"));
  elemComboBox->addItem(QString("Croix"));
  elemComboBox->addItem(QString::fromUtf8("Éllipse"));
  elemLabel = new QLabel(QString("Element : "));
  connect(elemComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updateVal(int)));

  sizeSlider = new QSlider;
  sizeSlider->setOrientation(Qt::Horizontal);
  sizeSlider->setMinimum(0);
  sizeSlider->setMaximum(21);
  sizeLabel = new QLabel(QString("Taille : %1").arg(sizeSlider->value()));
  connect(sizeSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

  mAboutPushButton = new QPushButton("About");
  connect(mAboutPushButton, SIGNAL(clicked()), this, SLOT(aboutClicked()));


  QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(elemLabel, elemComboBox);
  formLayout->addRow(sizeSlider, sizeLabel);
  formLayout->addRow(new QLabel(""), mAboutPushButton);

  mEroDoc = new QString(QString::fromUtf8("Cette opération permet d'éliminer les éléments" 
                                          "qui sont dans votre image ne pouvant pas contenir l'élément structurant"
                                          "(une forme géométrique carré, rectangle, cercle , disque )"
                                          "qui définit la façon dont votre image sera affectée et modifiée."
                                          "Pour réaliser une érosion , vous aurez besoin :"
                                          "-> de définir l'élément struturant de base(carré,rectangle,ellipse)"
                                          "à partir d'un widget."
                                          "-> de définir la proportion d'érosion que vous voulez appliquer"
                                          "sur votre image grace à"
                                          "un autre widget celui ci qui sera gradué de 0 à 21."));


  this->setLayout(formLayout);
  this->hide();

}

ErosionWidget::~ErosionWidget() {}

void ErosionWidget::updateVal(int v){
  sizeLabel->setText(QString("Taille : %1").arg(sizeSlider->value()));
  this->parent->m->Erosion(elemComboBox->currentIndex(), sizeSlider->value());
  this->parent->updateImage();

}

void ErosionWidget::aboutClicked(){
  this->parent->setSplashText(*mEroDoc);
  this->parent->showSplash();
}

/*********************** Erosion Widget END ******************************/

/*********************** Dilataion Widget BEGIN *************************/
DilatationWidget::DilatationWidget(MainWindow *parent){

  this->parent = parent;
  elemComboBox = new QComboBox;
  elemComboBox->addItem(QString("Rectangle"));
  elemComboBox->addItem(QString("Croix"));
  elemComboBox->addItem(QString::fromUtf8("Éllipse"));
  elemLabel = new QLabel(QString("Element : "));
  connect(elemComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updateVal(int)));

  sizeSlider = new QSlider;
  sizeSlider->setOrientation(Qt::Horizontal);
  sizeSlider->setMinimum(0);
  sizeSlider->setMaximum(21);
  sizeLabel = new QLabel(QString("Taille : %1").arg(sizeSlider->value()));
  connect(sizeSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

  QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(elemLabel, elemComboBox);
  formLayout->addRow(sizeSlider, sizeLabel);


  this->setLayout(formLayout);
  this->hide();

}

DilatationWidget::~DilatationWidget(){ }

void DilatationWidget::updateVal(int v){
  sizeLabel->setText(QString("Taille : %1").arg(sizeSlider->value()));
  this->parent->m->Dilatation(elemComboBox->currentIndex(), sizeSlider->value());
  this->parent->updateImage();

}

/*********************** Dilataion Widget END   *************************/

/*********************** Ouverture Widget BEGIN *************************/
OuvertureWidget::OuvertureWidget(MainWindow *parent){

  this->parent = parent;
  elemComboBox = new QComboBox;
  elemComboBox->addItem(QString("Rectangle"));
  elemComboBox->addItem(QString("Croix"));
  elemComboBox->addItem(QString::fromUtf8("Éllipse"));
  elemLabel = new QLabel(QString("Element : "));
  connect(elemComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updateVal(int)));

  sizeSlider = new QSlider;
  sizeSlider->setOrientation(Qt::Horizontal);
  sizeSlider->setMinimum(0);
  sizeSlider->setMaximum(21);
  sizeLabel = new QLabel(QString("Taille : %1").arg(sizeSlider->value()));
  connect(sizeSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

  QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(elemLabel, elemComboBox);
  formLayout->addRow(sizeSlider, sizeLabel);


  this->setLayout(formLayout);
  this->hide();

}

OuvertureWidget::~OuvertureWidget(){ }

void OuvertureWidget::updateVal(int v){
  sizeLabel->setText(QString("Taille : %1").arg(sizeSlider->value()));
  this->parent->m->Ouverture(elemComboBox->currentIndex(), sizeSlider->value());
  this->parent->updateImage();

}
/*********************** Ouverture Widget END *************************/

/*********************** Fermeture Widget BEGIN *************************/

FermetureWidget::FermetureWidget(MainWindow *parent){

  this->parent = parent;
  elemComboBox = new QComboBox;
  elemComboBox->addItem(QString("Rectangle"));
  elemComboBox->addItem(QString("Croix"));
  elemComboBox->addItem(QString::fromUtf8("Éllipse"));
  elemLabel = new QLabel(QString("Element : "));
  connect(elemComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updateVal(int)));

  sizeSlider = new QSlider;
  sizeSlider->setOrientation(Qt::Horizontal);
  sizeSlider->setMinimum(0);
  sizeSlider->setMaximum(21);
  sizeLabel = new QLabel(QString("Taille : %1").arg(sizeSlider->value()));
  connect(sizeSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

  QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(elemLabel, elemComboBox);
  formLayout->addRow(sizeSlider, sizeLabel);


  this->setLayout(formLayout);
  this->hide();

}

FermetureWidget::~FermetureWidget(){ }

void FermetureWidget::updateVal(int v){
  sizeLabel->setText(QString("Taille : %1").arg(sizeSlider->value()));
  this->parent->m->Fermeture(elemComboBox->currentIndex(), sizeSlider->value());
  this->parent->updateImage();
}
/*********************** Fermeture Widget END *************************/


GradientWidget::GradientWidget(MainWindow *parent){

  this->parent = parent;
  elemComboBox = new QComboBox;
  elemComboBox->addItem(QString("Rectangle"));
  elemComboBox->addItem(QString("Croix"));
  elemComboBox->addItem(QString::fromUtf8("Éllipse"));
  elemLabel = new QLabel(QString("Element : "));
  connect(elemComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updateVal(int)));

  sizeSlider = new QSlider;
  sizeSlider->setOrientation(Qt::Horizontal);
  sizeSlider->setMinimum(0);
  sizeSlider->setMaximum(21);
  sizeLabel = new QLabel(QString("Taille : %1").arg(sizeSlider->value()));
  connect(sizeSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

  QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(elemLabel, elemComboBox);
  formLayout->addRow(sizeSlider, sizeLabel);


  this->setLayout(formLayout);
  this->hide();

}

GradientWidget::~GradientWidget() { }

void GradientWidget::updateVal(int v){
  sizeLabel->setText(QString("Taille : %1").arg(sizeSlider->value()));
  this->parent->m->GradientMorph(elemComboBox->currentIndex(), sizeSlider->value());
  this->parent->updateImage();
}
/*********************** GradientWidget END   *************************/
