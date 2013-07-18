#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
//#include <opencv2/core/cxcore.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "filtre.h"
using namespace std;
using namespace cv;

filtre::filtre(Mat img,Mat outt){
image=img;
out=outt;
}

void filtre::bilateralFiltre(int diametre, double sigmaColor,double sigmaSpace){

  bilateralFilter(image,out,diametre,sigmaColor,sigmaSpace);
  image = out;
}

void filtre::blurFiltre(Size ksize){

  blur(image,image,ksize,Point(-1, -1));

}

void filtre::boxFiltre(cv::Size ksize){

    boxFilter(image,image,-1,ksize,Point(-1, -1),true);
}

void filtre::medianFiltre(int noyau){

    medianBlur(image,image,noyau);

}

void filtre::gaussienFiltre(Size ksize,double sigmaX,double sigmaY){
    GaussianBlur(image,image,ksize,sigmaX,sigmaY);
}

void filtre::sepFilter2DFiltre(int noyau_lignes,int noyau_colonnes){
    sepFilter2D(image,image,-1,noyau_lignes,noyau_colonnes,Point(-1,-1), 0);
}

void filtre::filter2DFiltre(int kernel){
filter2D(image, image, -1, kernel, Point(-1,-1), 0, BORDER_DEFAULT );
}

void filtre::LaplacienFiltre(Size noyau_gaussien,int taille_noyau){
GaussianBlur(image,image,noyau_gaussien,0,0,BORDER_DEFAULT);
cvtColor(image,image,CV_RGB2GRAY);
Laplacian(image,image,-1,taille_noyau,1,0,BORDER_DEFAULT);
convertScaleAbs(image,image);
}

void filtre::buit_sel_poivre(int n){

int x,y;
IplImage ima=image;
IplImage *img=&ima;

CvScalar pixelb,pixeln;

pixelb.val[0]=255;
pixelb.val[1]=255;
pixelb.val[2]=255;

pixeln.val[1]=0;
pixeln.val[2]=0;
pixeln.val[0]=0;

for(int k=0;k<n;k++){
x=rand()%img->height;
y=rand()%img->width;

cvSet2D(img,y,x,pixelb);
}

for(int k=0;k<n;k++){
x=rand()%img->height;
y=rand()%img->width;

cvSet2D(img,y,x,pixeln);
}
image=img;
}

