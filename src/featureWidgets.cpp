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
FeatureDetectWidget::FeatureDetectWidget(MainWindow *parent){
   this->parent = parent;

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

  this->setLayout(formLayout);
  this->hide();

}

FeatureDetectWidget::~FeatureDetectWidget() { }

void FeatureDetectWidget::updateVal(int){
  precisionLabel->setText(QString("Precision : %1").arg(precisionSlider->value()));
  this->parent->mFeature->featureDetect(algoComboBox->currentIndex(), precisionSlider->value());
  this->parent->updateImage();
  cv::imshow("Res", this->parent->mFeature->out);

}
/***********************  END featureDectect Widget ****************************/
/************************ BEGIN faceDetect widget ****************************/

FaceDetectWidget::FaceDetectWidget(MainWindow *parent){
 this->parent = parent;
   
 b=new QPushButton;
 b->setText("Detect");
  connect(b, SIGNAL(clicked()), this, SLOT(updateVal()));

 QFormLayout *formLayout = new QFormLayout;
 formLayout->addRow(b);

  this->setLayout(formLayout);
  this->hide();
  }

FaceDetectWidget::~FaceDetectWidget() { }


void FaceDetectWidget::updateVal(){
  
  this->parent->mFeature->faceDetect();
//  this->parent->updateImage();

  cv::imshow("Res", this->parent->mFeature->img);

}

/***********************  END faceDetect Widget ****************************/

/************************ BEGIN featureFind widget ****************************/
/***********************  END featureFind Widget ****************************/

