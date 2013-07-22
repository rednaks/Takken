#include "Features.h"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"


#include "opencv2/highgui/highgui_c.h"
#include "opencv2/nonfree/features2d.hpp"
#include "opencv2/calib3d/calib3d.hpp"

#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;


void Features::featureDetect(int alg,int mhess){
///-- Step 1: Detect the keypoints using SURF Detector

  int minHessian = mhess;
  FeatureDetector *detector;


 switch (alg){
   case 1 :

         detector=new GoodFeaturesToTrackDetector( minHessian );
        break;


   case 2 :

        detector=new SiftFeatureDetector( minHessian );
        break;
   case 3 :
        detector=new SurfFeatureDetector( minHessian );
        break;
     case 4 :
          detector=new DenseFeatureDetector( minHessian );
        break;

 }



  std::vector<KeyPoint> keypoints;

 detector->detect( img, keypoints );


  ///-- Draw keypoints
  Mat img_keypoints;

  drawKeypoints( img, keypoints, img, Scalar::all(-1), DrawMatchesFlags::DEFAULT );


  //-- Show detected (drawn) keypoints



}


string face_cascade_name = "haarcascade_frontalface_alt.xml";
string eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";
CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;
string window_name = "Capture - Face detection";
RNG rng(12345);

void detectAndDisplay( Mat frame )
{
   std::vector<Rect> faces;
   Mat frame_gray;

   cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
   equalizeHist( frame_gray, frame_gray );
   //-- Detect faces
   face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30) );

   for( size_t i = 0; i < faces.size(); i++ )
    {
      Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
      ellipse( frame, center, Size( faces[i].width/2, faces[i].height/2), 0, 0, 360, Scalar( 255, 0, 255 ), 2, 8, 0 );

      Mat faceROI = frame_gray( faces[i] );
      std::vector<Rect> eyes;

      //-- In each face, detect eyes
      eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CASCADE_SCALE_IMAGE, Size(30, 30) );

      for( size_t j = 0; j < eyes.size(); j++ )
       {
         Point eye_center( faces[i].x + eyes[j].x + eyes[j].width/2, faces[i].y + eyes[j].y + eyes[j].height/2 );
         int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
         circle( frame, eye_center, radius, Scalar( 255, 0, 0 ), 3, 8, 0 );
       }
    }
   //-- Show what you got



}


void Features::faceDetect(){




  if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading\n");  };
  if( !eyes_cascade.load( eyes_cascade_name ) ){ printf("--(!)Error loading\n");  };
  detectAndDisplay( img );


}




void Features::featureFind(Mat img2,int alg,int mhess){


  Mat img_object = img2;
  Mat img_scene = img;



  //-- Step 1: Detect the keypoints using SURF Detector
 int minHessian = mhess;
  FeatureDetector *detector;


 switch (alg){
   case 1 :

         detector=new GoodFeaturesToTrackDetector( minHessian );
        break;


   case 2 :

        detector=new SiftFeatureDetector( minHessian );
        break;
   case 3 :
        detector=new SurfFeatureDetector( minHessian );
        break;
     case 4 :
          detector=new DenseFeatureDetector( minHessian );
        break;

 }

  std::vector<KeyPoint> keypoints_object, keypoints_scene;

  detector->detect( img_object, keypoints_object );
  detector->detect( img_scene, keypoints_scene );

  //-- Step 2: Calculate descriptors (Featuresure vectors)
  SurfDescriptorExtractor extractor;

  Mat descriptors_object, descriptors_scene;

  extractor.compute( img_object, keypoints_object, descriptors_object );
  extractor.compute( img_scene, keypoints_scene, descriptors_scene );

  //-- Step 3: Matching descriptor vectors using FLANN matcher
  FlannBasedMatcher matcher;
  std::vector< DMatch > matches;
  matcher.match( descriptors_object, descriptors_scene, matches );

  double max_dist = 0; double min_dist = 100;

  //-- Quick calculation of max and min distances between keypoints
  for( int i = 0; i < descriptors_object.rows; i++ )
  { double dist = matches[i].distance;
    if( dist < min_dist ) min_dist = dist;
    if( dist > max_dist ) max_dist = dist;
  }

  printf("-- Max dist : %f \n", max_dist );
  printf("-- Min dist : %f \n", min_dist );

  //-- Draw only "good" matches (i.e. whose distance is less than 3*min_dist )
  std::vector< DMatch > good_matches;

  for( int i = 0; i < descriptors_object.rows; i++ )
  { if( matches[i].distance < 3*min_dist )
     { good_matches.push_back( matches[i]); }
  }

  Mat img_matches;
  drawMatches( img_object, keypoints_object, img_scene, keypoints_scene,
               good_matches, img_matches, Scalar::all(-1), Scalar::all(-1),
               vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS );

  //-- Localize the object
  std::vector<Point2f> obj;
  std::vector<Point2f> scene;

  for( int i = 0; i < good_matches.size(); i++ )
  {
    //-- Get the keypoints from the good matches
    obj.push_back( keypoints_object[ good_matches[i].queryIdx ].pt );
    scene.push_back( keypoints_scene[ good_matches[i].trainIdx ].pt );
  }

  Mat H = findHomography( obj, scene, CV_RANSAC );

  //-- Get the corners from the image_1 ( the object to be "detected" )
  std::vector<Point2f> obj_corners(4);
  obj_corners[0] = cvPoint(0,0); obj_corners[1] = cvPoint( img_object.cols, 0 );
  obj_corners[2] = cvPoint( img_object.cols, img_object.rows ); obj_corners[3] = cvPoint( 0, img_object.rows );
  std::vector<Point2f> scene_corners(4);

  perspectiveTransform( obj_corners, scene_corners, H);

  //-- Draw lines between the corners (the mapped object in the scene - image_2 )
  line( img_matches, scene_corners[0] + Point2f( img_object.cols, 0), scene_corners[1] + Point2f( img_object.cols, 0), Scalar(0, 255, 0), 4 );
  line( img_matches, scene_corners[1] + Point2f( img_object.cols, 0), scene_corners[2] + Point2f( img_object.cols, 0), Scalar( 0, 255, 0), 4 );
  line( img_matches, scene_corners[2] + Point2f( img_object.cols, 0), scene_corners[3] + Point2f( img_object.cols, 0), Scalar( 0, 255, 0), 4 );
  line( img_matches, scene_corners[3] + Point2f( img_object.cols, 0), scene_corners[0] + Point2f( img_object.cols, 0), Scalar( 0, 255, 0), 4 );


  img=img_matches;

}






Features::Features(String img)
{
    this->img=imread(img);
}

Features::~Features()
{
    //dtor
}
