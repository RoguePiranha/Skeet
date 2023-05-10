#pragma once
#include "point.h"

class Standard : public Bird
{
protected:
   Point dimensions;
   Point pt;
   Velocity v;
   double radius;
   bool dead;
   int points;

public:
   virtual void draw();
   virtual void advance();
}

class Variation : public Bird
{
protected:
   Bird * baseBird;


public:
    Variation(Bird * bird) : baseBird(bird) {}


private:
   void draw();
   void advance();
};

class Floater : public Bird
{
    Floater(Bird * bird) : Variation(bird) {}

    void draw();
    void advance();

};

class Crazy : public Bird
{
    Crazy(Bird * bird) : Variation(bird) {}

    void draw();
    void advance();

};

class Sinker : public Bird
{
    Sinker(Bird * bird) : Variation(bird) {}

    void draw();
    void advance();

};

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
   bool isOutOfBounds() const
   {
      return (pt.getX() < -radius || pt.getX() >= dimensions.getX() + radius ||
              pt.getY() < -radius || pt.getY() >= dimensions.getY() + radius);
   }

   // special functions
   virtual void draw() = 0;
   virtual void advance() = 0;
};