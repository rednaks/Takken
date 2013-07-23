#ifndef FEATURES_H_INCLUDED
#define FEATURES_H_INCLUDED



#include <stdio.h>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <opencv2/objdetect/objdetect.hpp>

#include <opencv2/imgproc/imgproc.hpp>


#include <opencv2/highgui/highgui_c.h>
#include <opencv2/nonfree/features2d.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <iostream>
#include <stdio.h>




using namespace cv;

class Features
{
    public:
        Mat img;
        Mat out;
        Features();

        virtual ~Features();


        /// detection des point d'interet avec surf / parametre 0:harris 1:sift 2:surf  /  la valeur pour la matrice hessienne avec surf ou la valeu de maxcorner avec harris
        void featureDetect(int=2,int=400);
        /// detection de visage
        void faceDetect();
        /// comaraison de de l'image en parametre avec notre image/ image a comparer / parametre 1:harris 2:sift 3:surf  /  la valeur pour la matrice hessienne/
        void featureFind(Mat,int=2,int=400);



};




#endif // FEATURES_H_INCLUDED
