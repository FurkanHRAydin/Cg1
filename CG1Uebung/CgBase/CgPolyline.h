#ifndef CGPOLYLINE_H
#define CGPOLYLINE_H

#include "CgBasePolyline.h"
#include <vector>
#include <glm/glm.hpp>

class CgPolyline: public CgBasePolyline
{
public:
    CgPolyline();
    CgPolyline(int index);
};

#endif // CGPOLYLINE_H
