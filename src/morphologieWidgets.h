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
#ifndef MORPHOLOGIE_WIDGETS_H
#define MORPHOLOGIE_WIDGETS_H

#include "abstractWidget.h"
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>


class MainWindow;

namespace morphologie {

  class ErosionWidget: public AbstractWidget {
    Q_OBJECT

    public:
      ErosionWidget(MainWindow * = 0);
      ~ErosionWidget();

    public slots:
      void updateVal(int);

    private:
      QComboBox *elemComboBox;
      QLabel *elemLabel;
      QSlider *sizeSlider;
      QLabel *sizeLabel;

  };

  class DilatationWidget: public AbstractWidget {
    Q_OBJECT

    public:
      DilatationWidget(MainWindow * = 0);
      ~DilatationWidget();

    public slots:
      void updateVal(int);

    private:
      QComboBox *elemComboBox;
      QLabel *elemLabel;
      QSlider *sizeSlider;
      QLabel *sizeLabel;

  };

  class OuvertureWidget: public AbstractWidget {
    Q_OBJECT

    public:
      OuvertureWidget(MainWindow * = 0);
      ~OuvertureWidget();

    public slots:
      void updateVal(int);

    private:
      QComboBox *elemComboBox;
      QLabel *elemLabel;
      QSlider *sizeSlider;
      QLabel *sizeLabel;

  };

  class FermetureWidget: public AbstractWidget {
    Q_OBJECT

    public:
      FermetureWidget(MainWindow * = 0);
      ~FermetureWidget();

    public slots:
      void updateVal(int);

    private:
      QComboBox *elemComboBox;
      QLabel *elemLabel;
      QSlider *sizeSlider;
      QLabel *sizeLabel;

  };

   class GradientWidget: public AbstractWidget {
    Q_OBJECT

    public:
      GradientWidget(MainWindow * = 0);
      ~GradientWidget();

    public slots:
      void updateVal(int);

    private:
      QComboBox *elemComboBox;
      QLabel *elemLabel;
      QSlider *sizeSlider;
      QLabel *sizeLabel;

  };

}// namespace segmentation

#endif
