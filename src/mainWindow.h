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


#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H
#include <QtGui>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "morphologieWidgets.h"
#include "Morphologie.h"

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private:
    //La barre de menu
    QMenuBar *menuBar;

    //Les menus
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *filtresMenu;
    QMenu *caracterisationMenu; // Menu Descripteurs de formes
    QMenu *morphMathMenu;
    QMenu *segMenu;
    QMenu *helpMenu;

    //Les actions pour le menu "File"
    QAction *openFileAction;
    QAction *saveFileAction;
    QAction *saveAsFileAction;
    QAction *quitFileAction;

    //Les actions pour le menu "Edit"
    //Les actions pour le menu "Filtres"
    QAction *gaussienFiltreAction;
    QAction *medianFiltreAction;
    QAction *blurFiltreAction;
    QAction *boxFiltreAction;
    QAction *sep2DFiltreAction;
    QAction *laplacienFiltreAction;
    QAction *filtre2DFiltreAction;
    QAction *bilateralFiltreAction;

    //Les actions pour le menu "Caractérisation"
    //Les actions pour le menu "Morphologie mathématique"
    QAction *erosionMorphAction;
    QAction *dilatationMorphAction;
    QAction *ouvertureMorphAction;
    QAction *fermetureMorphAction;

    //Les actions pour le menu "Segmentation"
    QAction *splitAndMergeSegAction;
    QAction *growinRegionSegAction;
    QAction *thresholdingSegAction;

    //Les actions pour le menu "Help"
    QAction *aboutHelpAction;

    QSplitter *splitter;

    QLabel *imageDispLabel; // Image container


public:
    Morphologie *m;



private:
    QImage const Mat2QImage(const cv::Mat&);
    
public:
    void updateImage();

};

#endif
