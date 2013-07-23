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
#include "segmentationWidgets.h"
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace segmentation;

ThresholdingWidget::ThresholdingWidget(MainWindow *parent){

  this->parent = parent;
  minRSlider = new QSlider;
  minRSlider->setOrientation(Qt::Horizontal);
  minRSlider->setMinimum(0);
  minRSlider->setMaximum(255);
  minRSlider->setValue(0);
  rValueLabel = new QLabel(QString("R : %1").arg(minRSlider->value()));
  connect(minRSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

  minGSlider = new QSlider;
  minGSlider->setOrientation(Qt::Horizontal);
  minGSlider->setMinimum(0);
  minGSlider->setMaximum(255);
  gValueLabel = new QLabel(QString("G : %1").arg(minGSlider->value()));
  connect(minGSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

  minBSlider = new QSlider;
  minBSlider->setOrientation(Qt::Horizontal);
  minBSlider->setMinimum(0);
  minBSlider->setMaximum(255);
  bValueLabel = new QLabel(QString("B : %1").arg(minBSlider->value()));
  connect(minBSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

  // Max values
  maxRSlider = new QSlider;
  maxRSlider->setOrientation(Qt::Horizontal);
  maxRSlider->setMinimum(0);
  maxRSlider->setMaximum(255);
  maxRSlider->setValue(0);
  mrValueLabel = new QLabel(QString("R : ")+maxRSlider->value());
  connect(maxRSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

  maxGSlider = new QSlider;
  maxGSlider->setOrientation(Qt::Horizontal);
  maxGSlider->setMinimum(0);
  maxGSlider->setMaximum(255);
  mgValueLabel = new QLabel(QString("G : ")+maxGSlider->value());
  connect(maxGSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

  maxBSlider = new QSlider;
  maxBSlider->setOrientation(Qt::Horizontal);
  maxBSlider->setMinimum(0);
  maxBSlider->setMaximum(255);
  mbValueLabel = new QLabel(QString("B : ")+maxBSlider->value());
  connect(maxBSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

  QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(new QLabel("Min Values"), new QLabel(":"));
  formLayout->addRow(minRSlider, rValueLabel);
  formLayout->addRow(minGSlider, gValueLabel);
  formLayout->addRow(minBSlider, bValueLabel);

  formLayout->addRow(new QLabel("Max Values"), new QLabel(":"));
  formLayout->addRow(maxRSlider, mrValueLabel);
  formLayout->addRow(maxGSlider, mgValueLabel);
  formLayout->addRow(maxBSlider, mbValueLabel);


  this->setLayout(formLayout);
  this->hide();

}

ThresholdingWidget::~ThresholdingWidget() {}

void ThresholdingWidget::updateVal(int v){
  rValueLabel->setText(QString("R :%1").arg(minRSlider->value()));
  gValueLabel->setText(QString("G :%1").arg(minGSlider->value()));
  bValueLabel->setText(QString("B :%1").arg(minBSlider->value()));

  mrValueLabel->setText(QString("R :%1").arg(maxRSlider->value()));
  mgValueLabel->setText(QString("G :%1").arg(maxGSlider->value()));
  mbValueLabel->setText(QString("B :%1").arg(maxBSlider->value()));
   this->parent->mSegmentation->thresholding(cv::Scalar(minBSlider->value(), minGSlider->value(), minRSlider->value()), cv::Scalar(maxBSlider->value(), maxGSlider->value(), maxRSlider->value()));
  this->parent->updateImage();
  //cv::imshow("Testing Origin", this->parent->mSegmentation->src);
  //cv::imshow("Testing", this->parent->mSegmentation->dst);
}
