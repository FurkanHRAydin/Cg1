#ifndef CGCOLORCHANGEEVENT_H
#define CGCOLORCHANGEEVENT_H


#include "../CgBase/CgBaseEvent.h"
#include "../CgBase/CgEnums.h"
#include <string>
#include <iostream>

class CgColorChangeEvent: public CgBaseEvent
{
private:

    Cg::EventType type;
    unsigned int r;
    unsigned int g;
    unsigned int b;

public:


    CgColorChangeEvent();
    CgColorChangeEvent(Cg::EventType type, unsigned int r, unsigned int g, unsigned int b);

    Cg::EventType  getType();
    CgBaseEvent* clone();

    unsigned int getR();
    unsigned int getB();
    unsigned int getG();
};

#endif // CGCOLORCHANGEEVENT_H
