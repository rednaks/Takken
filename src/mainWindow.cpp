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


MainWindow::MainWindow(){

  // Création de la barre de menu
  menuBar = new QMenuBar(this);
  
  // Ajout des menu
  fileMenu = menuBar->addMenu(tr("&File"));
  editMenu = menuBar->addMenu(tr("&Edit"));
  filtresMenu = menuBar->addMenu(tr("&Filtres"));
  caracterisationMenu = menuBar->addMenu(tr("&Caractérisation"));
  morphMathMenu = menuBar->addMenu(tr("&Morph. Mathématique"));
  segMenu = menuBar->addMenu(tr("&Segmentation"));
  helpMenu = menuBar->addMenu(tr("&Help"));


  //Ajout des actions du menu File
  openFileAction = fileMenu->addAction("Ouvrir");
  saveFileAction = fileMenu->addAction("Save");
  saveAsFileAction = fileMenu->addAction("Save As");
  quitFileAction = fileMenu->addAction("Quit");

  //Ajout des action du menu Filtres
  gaussienFiltreAction = filtresMenu->addAction("Gaussien");
  medianFiltreAction = filtresMenu->addAction("Median");
  blurFiltreAction = filtresMenu->addAction("Blur");
  boxFiltreAction = filtresMenu->addAction("Box");
  sep2DFiltreAction = filtresMenu->addAction("Sep 2D");
  laplacienFiltreAction = filtresMenu->addAction("Laplacien");
  filtre2DFiltreAction = filtresMenu->addAction("Filtre 2D");
  bilateralFiltreAction = filtresMenu->addAction("Bilateral");

  //Ajout des action du menu Morphologie Mathématique 
  erosionMorphAction = morphMathMenu->addAction("Erosion");
  dilatationMorphAction = morphMathMenu->addAction("Dilatation");
  ouvertureMorphAction = morphMathMenu->addAction("Ouverture");
  fermetureMorphAction = morphMathMenu->addAction("Fermeture");

  //Ajout des action du menu Segmentation
  splitAndMergeSegAction = segMenu->addAction("Split And Merge");
  growinRegionSegAction = segMenu->addAction("Growing Region");
  thresholdingSegAction = segMenu->addAction("Thresholding");

  //Ajout des action du menu Help
  aboutHelpAction = helpMenu->addAction("About");

  //Assicier la barre de menu à la fenetre
  setMenuBar(menuBar);
  this->resize(800, 600);
}

MainWindow::~MainWindow(){ 
  delete menuBar;

}
