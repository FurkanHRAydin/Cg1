#include "CgRotateEvent.h"

CgRotateEvent::CgRotateEvent()
{

}
CgRotateEvent::CgRotateEvent(Cg::EventType type, int n, bool checked)
{
    this->type=type;
    this->n =n;
    this->checked = checked;
}
//own method
int CgRotateEvent::getN() {
    return n;
}
bool CgRotateEvent::getChecked() {
    return checked;
}

Cg::EventType CgRotateEvent::getType() {
    return this->type;
}

//inherited
CgBaseEvent* CgRotateEvent::clone() {
    return new CgRotateEvent(this->type, this->n, this->checked);
}
