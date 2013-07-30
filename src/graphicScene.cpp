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

#include "graphicScene.h"
#include <cstdio>

GraphicScene::GraphicScene(){
  mScene = new QGraphicsScene;
  this->setScene(mScene);
  mSplash = new SplashItem;
  mSplashVisible = false;
  connect(this->horizontalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(scrollMoved(int)));
  connect(this->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(scrollMoved(int)));
}

GraphicScene::~GraphicScene(){ 
  delete mScene;
}

void GraphicScene::setImage(const QImage &aImage){
  mScene->clear();
  mScene->addPixmap(QPixmap::fromImage(aImage));
  mScene->setSceneRect(aImage.rect());
}

void GraphicScene::setSplashText(const QString &aString){
  mSplash->setText(aString);
}

void GraphicScene::showSplash(){
  if(!mSplashVisible){
    mSplash->setCenter(getVisibleScene().center());
    mScene->addItem(mSplash);
  }
  mSplashVisible = true;
}

void GraphicScene::hideSplash(){
  if(mSplashVisible)
    mScene->removeItem(mSplash);
  mSplashVisible = false;
}

bool GraphicScene::splashIsVisible(){
  return mSplashVisible;
}

QRectF GraphicScene::getVisibleScene(){
  QRect viewport_rect(0,0, viewport()->width(), viewport()->height());
  QRectF visible_scene = mapToScene(viewport_rect).boundingRect();

  return visible_scene;
}

void GraphicScene::scrollMoved(int aValue){
  if(mSplashVisible){
    this->hideSplash();
    this->showSplash();
    update();
  }

}
