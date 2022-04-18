#include "CgRotationBody.h"
#include "CgBase/CgEnums.h"
#include "CgUtils/ObjLoader.h"

CgRotationBody::CgRotationBody(int id, std::vector<glm::vec3> vec, int size):
m_type(Cg::TriangleMesh),
m_id(id)
{
    for(int i=0; i<vec.size(); i++) {
        m_vertices.push_back(vec.at(i));  //alle Punkte bekannt machen
    }

    for(int i=0; i< (m_vertices.size() / size)-1; i++) {
        for(int j=0; j<size-1; j++) {
            int pos = i*size+j;

            m_triangle_indices.push_back(pos);
            m_triangle_indices.push_back(pos + 1);
            m_triangle_indices.push_back(pos + 1 + size);

            m_triangle_indices.push_back(pos);
            m_triangle_indices.push_back(pos + 1 + size);
            m_triangle_indices.push_back(pos + size);
        }
    }

    for (int i=0; i<m_triangle_indices.size(); i+=3) {
        //schwerpunkt berechnen
        glm::vec3 vec_center = (m_vertices[m_triangle_indices[i]] + m_vertices[m_triangle_indices[i+1]] + m_vertices[m_triangle_indices[i+2]]) / (3.0f);
        m_Schwerpunkt.push_back(vec_center);

        //Normale berechnen
        glm::vec3 vec1 = m_vertices[m_triangle_indices[i+1]] - m_vertices[m_triangle_indices[i]];
        glm::vec3 vec2 = m_vertices[m_triangle_indices[i+2]] - m_vertices[m_triangle_indices[i]];

        glm::vec3 normal = glm::cross(vec2,vec1);
        normal = glm::normalize(normal);

        m_face_normals.push_back(normal);  //nicht vei vertex_normals abspeichern !
    }

}



CgRotationBody::~CgRotationBody()
{
    m_vertices.clear();
    m_vertex_normals.clear();
    m_vertex_colors.clear();
    m_tex_coords.clear();
    m_triangle_indices.clear();
    m_face_normals.clear();
    m_face_colors.clear();
}

void CgRotationBody::init( std::vector<glm::vec3> arg_verts,  std::vector<glm::vec3> arg_normals, std::vector<unsigned int> arg_triangle_indices)
{
    m_vertices.clear();
    m_vertex_normals.clear();
    m_triangle_indices.clear();
    m_vertices=arg_verts;
    m_vertex_normals=arg_normals;
    m_triangle_indices=arg_triangle_indices;
}

void CgRotationBody::init( std::string filename)
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

const std::vector<glm::vec3>& CgRotationBody::getVertices() const
{
    return m_vertices;
}

const std::vector<glm::vec3>& CgRotationBody::getVertexNormals() const
{
    return m_vertex_normals;
}

const std::vector<glm::vec3>& CgRotationBody::getVertexColors() const
{
     return m_vertex_colors;
}

const std::vector<glm::vec2>& CgRotationBody:: getVertexTexCoords() const
{
    return m_tex_coords;
}

const std::vector<unsigned int>& CgRotationBody::getTriangleIndices() const
{
    return m_triangle_indices;
}

const std::vector<glm::vec3>& CgRotationBody::getFaceNormals() const
{
    return m_face_normals;
}

const std::vector<glm::vec3>& CgRotationBody::getFaceColors() const
{
    return m_face_colors;
}

const std::vector<glm::vec3>& CgRotationBody::getSchwerpunkt() const
{
    return m_Schwerpunkt;
}
