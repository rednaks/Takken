#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
//#include <opencv2/core/cxcore.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "filtre.h"
using namespace std;
using namespace cv;


Filtre::Filtre(){

}

Filtre::Filtre(Mat img,Mat outt){
image=img;
out=outt;
}

void Filtre::bilateralFiltre(int diametre, double sigmaColor,double sigmaSpace){

  bilateralFilter(image,out,diametre,sigmaColor,sigmaSpace);
  image = out;
}

void Filtre::blurFiltre(Size ksize){

  blur(image,out,ksize,Point(-1, -1));
  image=out;
}

void Filtre::boxFiltre(cv::Size ksize){

    boxFilter(image,out,-1,ksize,Point(-1, -1),true);
    image=out;
}

void Filtre::medianFiltre(int noyau){

    medianBlur(image,out,noyau);
    image=out;

}

void Filtre::gaussienFiltre(Size ksize,double sigmaX,double sigmaY){
    GaussianBlur(image,out,ksize,sigmaX,sigmaY);
    image=out;
}

void Filtre::sepFilter2DFiltre(int noyau_lignes,int noyau_colonnes){
    sepFilter2D(image,out,-1,noyau_lignes,noyau_colonnes,Point(-1,-1), 0);
    image=out;
}

void Filtre::filter2DFiltre(int kernel){
filter2D(image, out, -1, kernel, Point(-1,-1), 0, BORDER_DEFAULT );
image=out;
}

void Filtre::LaplacienFiltre(Size noyau_gaussien,int taille_noyau){
    Mat out2,out1,out3;
GaussianBlur(image,out1,noyau_gaussien,0,0,BORDER_DEFAULT);
cvtColor(out1,out2,CV_RGB2GRAY);
Laplacian(out2,out3,-1,taille_noyau,1,0,BORDER_DEFAULT);
convertScaleAbs(out3,out);
image=out;
}

void Filtre::bruit_sel_poivre(int n){

out = image;
int x,y;
IplImage ima=image.clone();
int m=n*1000;
IplImage *img=&ima;

CvScalar pixelb,pixeln;

pixelb.val[0]=255;
pixelb.val[1]=255;
pixelb.val[2]=255;

pixeln.val[1]=0;
pixeln.val[2]=0;
pixeln.val[0]=0;

for(int k=0;k<m;k++){
x=rand()%img->height;
y=rand()%img->width;

cvSet2D(img,x,y,pixelb);
}

for(int k=0;k<m;k++){
x=rand()%img->height;
y=rand()%img->width;

cvSet2D(img,x,y,pixeln);
}
out=img;
}

