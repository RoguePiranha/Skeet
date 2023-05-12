/***********************************************************************
 * Header File:
 *    Bird : Everything that can be shot
 * Author:
 *    Br. Helfrich
 * Co-Authors:
 *    Michael Darling, Andrew Swayze
 * Summary:
 *    Stuff that moves across the screen to be shot
 ************************************************************************/

#pragma once
#include "point.h"
#include <list>

class AdvanceDecorator;

/**********************
 * BIRD
 * Everything that can be shot
 **********************/
class Bird
{
protected:
   static Point dimensions; // size of the screen
   Point pt;                  // position of the flyer
   Velocity v;                // velocity of the flyer
   double radius;             // the size (radius) of the flyer
   bool dead;                 // is this flyer dead?
   int points;                // how many points is this worth?
   std::list<AdvanceDecorator*> decorators;
   
public:
   Bird() : dead(false), points(0), radius(1.0) { }
   
   // setters
   void operator=(const Point    & rhs) { pt = rhs;    }
   void operator=(const Velocity & rhs) { v = rhs;     }
   void kill()                          { dead = true; }

   // getters
   bool isDead()           const { return dead;   }
   Point getPosition()     const { return pt;     }
   Velocity getVelocity()  const { return v;      }
   double getRadius()      const { return radius; }
   int getPoints() const { return points; }

   // setters
   void setPosition(Point position)     { this->pt = position; }
   void setVelocity(Velocity velocity) { this->v = velocity; }

   bool isOutOfBounds() const
   {
      return (pt.getX() < -radius || pt.getX() >= dimensions.getX() + radius ||
              pt.getY() < -radius || pt.getY() >= dimensions.getY() + radius);
   }

   // special functions
   virtual void draw() = 0;
   void advance();
};

/*********************************************
 * STANDARD
 * A standard bird: slows down, flies in a straight line
 *********************************************/
class Standard : public Bird
{
public:
    Standard(double radius = 25.0, double speed = 5.0, int points = 10);
    void draw();
};

/*********************************************
 * FLOATER
 * A bird that floats like a balloon: flies up and really slows down
 *********************************************/
class Floater : public Bird
{
public:
    Floater(double radius = 30.0, double speed = 5.0, int points = 15);
    void draw();
};

/*********************************************
 * CRAZY
 * A crazy flying object: randomly changes direction
 *********************************************/
class Crazy : public Bird
{
public:
    Crazy(double radius = 30.0, double speed = 4.5, int points = 30);
    void draw();
};

/*********************************************
 * SINKER
 * A sinker bird: honors gravity
 *********************************************/
class Sinker : public Bird
{
public:
    Sinker(double radius = 30.0, double speed = 4.5, int points = 20);
    void draw();
};


/*********************************************/
/* Decorators                                */
/*     -AdvanceDecorator                     */
/*     -InertiaDecorator                     */
/*     -GravityDecorator                     */
/*     -DragDecorator                        */
/*     -BouyancyDecorator                    */
/*     -TurnDecorator                        */
/*********************************************/

class AdvanceDecorator {
public:
    virtual void apply(Bird * bird) = 0;
};

class InertiaDecorator : public AdvanceDecorator {
public:
   void apply(Bird* bird);
};

class GravityDecorator : public AdvanceDecorator {
private:
   double gravity;
public:
   GravityDecorator(double gravity) : gravity(gravity) {}
   void apply(Bird * bird);
};

class DragDecorator : public AdvanceDecorator {
private:
    double drag;
public:
    DragDecorator(double drag) : drag(drag) {}
    void apply(Bird * bird) override;
};

class BouyancyDecorator : public AdvanceDecorator {
private:
   double bouyancy;
public:
   BouyancyDecorator(double bouyancy) : bouyancy(bouyancy) {}
   void apply(Bird * bird);
};

class TurnDecorator : public AdvanceDecorator {
private:
   bool turnEnabled;
   int turnQuantity;
public:
    TurnDecorator(int turnQuantity, bool turnEnabled) : turnQuantity(turnQuantity), turnEnabled(turnEnabled) {}
    void apply(Bird * bird);
};
