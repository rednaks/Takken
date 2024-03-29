#ifndef FILTRE_H_INCLUDED
#define FILTRE_H_INCLUDED
#include<string>
using namespace std;
using namespace cv;

class Filtre{

public:
Mat &image;
Mat out;
Filtre(Mat&);
Filtre(Mat&,Mat);
Mat getImage(){return image;};
Mat getOut(){return out;};
void setImage(Mat img){image=img;};
void setOut(Mat outt){out=outt;};
void bilateralFiltre(double sigmaColor,double sigmaSpace);
void blurFiltre(Size ksize);
void medianFiltre(int noyau);
void boxFiltre(cv::Size ksize);
void gaussienFiltre(Size ksize,double sigmaX,double sigmaY);
void LaplacienFiltre(Size noyau_gaussien,int taille_noyau);
void filter2DFiltre(int kernel);
void sepFilter2DFiltre(int noyau_lignes,int noyau_colonnes);
void bruit_sel_poivre(int n);
};

#endif // FILTRE_H_INCLUDED
