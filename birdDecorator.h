#pragma once
#include "point.h"

/**********************
 * BIRD
 * Everything that can be shot
 **********************/
class Bird
{
protected:
    static Point dimensions; // size of the screen
    Point pt;                // position of the flyer
    Velocity v;              // velocity of the flyer
    double radius;           // the size (radius) of the flyer
    bool dead;               // is this flyer dead?
    int points;              // how many points is this worth?

public:
    Bird() : dead(false), points(0), radius(1.0) {}

    // setters
    void operator=(const Point &rhs) { pt = rhs; }
    void operator=(const Velocity &rhs) { v = rhs; }
    void kill() { dead = true; }

    // getters
    bool isDead() const { return dead; }
    Point getPosition() const { return pt; }
    Velocity getVelocity() const { return v; }
    double getRadius() const { return radius; }
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
    Standard(double radius = 25.0, double speed = 5.0, int points = 10);
    void draw();
    void advance();
};

class Variation : public Bird
{
protected:
    Bird *baseBird;

public:

    Variation(Bird *bird) : baseBird(bird) {}

    void draw();
    void advance();
};

class Floater : public Variation
{
protected:
    double radius;
    double speed;
    int points;

public:
    // initialize and update values
        // Alternative1 - Floater(Bird *bird) : Variation(bird) {}
        // Alternative2 - Floater(Bird *bird) : Variation(bird), radius(30.0), speed(5.0), points(15) {}
    Floater(Bird *bird) : radius(30.0), speed(5.0), points(15) {}

    void draw();
    void advance();
};

class Crazy : public Variation
{
public:
    // initialize and update values
    Crazy(Bird *bird) : radius(30.0), speed(4.5), points(30) {}

    void draw();
    void advance();
};

class Sinker : public Variation
{
public:
    // initialize and update values
    Sinker(Bird *bird) : radius(30.0), speed(4.5), points(20) {}

    void draw();
    void advance();
};
