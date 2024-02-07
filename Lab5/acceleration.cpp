/***********************************************************************
 * Source File:
 *    ACCELERATION
 * Author:
 *    Br. Helfrich and Emily Raventos
 * Summary:
 *    Everything we need to know about changing speed
 ************************************************************************/

#include "acceleration.h"
#include "angle.h"

#include <cmath> // for sin and cos

 /*********************************************
  * ACCELERATION : ADD
  *  a += a
  *********************************************/
void Acceleration::add(const Acceleration& acceleration)
{
   ddx += acceleration.ddx;
   ddy += acceleration.ddy;
}

/*********************************************
 * ACCELERATION : SET
 *  set from angle and direction
 *********************************************/
void Acceleration::set(const Angle& angle, double magnitude)
{
   ddx = magnitude * sin(angle.getRadians());
   ddy = magnitude * cos(angle.getRadians());
}
