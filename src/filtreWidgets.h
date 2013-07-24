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

#ifndef FILTRE_WIDGETS_H
#define FILTRE_WIDGETS_H

#include <QtGui>

class MainWindow;

namespace filtre {

/******************** SEL_POIVRE Widget  ***********************************/

    class BruitageWidget: public QWidget {
      Q_OBJECT

      public:
        BruitageWidget(MainWindow * =0);
        ~BruitageWidget();

      public slots:
          void updateVal(int);
      private:
        QSlider *densiteSlider;
        QSpinBox *densiteSpinBox;
        QLabel *densiteLabel;
        MainWindow *parent;

    };
/************************************************************************/
/******************** Bilateral Widget  ***********************************/
    class  BilateralWidget :public QWidget{
    Q_OBJECT


        public:
            BilateralWidget(MainWindow * =0);
            ~BilateralWidget();

        public slots:
            void updateVal(int);
        private:
            QSlider *diametreSlider;
            QLabel *diametreLabel;
            QSlider *sigmaColorSlider;
            QLabel *sigmaColorLabel;
            QSlider *sigmaSpaceSlider;
            QLabel *sigmaSpaceLabel;
            MainWindow *parent;
    };
/************************************************************************/
/******************** Blur Widget  ***********************************/
  class BlurWidget:public QWidget {
  Q_OBJECT

 public:
    BlurWidget(MainWindow * =0);
    ~BlurWidget();

 public slots:
    void updateVal(int);
 private:
        QSlider *noyauSlider;
        QSpinBox *noyauSpinBox;
        QLabel *noyauLabel;
        MainWindow *parent;
  };

/************************************************************************/
/******************** BoxFilter Widget  ***********************************/

   class BoxFiltreWidget:public QWidget {
  Q_OBJECT

 public:
    BoxFiltreWidget(MainWindow * =0);
    ~BoxFiltreWidget();

 public slots:
    void updateVal(int);
 private:
        QSlider *noyauSlider;
        QSpinBox *noyauSpinBox;
        QLabel *noyauLabel;
        MainWindow *parent;
  };

/************************************************************************/
/******************** Filter2D Widget  ***********************************/

   class Filter2DWidget:public QWidget {
  Q_OBJECT

 public:
    Filter2DWidget(MainWindow * =0);
    ~Filter2DWidget();

 public slots:
    void updateVal(int);
 private:
        QSlider *noyauSlider;
        QSpinBox *noyauSpinBox;
        QLabel *noyauLabel;
        MainWindow *parent;
  };
/************************************************************************/
/******************** sepFilter2D Widget  ***********************************/
 class  SepFilter2DWidget :public QWidget{
    Q_OBJECT


        public:
            SepFilter2DWidget(MainWindow * =0);
            ~SepFilter2DWidget();

        public slots:
            void updateVal(int);
        private:
            QSlider *noyauLigneSlider;
            QLabel *noyauLigneLabel;
            QSlider *noyauColonneSlider;
            QLabel *noyauColonneLabel;
            MainWindow *parent;
    };
/************************************************************************/

/******************** Median Widget  ***********************************/
class MedianWidget:public QWidget {
  Q_OBJECT

 public:
    MedianWidget(MainWindow * =0);
    ~MedianWidget();

 public slots:
    void updateVal(int);
 private:
        QSlider *noyauSlider;
        QLabel *noyauLabel;
        MainWindow *parent;
  };
/************************************************************************/
/******************** Gaussien Widget  ***********************************/
 class  GaussienWidget :public QWidget{
    Q_OBJECT


        public:
            GaussienWidget(MainWindow * =0);
            ~GaussienWidget();

        public slots:
            void updateVal(int);
        private:
            QSlider *noyauSlider;
            QLabel *noyauLabel;
            QSlider *sigmaXSlider;
            QLabel *sigmaXLabel;
            QSlider *sigmaYSlider;
            QLabel *sigmaYLabel;
            MainWindow *parent;
    };
/************************************************************************/

/******************** Laplacien Widget  ***********************************/
 class  LaplacienWidget :public QWidget{
    Q_OBJECT


        public:
            LaplacienWidget(MainWindow * =0);
            ~LaplacienWidget();

        public slots:
            void updateVal(int);
        private:
            QSlider *noyauGaussSlider;
            QLabel *noyauGaussLabel;
            QSlider *noyauLaplaceSlider;
            QLabel *noyauLaplaceLabel;
            MainWindow *parent;
    };
/************************************************************************/
} // end namespace filtre

#endif
