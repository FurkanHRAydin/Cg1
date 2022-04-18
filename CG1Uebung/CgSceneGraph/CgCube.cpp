#include "CgCube.h"
#include "CgBase/CgEnums.h"
#include "CgUtils/ObjLoader.h"
#include "../CgBase/CgPolyline.h"

CgCube::CgCube():
m_type(Cg::TriangleMesh),
m_id(42)
{
    m_vertices.push_back(glm::vec3(-0.5,0.0,0.0));
    m_vertices.push_back(glm::vec3(0.5,-0.5,0.0));
    m_vertices.push_back(glm::vec3(0.0,0.5,0.0));

    m_triangle_indices.push_back(0);
    m_triangle_indices.push_back(1);
    m_triangle_indices.push_back(2);

    m_vertex_normals.push_back(glm::vec3(0.0,0.0,1.0));
    m_vertex_normals.push_back(glm::vec3(0.0,0.0,1.0));
    m_vertex_normals.push_back(glm::vec3(0.0,0.0,1.0));
}

CgCube::CgCube(int id):
m_type(Cg::TriangleMesh),
m_id(id)
{
    //Punkte erstellen (x,y,z)Geometrisch
    //Vorderseite
    m_vertices.push_back(glm::vec3(-0.5,0.0,0.35)); //p0
    m_vertices.push_back(glm::vec3(0.0,-0.5,0.35)); //p1
    m_vertices.push_back(glm::vec3(0.0,0.5,0.35));  //p2
    m_vertices.push_back(glm::vec3(0.5,0.0,0.35));  //p3

    //Rueckseite
    m_vertices.push_back(glm::vec3(-0.5,0.0,-0.35)); //p4
    m_vertices.push_back(glm::vec3(0.0,-0.5,-0.35)); //p5
    m_vertices.push_back(glm::vec3(0.0,0.5,-0.35));  //p6
    m_vertices.push_back(glm::vec3(0.5,0.0,-0.35));  //p2




    //Linien Topologisch verbinden
    //Vorderfaleche

    m_triangle_indices.push_back(0); //S1(-0.5/3,0,0)
    m_triangle_indices.push_back(1);
    m_triangle_indices.push_back(2);

    m_triangle_indices.push_back(2); //S2(0.5/3,0,0)
    m_triangle_indices.push_back(1);
    m_triangle_indices.push_back(3);

    //Rueckflaeche

    m_triangle_indices.push_back(7);
    m_triangle_indices.push_back(5);
    m_triangle_indices.push_back(6);

    m_triangle_indices.push_back(6);
    m_triangle_indices.push_back(5);
    m_triangle_indices.push_back(4);

    //Seitenflaechen
    //Seite 1
    m_triangle_indices.push_back(0); //Dreieck 1
    m_triangle_indices.push_back(2); //S5(0.0,-1/3,-0.707/3)
    m_triangle_indices.push_back(4);

    m_triangle_indices.push_back(4);// Dreieck 2
    m_triangle_indices.push_back(2); //S6(-0.5/3,1/3,-2*0.707/3)
    m_triangle_indices.push_back(6);

    //Gegen Seite von 2
    m_triangle_indices.push_back(1); //Dreieck 1
    m_triangle_indices.push_back(5); //S9(0.5/3,-0.5/3,-2*0.707/3)
    m_triangle_indices.push_back(7);

    m_triangle_indices.push_back(1); // Dreieck 2
    m_triangle_indices.push_back(7); //S10(1/3,-0.5/3,-0.707/3)
    m_triangle_indices.push_back(3);


    //Seite 3
    m_triangle_indices.push_back(0); //Dreieck 1
    m_triangle_indices.push_back(4); //S7(-0.5/3,-0.5/3,-2*0.707/3
    m_triangle_indices.push_back(5);

    m_triangle_indices.push_back(0); // Dreieck 2
    m_triangle_indices.push_back(5); //S8(-0.5/3,-1/3,-0.707/3)
    m_triangle_indices.push_back(1);

    //Gegenseite von 3
    m_triangle_indices.push_back(3); //Dreieck 1
    m_triangle_indices.push_back(7); //S11(1/3,0.5/3,-2*0.707/3)
    m_triangle_indices.push_back(6);

    m_triangle_indices.push_back(3); // Dreieck 2
    m_triangle_indices.push_back(6); //S12(0.5/3,1/3,-0.707/3)
    m_triangle_indices.push_back(2);


    for (int i=0; i<m_triangle_indices.size(); i+=3) {
        //schwerpunkt berechnen
        glm::vec3 vec_center = (m_vertices[m_triangle_indices[i]] + m_vertices[m_triangle_indices[i+1]] + m_vertices[m_triangle_indices[i+2]]) / (3.0f);
        m_schwerpunkt.push_back(vec_center);

        //Normale berechnen
        glm::vec3 vec1 = m_vertices[m_triangle_indices[i+1]] - m_vertices[m_triangle_indices[i]];
        glm::vec3 vec2 = m_vertices[m_triangle_indices[i+2]] - m_vertices[m_triangle_indices[i]];

        glm::vec3 normal = glm::cross(vec1, vec2);
        normal = glm::normalize(normal);

        m_face_normals.push_back(normal);  //nicht vei vertex_normals abspeichern !
    }

}



CgCube::~CgCube()
{
    m_vertices.clear();
    m_vertex_normals.clear();
    m_vertex_colors.clear();
    m_tex_coords.clear();
    m_triangle_indices.clear();
    m_face_normals.clear();
    m_face_colors.clear();
}

void CgCube::init( std::vector<glm::vec3> arg_verts,  std::vector<glm::vec3> arg_normals, std::vector<unsigned int> arg_triangle_indices)
{
    m_vertices.clear();
    m_vertex_normals.clear();
    m_triangle_indices.clear();
    m_vertices=arg_verts;
    m_vertex_normals=arg_normals;
    m_triangle_indices=arg_triangle_indices;
}

void CgCube::init( std::string filename)
{
    m_vertices.clear();
    m_vertex_normals.clear();
    m_triangle_indices.clear();

    ObjLoader loader;
    loader.load(filename);

    loader.getPositionData(m_vertices);
    loader.getNormalData(m_vertex_normals);
    loader.getFaceIndexData(m_triangle_indices);
}

const std::vector<glm::vec3>& CgCube::getVertices() const
{
    return m_vertices;
}

const std::vector<glm::vec3>& CgCube::getVertexNormals() const
{
    return m_vertex_normals;
}

const std::vector<glm::vec3>& CgCube::getVertexColors() const
{
     return m_vertex_colors;
}

const std::vector<glm::vec2>& CgCube:: getVertexTexCoords() const
{
    return m_tex_coords;
}

const std::vector<unsigned int>& CgCube::getTriangleIndices() const
{
    return m_triangle_indices;
}

const std::vector<glm::vec3>& CgCube::getFaceNormals() const
{
    return m_face_normals;
}

const std::vector<glm::vec3>& CgCube::getFaceColors() const
{
    return m_face_colors;
}

const std::vector<glm::vec3>& CgCube::getSchwerpunkt() const
{
    return m_schwerpunkt;
}
