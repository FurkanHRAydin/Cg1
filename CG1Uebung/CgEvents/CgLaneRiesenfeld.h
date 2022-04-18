#ifndef CGLANERIESENFELD_H
#define CGLANERIESENFELD_H


#include "../CgBase/CgBaseEvent.h"
#include "../CgBase/CgEnums.h"
#include <string>
#include <iostream>

class CgLaneRiesenfeld: public CgBaseEvent
{
public:
    CgLaneRiesenfeld();
    CgLaneRiesenfeld(Cg::EventType);
    CgLaneRiesenfeld(Cg::EventType, int n);

    Cg::EventType getType();
    CgBaseEvent* clone();

    unsigned int getN();

private:
    unsigned int n;
    Cg::EventType type;
};

#endif // CGLANERIESENFELD_H
