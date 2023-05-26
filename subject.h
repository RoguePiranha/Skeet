/***********************************************************************
 * Header File:
 *    Subject: The base class for all subjects
 * Author:
 *    Andrew Swayze
 * Summary:
 *    This class is the base class for all subjects. It provides the
 *    interface for attaching, detaching, and notifying observers.
 ************************************************************************/

class Subject {
public:
    virtual ~Subject() = default;
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify() = 0;
};