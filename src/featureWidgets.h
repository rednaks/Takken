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

#ifndef FEATURE_WIDGETS_H
#define FEATURE_WIDGETS_H

#include <QtGui>
class MainWindow;

namespace feature {
  class FeatureDetectWidget: public QWidget{
    Q_OBJECT
    public:
      FeatureDetectWidget(MainWindow* =0);
      ~FeatureDetectWidget();
    private:
      QComboBox *algoComboBox;
      QSlider *precisionSlider;

      QLabel *algoLabel;
      QLabel *precisionLabel;
      MainWindow *parent;

    public slots:
      void updateVal(int);
  };

  
  class FaceDetectWidget: public QWidget{
    Q_OBJECT
    public:
      FaceDetectWidget(MainWindow* =0);
      ~FaceDetectWidget();
    private:
      QPushButton *b;
      MainWindow *parent;

      public slots:
      void updateVal();

    };


  class FeatureFindWidget: public QWidget{
    Q_OBJECT
    public:
      FeatureFindWidget(MainWindow* =0);
      ~FeatureFindWidget();
    private:
      QLabel *LoadLabel;
      QPushButton *b;
      MainWindow *parent;

      public slots:
      void updateVal();

    };

  
} // namespace feature

#endif
