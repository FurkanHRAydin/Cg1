#include "CgColorChangeEvent.h"

CgColorChangeEvent::CgColorChangeEvent()
{
}

CgColorChangeEvent::CgColorChangeEvent(Cg::EventType type, unsigned int r, unsigned int g, unsigned int b) {
    this->type = type;
    this->r=r;
    this->g=g;
    this->b=b;
}


//inherited
Cg::EventType CgColorChangeEvent::getType() {
    return this->type;
}

//inherited
CgBaseEvent* CgColorChangeEvent::clone() {
    return new CgColorChangeEvent(this->type, this->r, this->b, this->g);
}

unsigned int CgColorChangeEvent::getR() {
    return r;
}

unsigned int CgColorChangeEvent::getG() {
    return g;
}

unsigned int CgColorChangeEvent::getB() {
    return b;
}
