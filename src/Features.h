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
#if CV_MAJOR_VERSION == 2
  #if CV_MINOR_VERSION > 3
    #include <opencv2/nonfree/features2d.hpp>
  #endif
#endif
#include <opencv2/calib3d/calib3d.hpp>
#include <iostream>
#include <stdio.h>




using namespace cv;

class Features
{
    public:
        Mat &img;
        Mat out;
        Features(Mat &);

        virtual ~Features();


        /// detection des point d'interet avec surf / parametre 0:harris 1:sift 2:surf  /  la valeur pour la matrice hessienne avec surf ou la valeu de maxcorner avec harris
        void featureDetect(int=2,int=400);
        /// detection de visage
        void faceDetect();
        /// comaraison de de l'image en parametre avec notre image/ image a comparer / parametre 1:harris 2:sift 3:surf  /  la valeur pour la matrice hessienne/
        void featureFind(Mat,int=2,int=400);



};




#endif // FEATURES_H_INCLUDED
