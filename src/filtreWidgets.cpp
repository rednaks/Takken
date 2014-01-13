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

#include "filtreWidgets.h"
#include "mainWindow.h"

using namespace filtre;

/******************** Begin Bruitage Widget *****************************/
BruitageWidget::BruitageWidget(MainWindow* parent):AbstractWidget(parent) {

  densiteSlider = new QSlider;
  densiteSlider->setOrientation(Qt::Horizontal);
  densiteSlider->setMinimum(0);
  densiteSlider->setMaximum(50);
  connect(densiteSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

  densiteSpinBox = new QSpinBox;
  densiteSpinBox->setMinimum(0);
  densiteSpinBox->setMaximum(50);
  connect(densiteSpinBox, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

  densiteLabel = new QLabel(QString::fromUtf8("Densité :"));




  QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(densiteLabel, new QLabel(""));
  formLayout->addRow(densiteSlider, densiteSpinBox);
  formLayout->addRow(new QLabel(""), mAboutPushButton);


  mDoc = new QString(QString::fromUtf8("Le bruit impulsionnel, également appelé sel et poivre, est une dégradation de l'image sous la forme de pixels noirs et blancs répartis au hasard.Il consiste à mettre, aléatoirement, plusieurs pixels aux valeurs 255 ou 0 (valeurs extrêmes de l’intervalle des niveaux de gris). "));
  this->setLayout(formLayout);
  this->hide();

}

BruitageWidget::~BruitageWidget(){ }

void BruitageWidget::updateVal(int v){
  printf("Val : %d\n",v);
  densiteSpinBox->setValue(v);
  densiteSlider->setValue(v);
  this->parent->mFiltre->bruit_sel_poivre(v);
  this->parent->updateImage();

}


/******************** END Bruitage Widget *****************************/

/******************** BEGIN Bilateral Widget ***********************************/
BilateralWidget::BilateralWidget(MainWindow* parent):AbstractWidget(parent){
sigmaColorSlider = new QSlider;
sigmaColorSlider->setOrientation(Qt::Horizontal);
sigmaColorSlider->setMinimum(0);
sigmaColorSlider->setMaximum(200);
connect(sigmaColorSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

sigmaColorLabel = new QLabel(QString::fromUtf8("SigmaSpace :"));


sigmaSpaceSlider = new QSlider;
sigmaSpaceSlider->setOrientation(Qt::Horizontal);
sigmaSpaceSlider->setMinimum(0);
sigmaSpaceSlider->setMaximum(200);
connect(sigmaSpaceSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

sigmaSpaceLabel = new QLabel(QString::fromUtf8("SigmaColor :"));




QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(sigmaColorLabel, new QLabel(""));
  formLayout->addRow(sigmaColorSlider);
  formLayout->addRow(sigmaSpaceLabel, new QLabel(""));
  formLayout->addRow(sigmaSpaceSlider);
  formLayout->addRow(new QLabel(""), mAboutPushButton);

  mDoc = new QString(QString::fromUtf8("Le filtre bilatéral peut réduire les bruits indésirables tout en gardant les bords assez pointus contrairement au filtre gaussien. Cependant, il est très lent comparé à la plupart des filtres.On l’utilise généralement pour éviter le lissage des contours résultant de l’application de quelques filtres."));

  this->setLayout(formLayout);
  this->hide();


}

BilateralWidget::~BilateralWidget(){}

void BilateralWidget::updateVal(int v){
    printf("Val : %d\n",v);
    this->parent->mFiltre->bilateralFiltre(sigmaColorSlider->value(),sigmaSpaceSlider->value());
    this->parent->updateImage();
}


/******************** END Bilateral Widget  ***********************************/

/******************** BEGIN Blur Widget ***********************************/
BlurWidget::BlurWidget(MainWindow* parent):AbstractWidget(parent){
noyauSlider = new QSlider;
noyauSlider->setOrientation(Qt::Horizontal);
noyauSlider->setMinimum(1);
noyauSlider->setMaximum(40);
connect(noyauSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));


noyauSpinBox= new QSpinBox;
noyauSpinBox->setMinimum(1);
noyauSpinBox->setMaximum(40);
connect(noyauSpinBox, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

noyauLabel =new QLabel(QString::fromUtf8("Noyau:"));





  QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(noyauLabel, new QLabel(""));
  formLayout->addRow(noyauSlider, noyauSpinBox);
  formLayout->addRow(new QLabel(""), mAboutPushButton);

  mDoc = new QString(QString::fromUtf8("Le filtre Blur est un filtre uniforme, sa matrice n’est composée que des 1 multipliés par l’inverse du carré du noyau."));

  this->setLayout(formLayout);
  this->hide();
}

BlurWidget::~BlurWidget(){ }

void BlurWidget::updateVal(int v){
printf("Val : %d\n",v);
  noyauSpinBox->setValue(v);
  noyauSlider->setValue(v);
  this->parent->mFiltre->blurFiltre(Size(v,v));
  this->parent->updateImage();
}


/******************** END Blur Widget  ***********************************/

/******************** BEGIN Median Widget ***********************************/

MedianWidget::MedianWidget(MainWindow* parent):AbstractWidget(parent) {
noyauSlider = new QSlider;
noyauSlider->setOrientation(Qt::Horizontal);
noyauSlider->setMinimum(1);
noyauSlider->setMaximum(21);
noyauSlider->setSingleStep(2);
connect(noyauSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

noyauLabel =new QLabel(QString::fromUtf8("Noyau:"));





  QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(noyauLabel, new QLabel(""));
  formLayout->addRow(noyauSlider);
  formLayout->addRow(new QLabel(""), mAboutPushButton);


  mDoc = new QString(QString::fromUtf8("Le filtre médian est utilisé pour atténuer des pixels d'une valeur très différente de leur entourage.Il prend dans le voisinage la valeur la moins extrême. Pour cela, on crée une liste des valeurs du voisinage, puis on trie cette liste et on prend la valeur qui se trouve au milieu de la liste. Cette valeur médiane est la plus éloignée des deux extrêmes.Ce filtre est particulièrement efficace lorsqu’il s’agit d’éliminer les bruits impulsionnels"));

  this->setLayout(formLayout);
  this->hide();
}

MedianWidget::~MedianWidget(){}

void MedianWidget::updateVal(int v){
    if(noyauSlider->value() % 2==1){
printf("Val : %d\n",v);
  this->parent->mFiltre->medianFiltre( noyauSlider->value());
  this->parent->updateImage();}
  else{
this->parent->mFiltre->medianFiltre( noyauSlider->value()+1);
  this->parent->updateImage();
  }
  }


/******************** END  Median Widget  ***********************************/

/******************** BEGIN boxFiltre Widget ***********************************/
BoxFiltreWidget::BoxFiltreWidget(MainWindow* parent):AbstractWidget(parent) {
noyauSlider = new QSlider;
noyauSlider->setOrientation(Qt::Horizontal);
noyauSlider->setMinimum(1);
noyauSlider->setMaximum(40);
connect(noyauSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));


noyauSpinBox= new QSpinBox;
noyauSpinBox->setMinimum(1);
noyauSpinBox->setMaximum(40);
connect(noyauSpinBox, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

noyauLabel =new QLabel(QString::fromUtf8("Noyau:"));





  QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(noyauLabel, new QLabel(""));
  formLayout->addRow(noyauSlider, noyauSpinBox);
     formLayout->addRow(new QLabel(""), mAboutPushButton);


  mDoc = new QString(QString::fromUtf8("Le BoxFilter est  semblable au filtre Blur à un paramètre prés.Une fois le paramètre « normalize » initialisé à « true »,  le boxfilter devient identique au filtre blur. Autrement, le noyau n’a plus aucun effet, et la matrice n’est composée que des 1."));

  this->setLayout(formLayout);
  this->hide();
}

BoxFiltreWidget::~BoxFiltreWidget(){ }

void BoxFiltreWidget::updateVal(int v){
printf("Val : %d\n",v);
  noyauSpinBox->setValue(v);
  noyauSlider->setValue(v);
  this->parent->mFiltre->boxFiltre(Size(v,v));
  this->parent->updateImage();
}


/******************** END boxFiltre Widget  ***********************************/

/******************** BEGIN Gaussien Widget ***********************************/

GaussienWidget::GaussienWidget(MainWindow* parent):AbstractWidget(parent) {
noyauSlider= new QSlider;
noyauSlider->setOrientation(Qt::Horizontal);
noyauSlider->setMinimum(1);
noyauSlider->setMaximum(21);
noyauSlider->setSingleStep(2);
connect(noyauSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

noyauLabel = new QLabel (QString::fromUtf8("taille du noyau :"));

sigmaXSlider = new QSlider;
sigmaXSlider->setOrientation(Qt::Horizontal);
sigmaXSlider->setMinimum(0);
sigmaXSlider->setMaximum(10);
connect(sigmaXSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

sigmaXLabel = new QLabel(QString::fromUtf8("Deviation par rapport a x :"));


sigmaYSlider = new QSlider;
sigmaYSlider->setOrientation(Qt::Horizontal);
sigmaYSlider->setMinimum(0);
sigmaYSlider->setMaximum(10);
connect(sigmaYSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

sigmaYLabel = new QLabel(QString::fromUtf8("Deviation par rapport a y :"));




QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(noyauLabel, new QLabel(""));
  formLayout->addRow(noyauSlider);
  formLayout->addRow(sigmaXLabel, new QLabel(""));
  formLayout->addRow(sigmaXSlider);
  formLayout->addRow(sigmaYLabel, new QLabel(""));
  formLayout->addRow(sigmaYSlider);
   formLayout->addRow(new QLabel(""), mAboutPushButton);

  mDoc = new QString(QString::fromUtf8("Le filtre Gaussien est un filtre isotrope (trop lissant ne préservant pas les contours) avec des propriétés mathématiques bien précises. Les pixels prés du centre ont un effet ou un poids plus important que ceux qui sont situés plus loin. Il faut noter que plus le sigma est grand, plus la cloche Gaussienne est large et plus le flou appliqué à l'image sera marqué.Le filtre gaussien est un filtre séparable."));

  this->setLayout(formLayout);
  this->hide();


}

GaussienWidget::~GaussienWidget(){}

void GaussienWidget::updateVal(int v){
    if(noyauSlider->value() %2 ==1){
    printf("Val : %d\n",v);
    this->parent->mFiltre->gaussienFiltre(Size (noyauSlider->value(),noyauSlider->value()),sigmaXSlider->value(),sigmaYSlider->value());
    this->parent->updateImage();}
    else{
    this->parent->mFiltre->gaussienFiltre(Size (noyauSlider->value()+1,noyauSlider->value()+1),sigmaXSlider->value(),sigmaYSlider->value());
    this->parent->updateImage();}

}


/******************** END Gaussien Widget  ***********************************/

/******************** BEGIN Laplacien Widget ***********************************/
LaplacienWidget::LaplacienWidget(MainWindow* parent):AbstractWidget(parent) {
noyauGaussSlider= new QSlider;
noyauGaussSlider->setOrientation(Qt::Horizontal);
noyauGaussSlider->setMinimum(1);
noyauGaussSlider->setMaximum(41);
noyauGaussSlider->setSingleStep(2);
connect(noyauGaussSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

noyauGaussLabel = new QLabel (QString::fromUtf8("noyau gaussien :"));

noyauLaplaceSlider = new QSlider;
noyauLaplaceSlider->setOrientation(Qt::Horizontal);
noyauLaplaceSlider->setMinimum(1);
noyauLaplaceSlider->setMaximum(9);
noyauLaplaceSlider->setSingleStep(2);
connect(noyauLaplaceSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

noyauLaplaceLabel = new QLabel(QString::fromUtf8("noyau laplacien :"));



QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(noyauGaussLabel, new QLabel(""));
  formLayout->addRow(noyauGaussSlider);
  formLayout->addRow(noyauLaplaceLabel, new QLabel(""));
  formLayout->addRow(noyauLaplaceSlider);
  formLayout->addRow(new QLabel(""), mAboutPushButton);

  mDoc = new QString(QString::fromUtf8("Le filtre Laplacien est un filtre de convolution particulier utilisé pour mettre en valeur les détails qui ont une variation rapide de luminosité. Le Laplacien est donc idéal pour rendre visible les contours des objets"));

  this->setLayout(formLayout);
  this->hide();


}

LaplacienWidget::~LaplacienWidget(){}

void LaplacienWidget::updateVal(int v){
    if(noyauGaussSlider->value() %2 ==1 && noyauLaplaceSlider->value()%2==1){
    printf("Val : %d\n",v);
    this->parent->mFiltre->LaplacienFiltre(Size(noyauGaussSlider->value(),noyauGaussSlider->value()),noyauLaplaceSlider->value());
    this->parent->updateImage();}
    else if (noyauGaussSlider->value() %2 ==1 && noyauLaplaceSlider->value()%2==0){
this->parent->mFiltre->LaplacienFiltre(Size(noyauGaussSlider->value(),noyauGaussSlider->value()),noyauLaplaceSlider->value()+1);
    this->parent->updateImage();}
      else if (noyauGaussSlider->value() %2 ==0 && noyauLaplaceSlider->value()%2==1){
this->parent->mFiltre->LaplacienFiltre(Size(noyauGaussSlider->value()+1,noyauGaussSlider->value()+1),noyauLaplaceSlider->value());
    this->parent->updateImage();}
    else{
this->parent->mFiltre->LaplacienFiltre(Size(noyauGaussSlider->value()+1,noyauGaussSlider->value()+1),noyauLaplaceSlider->value()+1);
    this->parent->updateImage();}

    //cv::imshow("Res", this->parent->mFiltre->out);

}


/******************** END Laplacien Widget  ***********************************/

/******************** BEGIN Filtre2D Widget ***********************************/
Filter2DWidget::Filter2DWidget(MainWindow* parent):AbstractWidget(parent) {
noyauSlider = new QSlider;
noyauSlider->setOrientation(Qt::Horizontal);
noyauSlider->setMinimum(1);
noyauSlider->setMaximum(40);
connect(noyauSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));


noyauSpinBox= new QSpinBox;
noyauSpinBox->setMinimum(1);
noyauSpinBox->setMaximum(40);
connect(noyauSpinBox, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

noyauLabel =new QLabel(QString::fromUtf8("Noyau:"));



  QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(noyauLabel, new QLabel(""));
  formLayout->addRow(noyauSlider, noyauSpinBox);
     formLayout->addRow(new QLabel(""), mAboutPushButton);


  mDoc = new QString(QString::fromUtf8("Le Filter2D applique un filtre linéaire arbitraire à l’image. Sa fonction calcule en effet la corrélation, contrairement au reste des filtres linéaires calculant la convolution."));

  this->setLayout(formLayout);
  this->hide();
}

Filter2DWidget::~Filter2DWidget(){}

void Filter2DWidget::updateVal(int v){
printf("Val : %d\n",v);
  noyauSpinBox->setValue(v);
  noyauSlider->setValue(v);
  this->parent->mFiltre->filter2DFiltre(v);
  this->parent->updateImage();
}


/******************** END Filtre2D Widget  ***********************************/
/******************** BEGIN SepFilter Widget ***********************************/
SepFilter2DWidget::SepFilter2DWidget(MainWindow* parent):AbstractWidget(parent) {
noyauLigneSlider= new QSlider;
noyauLigneSlider->setOrientation(Qt::Horizontal);
noyauLigneSlider->setMinimum(2);
noyauLigneSlider->setMaximum(20);
connect(noyauLigneSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

noyauLigneLabel = new QLabel (QString::fromUtf8("noyau des lignes :"));

noyauColonneSlider = new QSlider;
noyauColonneSlider->setOrientation(Qt::Horizontal);
noyauColonneSlider->setMinimum(2);
noyauColonneSlider->setMaximum(20);
connect(noyauColonneSlider, SIGNAL(valueChanged(int)), this, SLOT(updateVal(int)));

noyauColonneLabel = new QLabel(QString::fromUtf8("noyau des colonnes :"));



QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(noyauLigneLabel, new QLabel(""));
  formLayout->addRow(noyauLigneSlider);
  formLayout->addRow(noyauColonneLabel, new QLabel(""));
  formLayout->addRow(noyauColonneSlider);
     formLayout->addRow(new QLabel(""), mAboutPushButton);

  mDoc = new QString(QString::fromUtf8("Ce filtre applique un filtre linéaire séparable. Il traite séparément les lignes et les colonnes. Les lignes sont filtrées par le premier noyau, le deuxième noyau  filtre des colonnes.Ce qui diminue largement le nombre d’opérations et donc le temps d’exécution."));

  this->setLayout(formLayout);
  this->hide();

}

SepFilter2DWidget::~SepFilter2DWidget(){}

void SepFilter2DWidget::updateVal(int v){
    printf("Val : %d\n",v);
    this->parent->mFiltre->sepFilter2DFiltre(noyauLigneSlider->value(),noyauColonneSlider->value());
   this->parent->updateImage();
}


/******************** END SepFilter Widget  ***********************************/

