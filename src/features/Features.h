#ifndef FEATURES_H_INCLUDED
#define FEATURES_H_INCLUDED



#include <stdio.h>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"

#include "opencv2/nonfree/features2d.hpp"


using namespace cv;

class Features
{
    public:
        Mat img;

        Features(String);

        virtual ~Features();


        /// detection des point d'interet avec surf / parametre 1:harris 2:sift 3:surf 4:dense /  la valeur pour la matrice hessienne
        void featureDetect(int=2,int=400);
        /// detection de visage
        void faceDetect();
        /// comaraison de de l'image en parametre avec notre image/ image a comparer / parametre 1:harris 2:sift 3:surf 4:dense /  la valeur pour la matrice hessienne/
        void featureFind(Mat,int=2,int=400);



};




#endif // FEATURES_H_INCLUDED
