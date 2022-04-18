#ifndef CGPOLYLINE_H
#define CGPOLYLINE_H

#include "../CgBase/CgBasePolyline.h"
#include <vector>
#include <glm/glm.hpp>

class CgPolyline: public CgBasePolyline
{
public:
    CgPolyline(int index, std::vector<glm::vec3> vec);



    virtual ~CgPolyline();

    //inherited from CgBaseRenderableObject
    Cg::ObjectType getType() const override;
    unsigned int getID() const override;

    const std::vector<glm::vec3>& getVertices() const override;
    glm::vec3 getColor() const override;
    unsigned int getLineWidth() const override;
    void setVertices(std::vector<glm::vec3> newvertices);
    void addVertices(glm::vec3 segment);

private:
    const Cg::ObjectType m_type;
    const unsigned int m_id;
    std::vector<glm::vec3> m_vertices;
    glm::vec3 m_face_colors;
    int m_line_width;
};

#endif // CGPOLYLINE_H
