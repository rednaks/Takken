

#include "Morphologie.h"



void Morphologie::Erosion(int erosion_elem, int erosion_size)
{
  int erosion_type;
  if( erosion_elem == 0 ){ erosion_type = MORPH_RECT; }
  else if( erosion_elem == 1 ){ erosion_type = MORPH_CROSS; }
  else if( erosion_elem == 2) { erosion_type = MORPH_ELLIPSE; }

  Mat element = getStructuringElement( erosion_type,
                                       Size( 2*erosion_size + 1, 2*erosion_size+1 ),
                                       Point( erosion_size, erosion_size ) );

  /// Apply the erosion operation
  dilate( src, dst, element );



}




void Morphologie::Dilatation(int dilation_elem, int dilation_size)
{
      int dilation_type;
  if( dilation_elem == 0 ){ dilation_type = MORPH_RECT; }
  else if( dilation_elem == 1 ){ dilation_type = MORPH_CROSS; }
  else if( dilation_elem == 2) { dilation_type = MORPH_ELLIPSE; }

  Mat element = getStructuringElement( dilation_type,
                                       Size( 2*dilation_size + 1, 2*dilation_size+1 ),
                                       Point( dilation_size, dilation_size ) );
  /// Apply the dilation operation

   erode( src, dst, element );

}


void Morphologie::Ouverture(int morph_elem, int morph_size)
{
      int morph_type;
  if( morph_elem == 0 ){ morph_type = MORPH_RECT; }
  else if( morph_elem == 1 ){ morph_type = MORPH_CROSS; }
  else if( morph_elem == 2) { morph_type = MORPH_ELLIPSE; }

  Mat element = getStructuringElement( morph_elem, Size( 2*morph_size + 1, 2*morph_size+1 ), Point( morph_size, morph_size ) );
  /// Apply the opening operation

   erode( src,dst,element );

   dilate(src,dst,element);

}

void Morphologie::Fermeture(int morph_elem, int morph_size)
{
       int morph_type;
  if( morph_elem == 0 ){ morph_type = MORPH_RECT; }
  else if( morph_elem == 1 ){ morph_type = MORPH_CROSS; }
  else if( morph_elem == 2) { morph_type = MORPH_ELLIPSE; }

  Mat element = getStructuringElement( morph_elem, Size( 2*morph_size + 1, 2*morph_size+1 ), Point( morph_size, morph_size ) );
  /// Apply the opening operation

   dilate(src,dst,element);
   erode( src,dst,element );



}

void Morphologie::GradientMorph(int morph_elem, int morph_size)
{

      int morph_type;
  if( morph_elem == 0 ){ morph_type = MORPH_RECT; }
  else if( morph_elem == 1 ){ morph_type = MORPH_CROSS; }
  else if( morph_elem == 2) { morph_type = MORPH_ELLIPSE; }

   int operation = morph_operator + 4;

  Mat element = getStructuringElement( morph_elem, Size( 2*morph_size + 1, 2*morph_size+1 ), Point( morph_size, morph_size ) );



morphologyEx( src, dst, operation, element );
}



Morphologie::Morphologie()
{
erosion_elem=0 ;
erosion_size=0;
dilation_elem=0 ;
dilation_size=0 ;
morph_elem=0;
morph_size=0;
morph_operator =0;
max_elem=0;
max_kernel_size=0 ;


}

