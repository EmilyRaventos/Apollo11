/*************************************************************
 * 1. Name:
 *      -Emily Raventos and Ashlee Hart-
 * 2. Assignment Name:
 *      Practice 02: Physics simulator
 * 3. Assignment Description:
 *      Compute how the Apollo lander will move across the screen
 * 4. What was the hardest part? Be as specific as possible.
 *      - Writing the individual functions went pretty smoothly. We just had a hard time
 *      figuring out how to use those formulas to change the displayed results.-
 * 5. How long did it take for you to complete the assignment?
 *      -3 hours
 **************************************************************/

#include <iostream>  // for CIN and COUT
#include <string>
#include <cassert>
#include <cmath> // for sqrt, pow, sin, and cos

using namespace std;

#define WEIGHT   15103.000   // Weight in KG
#define GRAVITY     -1.625   // Vertical acceleration due to gravity, in m/s^2
#define THRUST   45000.000   // Thrust of main engine, in Newtons (kg m/s^2)

/***************************************************
 * NAME: Ashlee H
 * COMPUTE DISTANCE
 * Apply inertia to compute a new position using the distance equation.
 * The equation is:
 *     s = s + v t + 1/2 a t^2
 * INPUT
 *     s : original position, in meters
 *     v : velocity, in meters/second
 *     a : acceleration, in meters/second^2
 *     t : time, in seconds
 * OUTPUT
 *     s : new position, in meters
 **************************************************/

double computeDistance(double s, double v, double a, double t)
{
   return s + (v * t) + (0.5 * a * (t * t));
}

/**************************************************
 * NAME: Ashlee H
 * COMPUTE ACCELERATION
 * Find the acceleration given a thrust and mass.
 * This will be done using Newton's second law of motion:
 *     f = m * a
 * INPUT
 *     f : force, in Newtons (kg * m / s^2)
 *     m : mass, in kilograms
 * OUTPUT
 *     a : acceleration, in meters/second^2
 ***************************************************/
double computeAcceleration(double f, double m)
{
   //assert(m != 0.0);
   return f / m;
}

/***********************************************
 * NAME: Ashlee H
 * COMPUTE VELOCITY
 * Starting with a given velocity, find the new
 * velocity once acceleration is applied. This is
 * called the Kinematics equation. The
 * equation is:
 *     v = v + a t
 * INPUT
 *     v : velocity, in meters/second
 *     a : acceleration, in meters/second^2
 *     t : time, in seconds
 * OUTPUT
 *     v : new velocity, in meters/second
 ***********************************************/
double computeVelocity(double v, double a, double t)
{
   return v + (a * t);
}

/***********************************************
 * NAME: Ashlee H
 * COMPUTE VERTICAL COMPONENT
 * Find the vertical component of a velocity or acceleration.
 * The equation is:
 *     cos(a) = y / total
 * This can be expressed graphically:
 *      x
 *    +-----
 *    |   /
 *  y |  / total
 *    |a/
 *    |/
 * INPUT
 *     a : angle, in radians
 *     total : total velocity or acceleration
 * OUTPUT
 *     y : the vertical component of the total
 ***********************************************/
double computeVerticalComponent(double a, double total)
{
   double y = total * cos(a);
   return y;
}

/***********************************************
     * NAME: Emily Raventos
     * COMPUTE HORIZONTAL COMPONENT
     * Find the horizontal component of a velocity or acceleration.
     * The equation is:
     *     sin(a) = x / total
     * This can be expressed graphically:
     *      x
     *    +-----
     *    |   /
     *  y |  / total
     *    |a/
     *    |/
     * INPUT
     *     a : angle, in radians
     *     total : total velocity or acceleration
     * OUTPUT
     *     x : the vertical component of the total
     ***********************************************/
double computeHorizontalComponent(double a, double total)
{
   double x = sin(a) * total;
   return x;
}

/************************************************
      * NAME: Emily Raventos
      * COMPUTE TOTAL COMPONENT
      * Given the horizontal and vertical components of
      * something (velocity or acceleration), determine
      * the total component. To do this, use the Pythagorean Theorem:
      *    x^2 + y^2 = t^2
      * where:
      *      x
      *    +-----
      *    |   /
      *  y |  / total
      *    | /
      *    |/
      * INPUT
      *    x : horizontal component
      *    y : vertical component
      * OUTPUT
      *    total : total component
      ***********************************************/
double computeTotalComponent(double x, double y)
{
   return sqrt((x * x) + (y * y));
}

/*************************************************
       * NAME: Emily Raventos
       * RADIANS FROM DEGEES
       * Convert degrees to radians:
       *     radians / 2pi = degrees / 360
       * INPUT
       *     d : degrees from 0 to 360
       * OUTPUT
       *     r : radians from 0 to 2pi
       **************************************************/
double radiansFromDegrees(double d)
{
   double r;
   const double PI = 3.14159265358979323846;
   r = (d / 360) * (2 * PI);

   return r;
}

