/***********************************************************************
 * Source File:
 *    ANGLE
 * Author:
 *    Br. Helfrich and Ashlee Hart
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#include "angle.h"
#include <math.h>  // for floor()
#include <cassert>
using namespace std;

/************************************
 * ANGLE : NORMALIZE
 * Author: Ashlee Hart
 ************************************/
double Angle::normalize(double radians) const
{
   // Updated the if statements to follow Bro. H's solution
   if (radians >= (M_PI * 2.0))
   {
      double multiples = floor(radians / (M_PI * 2.0));

      return radians - ((M_PI * 2.0) * multiples);
   }

   else if (radians < 0.0)
   {
      double multiples = ceil(-radians / (M_PI * 2.0));
      return (M_PI * 2.0) * multiples + radians;
   }

   return radians;
}


