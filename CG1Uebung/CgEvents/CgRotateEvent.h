#ifndef CGROTATE_H
#define CGROTATE_H


#include "../CgBase/CgBaseEvent.h"
#include "../CgBase/CgEnums.h"
#include <string>
#include <iostream>

class CgRotateEvent: public CgBaseEvent
{
public:
    CgRotateEvent();
    CgRotateEvent(Cg::EventType, int n, bool checked);

    Cg::EventType getType();
    CgBaseEvent* clone();

    int getN();
    bool getChecked();

private:
    unsigned int n;
    Cg::EventType type;
    bool checked;
};

#endif // CGROTATE_H