/**************************************************
        * NAME: Emily Raventos
        * PROMPT
        * A generic function to prompt the user for a double
        * INPUT
        *      message : the message to display to the user
        * OUTPUT
        *      response : the user's response
        ***************************************************/
double prompt(string message)
{
   double response;
   cout << message << ' ';
   cin >> response;

   return response;
}

/**************************************************
        * NAME: Emily Raventos and Ashlee Hart
        * CALCULATE SPEED
        * Given the initial position and the new position, calculate speed.
        *     speed = (n - h) / t
        * INPUT
        *      h : Initial Position
        *      n : New Position
        *      time : time  
        * OUTPUT
        *      speed : the speed of Apollo  11
***************************************************/
double computeSpeed(double x, double y, double x1, double y1)
{
   double distance = sqrt(((x - x1) * (x - x1)) + ((y - y1) * (y - y1)));
   double time = 1; // Change and have t be paramater for other time intervals. 
   return distance / time;
}

/**************************************************
        * NAME: 
        * FIND HORIZONTAL POSITION
        * Given the initial velocity, acceleration, and time, find the horizontal position
        *      h = v * t + ((1/2) * a * (t * t))
        * INPUT
        *      v : initial velocity
        *      a : acceleration
        *      t : time
        * OUTPUT
        *      h : horizontal position
        * 
        * ******** Figure out how to incorporate the angular movement of the object. *********
***************************************************/
double findHorizontalPosition(double v, double a, double t)
{
   return v * t + (0.5 * a * (t * t));
}

/****************************************************************
* MAIN
* Prompt for input, compute new position, and display output
****************************************************************/
int main()
{
   // Prompt for input and variables to be computed
   double dx = prompt("What is your horizontal velocity (m/s)? ");
   double dy = prompt("What is your vertical velocity (m/s)? ");
   double y = prompt("What is your altitude (m)? ");
   double x = 0.00;
   double aDegrees = prompt("What is the angle of the LM where 0 is up (degrees)? ");
   double t = 1.00; // The entire test is 10 seconds
   double aRadians;            // Angle in radians
   double accelerationThrust;  // Acceleration due to thrust
   double ddxThrust;         // Horizontal acceleration due to thrust
   double ddyThrust;           // Vertical acceleration due to thrust
   double ddx;              // Total horizontal acceleration
   double ddy;                 // Total vertical acceleration
   double v;                   // Total velocity

   // Compute acceleration because it does not change
   aRadians = radiansFromDegrees(aDegrees);
   accelerationThrust = computeAcceleration(THRUST, WEIGHT);
   ddxThrust = computeHorizontalComponent(aRadians, accelerationThrust);
   ddyThrust = computeVerticalComponent(aRadians, accelerationThrust);
   ddx = ddxThrust;
   ddy = ddyThrust + GRAVITY; // Changed * to +

   /////////////////////// vvvDELETE BEFORE TURNING INvvv ///////////////////////////////////////////////
   // Go through the simulator five times
   for (int count = 0; count < 5; count++)
   {
      // Compute stuff
      dx = computeVelocity(dx, ddx, t);
      dy = computeVelocity(dy, ddy, t);
      x = computeDistance(x, dx, ddx, t);
      y = computeDistance(y, dy, ddy, t);
      v = computeTotalComponent(dx, dy);

      /* Output for Problem Set 2
      cout.setf(ios::fixed | ios::showpoint);
      cout.precision(2);
      cout << "\tNew position:   (" << x << ", " << y << ")m\n";
      cout << "\tNew velocity:   (" << dx << ", " << dy << ")m/s\n";
      cout << "\tTotal velocity:  " << v << "m/s\n\n";
      */
   }
   /////////////////////// ^^^DELETE BEFORE TURNING IN^^^ ///////////////////////////////////////////////

   // Loop until the time reaches 10 seconds
   double time = 1.0
   while (time <= 10.0)
   {
      // Compute stuff
      // If we need acceleration, use the code above the deleted section
      fx = // Initial x position. Will be 0 for the first time through the loop.
      fy = // Initial y position. Will be altitude for the first time through the loop.
      px = // Position x. Get from a function
      py = // Position y. Get from a function
      dx = computeVelocity(dx, ddx, t);
      dy = computeVelocity(dy, ddy, t);
      s = computeSpeed(fx, fy, px, py); // To call, input initial position (x, y) and new position (x, y)
      aRadians = radiansFromDegrees(aDegrees);

      // Display time, position, velocity, speed, and angle.
      cout.setf(ios::fixed | ios::showpoint);
      cout.precision(2);
      cout << time << "s - "; // Time
           << "x, y: (" << x << ", " << y << ")m "// Position (x, y)
           << "dx, dy: (" << dx << ", " << dy << ")m/s" // Velocity (dx, dy)
           << "speed: " << speed << "m/s" // Speed
           << "angle: " << aRadians << "deg"; // Angle

      if (time == 5)
      {
         cout << "New angle: ";
         cin >> aRadians;
      }

      time ++
   }

   return 0;
}
