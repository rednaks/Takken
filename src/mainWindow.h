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

#define BRUIT_WIDGET            0x01
#define GAUSSIEN_WIDGET         0x02
#define MEDIAN_WIDGET           0x03
#define BLUR_WIDGET             0x04
#define BOX_WIDGET              0x05
#define SEP_2D_WIDGET           0x06
#define LAPLACIEN_WIDGET        0x07
#define FILTRE_2D_WIDGET        0x08
#define BILATERAL_WIDGET        0x09
#define FEATURE_DETECT_WIDGET   0x0A
#define FACE_DETECT_WIDGET      0x0B
#define FEATURE_FIND_WIDGET     0x0C
#define EROSION_WIDGET          0x0D
#define DILATATION_WIDGET       0x10
#define OUVERTURE_WIDGET        0x11
#define FERMETURE_WIDGET        0x12
#define GRADIENT_WIDGET         0x13
#define SPLIT_AND_MERGE_WIDGET  0x14
#define GROWING_REGION_WIDGET   0x15
#define THRESHOLDING_WIDGET     0x16

#include <QtGui>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>
#include "graphicScene.h"
#include "filtre.h"
#include "filtreWidgets.h"
#include "morphologieWidgets.h"
#include "Morphologie.h"
#include "segmentationWidgets.h"
#include "segmentation.h"
#include "Features.h"
#include "featureWidgets.h"

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
    QAction *bruitFiltreAction;
    QAction *gaussienFiltreAction;
    QAction *medianFiltreAction;
    QAction *blurFiltreAction;
    QAction *boxFiltreAction;
    QAction *sep2DFiltreAction;
    QAction *laplacienFiltreAction;
    QAction *filtre2DFiltreAction;
    QAction *bilateralFiltreAction;

    //Les actions pour le menu "Caractérisation"
    QAction *featureDetectAction;
    QAction *faceDetectAction;
    QAction *featureFindAction;

    //Les actions pour le menu "Morphologie mathématique"
    QAction *erosionMorphAction;
    QAction *dilatationMorphAction;
    QAction *ouvertureMorphAction;
    QAction *fermetureMorphAction;
    QAction *gradientMorphAction;

    //Les actions pour le menu "Segmentation"
    QAction *splitAndMergeSegAction;
    QAction *growinRegionSegAction;
    QAction *thresholdingSegAction;

    //Les actions pour le menu "Help"
    QAction *aboutHelpAction;

    QSplitter *splitter;

    cv::Mat src;
    GraphicScene *mImageScene; //Image Container
    unsigned int currentWidget;


public:
    Filtre *mFiltre;
    filtre::BruitageWidget *bruitWidget;
    filtre::GaussienWidget *gaussienWidget;
    filtre::MedianWidget *medianWidget;
    filtre::BlurWidget *blurWidget;
    filtre::BoxFiltreWidget *boxFiltreWidget;
    filtre::SepFilter2DWidget *sepFilter2DWidget;
    filtre::LaplacienWidget *laplacientWidget;
    filtre::Filter2DWidget *filtre2DWidget;
    filtre::BilateralWidget *bilateralWidget;


    Features *mFeature;
    feature::FeatureDetectWidget *featureDetectWidget;
    feature::FaceDetectWidget *faceDetectWidget;
    feature::FeatureFindWidget *featureFindWidget;

    Morphologie *m;
    morphologie::ErosionWidget *erosionWidget;
    morphologie::DilatationWidget *dilatationWidget;
    morphologie::OuvertureWidget *ouvertureWidget;
    morphologie::FermetureWidget *fermetureWidget;
    morphologie::GradientWidget *gradientWidget;

    Segmentation *mSegmentation;
    segmentation::ThresholdingWidget *thresholdingWidget;



private:
    QImage const Mat2QImage(const cv::Mat&);
    void loadWidget(int);
    bool checkImageLoaded();
    void hideAllSideBarWidgets();
    std::vector<QWidget *> sideBarWidgets;
    
public:
    void updateImage();
    void setSplashText(const QString&);
    void showSplash();
    void hideSplash();
    bool splashIsVisible();

public slots:
    void openImage();

    //Slits pour les filtres
    void bruitClicked();
    void gaussienClicked();
    void medianClicked();
    void blurClicked();
    void boxClicked();
    void sep2DClicked();
    void laplacienClicked();
    void filtre2DClicked();
    void bilateralClicked();

    //Slots pour la caractérisation
    void featureDetectClicked();
    void faceDetectClicked();
    void featureFindClicked();
    //Slots pour la morphologie
    void erosionClicked();
    void dilatationClicked();
    void ouvertureClicked();
    void fermetureClicked();
    void gradientClicked();

    //Slots pour la segmentation
    void thresholdingClicked();

};

#endif
