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
/******************** END Bilateral Widget  ***********************************/

/******************** BEGIN Blur Widget ***********************************/
/******************** END Blur Widget  ***********************************/

/******************** BEGIN Median Widget ***********************************/
/******************** END  Median Widget  ***********************************/

/******************** BEGIN boxFiltre Widget ***********************************/
/******************** END boxFiltre Widget  ***********************************/

/******************** BEGIN Gaussien Widget ***********************************/
/******************** END Gaussien Widget  ***********************************/

/******************** BEGIN Laplacien Widget ***********************************/
/******************** END Laplacien Widget  ***********************************/

/******************** BEGIN Filtre2D Widget ***********************************/
/******************** END Filtre2D Widget  ***********************************/
/******************** BEGIN SepFilter Widget ***********************************/
/******************** END SepFilter Widget  ***********************************/

