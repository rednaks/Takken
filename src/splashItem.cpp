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
#include "splashItem.h"

#include <QtGui>
#include <cstdio>

SplashItem::SplashItem(){

  text = new QString;
  mCenter = QPointF(QRectF(0, 0, 400, 370).center());
}

SplashItem::~SplashItem(){ }

QRectF SplashItem::boundingRect() const
{
  return QRectF(mCenter.x()-200, mCenter.y()-150, 400, 340);
}

void SplashItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

  painter->setPen(QPen(Qt::black,2));
  painter->setBrush(QColor(245, 245, 255, 200));
  QRectF splashRect = boundingRect();
  painter->drawRoundRect(splashRect, 0, 0);

  int flags = Qt::AlignTop | Qt::AlignLeft | Qt::TextWordWrap;
  QRectF textRect = splashRect.adjusted(10, 10, -10, -10);
  QFont font;
  font.setPixelSize(18);
  painter->setPen(Qt::black);
  painter->setFont(font);
  painter->drawText(textRect, flags, *text);
}

void SplashItem::setText(const QString &aString)
{
  *text = aString;
}

void SplashItem::setCenter(const QPointF &aCenter){
  mCenter = aCenter;
}
