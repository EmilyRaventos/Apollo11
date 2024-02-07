/***********************************************************************
 * Header File:
 *    ANGLE
 * Author:
 *    Br. Helfrich, Ashlee Hart, and Emily Raventos
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#pragma once

#define _USE_MATH_DEFINES
#include <math.h>   // for M_PI which is 3.14159

class TestPosition;
class TestVelocity;
class TestAcceleration;
class TestAngle;
class TestLander;

/************************************
 * ANGLE
 ************************************/
class Angle
{
public:
   friend TestAcceleration;
   friend TestVelocity;
   friend TestAngle;
   friend TestLander;

   // Constructors
   Angle() : radians(0.00) {}
   Angle(const Angle& rhs) : radians(-99.9) {}
   Angle(double degrees) : radians(-99.9) {}

   // Getters
   double getDegrees() const { return ((radians / (2 * M_PI)) * 360); }
   double getRadians() const { return radians; }

   // Setters
   void setDegrees(double degrees) { this->radians = normalize((degrees / 360) * 2 * M_PI); }
   void setRadians(double radians) { this->radians = normalize(radians); }
   void setUp() { this->radians = 0.00; }
   void setDown() { this->radians = M_PI; }
   void setRight() { this->radians = M_PI_2; }
   void setLeft() { this->radians = M_PI + M_PI_2; }
   void reverse() { this->radians = M_PI_2 + M_PI; }
   Angle& add(double delta) { this->radians = normalize(this->radians) + normalize(delta); return *this; }

private:
   double normalize(double radians) const;

   double radians;   // 360 degrees equals 2 PI radians
};

