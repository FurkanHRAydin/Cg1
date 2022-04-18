#include "CgPolyline.h"


CgPolyline::CgPolyline(int index, std::vector<glm::vec3> vec):
m_type(Cg::Polyline),
m_id(index),
m_line_width{1},
m_face_colors{1}
{
    //m_verticies bekommt anfangs und endpunkt des Vekotrs zugewisen
    for(int i = 0; i< vec.size(); i++) {
        m_vertices.push_back(vec.at(i));

    }

}

const std::vector<glm::vec3>& CgPolyline:: getVertices() const
{
    return m_vertices;
}

glm::vec3 CgPolyline:: getColor() const
{
    return m_face_colors;
}

unsigned int CgPolyline:: getLineWidth() const
{
    return m_line_width;
}

Cg::ObjectType CgPolyline::getType() const {
    return m_type;
}
unsigned int CgPolyline::getID() const {
    return m_id;
}

CgPolyline::~CgPolyline() {
    m_vertices.clear();
}

void CgPolyline::setVertices(std::vector<glm::vec3> newvertices){
    m_vertices.clear();
    for(unsigned int i = 0; i< newvertices.size(); ++i) {
        m_vertices.push_back(newvertices.at(i));
    }
}
void CgPolyline::addVertices(glm::vec3 segment) {
    m_vertices.push_back(segment);
}

