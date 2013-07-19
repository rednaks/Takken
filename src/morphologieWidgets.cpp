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

ErosionWidget::ErosionWidget(MainWindow *parent){

  this->parent = parent;
  elemSlider = new QSlider;
  elemSlider->setOrientation(Qt::Horizontal);
  elemSlider->setMinimum(0);
  elemSlider->setMaximum(2);
  elemSlider->setValue(0);
  elemLabel = new QLabel(QString("Element : %1").arg(elemSlider->value()));
  connect(elemSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

  sizeSlider = new QSlider;
  sizeSlider->setOrientation(Qt::Horizontal);
  sizeSlider->setMinimum(0);
  sizeSlider->setMaximum(21);
  sizeLabel = new QLabel(QString("Taille : %1").arg(sizeSlider->value()));
  connect(sizeSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

  QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(elemSlider, elemLabel);
  formLayout->addRow(sizeSlider, sizeLabel);


  this->setLayout(formLayout);

}

ErosionWidget::~ErosionWidget() {}

void ErosionWidget::updateVal(int v){
  elemLabel->setText(QString("Element : %1").arg(elemSlider->value()));
  sizeLabel->setText(QString("Taille : %1").arg(sizeSlider->value()));
  this->parent->m->Erosion(elemSlider->value(), sizeSlider->value());
  this->parent->updateImage();

}
