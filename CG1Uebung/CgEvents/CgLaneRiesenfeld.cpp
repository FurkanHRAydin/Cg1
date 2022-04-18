#include "CgLaneRiesenfeld.h"

CgLaneRiesenfeld::CgLaneRiesenfeld()
{

}

CgLaneRiesenfeld::CgLaneRiesenfeld(Cg::EventType type)
{
    this->type=type;
}

CgLaneRiesenfeld::CgLaneRiesenfeld(Cg::EventType type, int n)
{
    this->type=type;
    this->n =n;
}
//own method
unsigned int CgLaneRiesenfeld::getN() {
    return n;
}

Cg::EventType CgLaneRiesenfeld::getType() {
    return this->type;
}

//inherited
CgBaseEvent* CgLaneRiesenfeld::clone() {
    return new CgLaneRiesenfeld(this->type, this->n);
}

