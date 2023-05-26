/***********************************************************************
 * Header File:
 *    Observer: The base class for all observers
 * Author:
 *    Andrew Swayze
 * Summary:
 *    This class is the base class for all observers. It provides the
 *    interface for updating the observer.
 ************************************************************************/

#include "subject.h"
#include <string>

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(Subject* subject) = 0;
};

/**********************
 * SCORE
 * Points earned vs lost
 **********************/
class Score : public Observer
{
public:
    Score() { reset(); }
    std::string getText() const;
    void adjust(int value) { points += value; }
    void reset() { points = 0; };
    void update(Subject* subject);
private:
    int points;
};

/**********************
 * HIT RATIO
 * Bird hit ratio
 **********************/
class HitRatio : public Observer
{
public:
    HitRatio()  { reset(); }
    std::string getText() const;
    void adjust(int value);
    void reset() { numKilled = numMissed = 0; }
    void update(Subject* subject);
private:
    int numKilled;
    int numMissed;
};