#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
//#include "highgui.h"
#include <stdlib.h>
#include <stdio.h>
#ifndef DEF_MORPHOLOGIE
#define DEF_MORPHOLOGIE

using namespace std;
using namespace cv;
class   Morphologie{

    public:
    Morphologie();
    void Erosion(int , int);
    void Dilatation(int , int);



    public:
Mat src;
int erosion_elem ;
int erosion_size ;
int dilation_elem ;
int dilation_size ;
int  max_elem ;
int  max_kernel_size ;


};
#endif

