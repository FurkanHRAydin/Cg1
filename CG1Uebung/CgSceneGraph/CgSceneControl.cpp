#include "CgSceneControl.h"
#include "CgBase/CgEnums.h"
#include "CgEvents/CgMouseEvent.h"
#include "CgEvents/CgColorChangeEvent.h"
#include "CgEvents/CgLaneRiesenfeld.h"
#include "CgEvents/CgRotateEvent.h"
#include "CgEvents/CgKeyEvent.h"
#include "CgEvents/CgWindowResizeEvent.h"
#include "CgEvents/CgLoadObjFileEvent.h"
#include "CgEvents/CgTrackballEvent.h"
#include "CgBase/CgBaseRenderer.h"
#include "CgExampleTriangle.h"
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include "CgUtils/ObjLoader.h"
#include <string>
#include "CgCube.h"
#include "CgRotationBody.h"
#include "CgPolyline.h"
#include "../CgUtils/Functions.h"

CgSceneControl::CgSceneControl()
{
    m_cube=nullptr;
    m_rotate=nullptr;
    m_current_transformation=glm::mat4(1.);
    m_lookAt_matrix= glm::lookAt(glm::vec3(0.0,0.0,1.0),glm::vec3(0.0,0.0,0.0),glm::vec3(0.0,1.0,0.0));
    m_proj_matrix= glm::mat4x4(glm::vec4(1.792591, 0.0, 0.0, 0.0), glm::vec4(0.0, 1.792591, 0.0, 0.0), glm::vec4(0.0, 0.0, -1.0002, -1.0), glm::vec4(0.0, 0.0, -0.020002, 0.0));
    m_trackball_rotation=glm::mat4(1.);

   /* Drawing Cube
    m_cube = new CgCube(21);
    for(int i=0; i < m_cube->getFaceNormals().size() ; i++) {
        std::vector<glm::vec3> vec;
        vec.push_back(m_cube->getSchwerpunkt()[i]);
        vec.push_back((m_cube->getSchwerpunkt()[i]) + (m_cube->getFaceNormals()[i]) );
        m_polylines.push_back(new CgPolyline(i, vec));
    }
    */


   vec.push_back(glm::vec3(0.0, 2.0, 0.0));
   vec.push_back(glm::vec3(1.0, 1.0, 0.0));
   vec.push_back(glm::vec3(1.0, -1.0, 0.0));
   vec.push_back(glm::vec3(0.0, -2.0, 0.0));

   m_polyline = new CgPolyline(Functions::getId(), vec);


}


CgSceneControl::~CgSceneControl()
{

    if(m_cube!=NULL)
        delete m_cube;

    for(unsigned int i = 0; i < m_polylines.size(); i++) {
        if(m_polylines[i] != NULL)
            delete m_polylines[i];
    }

    if (m_polyline != NULL)
            delete m_polyline;

    if(m_rotate!=NULL)
        delete m_rotate;


}

void CgSceneControl::setRenderer(CgBaseRenderer* r)
{
    m_renderer=r;
    m_renderer->setSceneControl(this);

    //set Color in the beginn of the Rendering - removed form rederObjects()!
    m_renderer->setUniformValue("mycolor",glm::vec4(0.0,1.0,0.0,1.0));

    if(m_cube!=NULL)
        m_renderer->init(m_cube);
    /*
    for(unsigned int i = 0; i < m_polylines.size() ; i++) {
        if(m_polylines[i] != NULL)
            m_renderer->init(m_polylines[i]);
    }
    */

    if(m_polyline!=NULL)
            m_renderer->init(m_polyline);

    if(m_rotate!=NULL)
            m_renderer->init(m_rotate);

}


void CgSceneControl::renderObjects()
{

    // Materialeigenschaften setzen
    // sollte ja eigentlich pro Objekt unterschiedlich sein können, naja bekommen sie schon hin....


    m_renderer->setUniformValue("matDiffuseColor",glm::vec4(0.35,0.31,0.09,1.0));
    m_renderer->setUniformValue("lightDiffuseColor",glm::vec4(1.0,1.0,1.0,1.0));


    m_renderer->setUniformValue("matAmbientColor",glm::vec4(0.25,0.22,0.06,1.0));
    m_renderer->setUniformValue("lightAmbientColor",glm::vec4(1.0,1.0,1.0,1.0));


    m_renderer->setUniformValue("matSpecularColor",glm::vec4(0.8,0.72,0.21,1.0));
    m_renderer->setUniformValue("lightSpecularColor",glm::vec4(1.0,1.0,1.0,1.0));





    glm::mat4 mv_matrix = m_lookAt_matrix * m_trackball_rotation* m_current_transformation ;
    glm::mat3 normal_matrix = glm::transpose(glm::inverse(glm::mat3(mv_matrix)));

    m_renderer->setUniformValue("projMatrix",m_proj_matrix);
    m_renderer->setUniformValue("modelviewMatrix",mv_matrix);
    m_renderer->setUniformValue("normalMatrix",normal_matrix);

    if(m_cube!=NULL)
        m_renderer->render(m_cube);

    for(unsigned int i = 0; i < m_polylines.size(); i++) {
        if(m_polylines[i] != NULL)
            m_renderer->render(m_polylines[i]);
    }

    if(m_polyline!=NULL)
        m_renderer->render(m_polyline);

    if(m_rotate!=NULL)
        m_renderer->render(m_rotate);

}




void CgSceneControl::handleEvent(CgBaseEvent* e)
{

    if(e->getType() & Cg::CgColorChangeEvent)
    {
        CgColorChangeEvent* ev = (CgColorChangeEvent*)e;

        double red = ev->getR() / 255.0;
        double blue = ev->getB() / 255.0;
        double green = ev->getG() / 255.0;

        m_renderer->setUniformValue("mycolor",glm::vec4(red,blue,green,1.0));
        m_renderer->redraw(); //zeichnet neu mit farbaenderung

        std::cout << ev->getType() << " " << ev->getR()<< " " << ev->getB()<< " " << ev->getG() << std::endl;
    }

    // die Enums sind so gebaut, dass man alle Arten von MausEvents über CgEvent::CgMouseEvent abprüfen kann,
    // siehe dazu die CgEvent enums im CgEnums.h


    if(e->getType() & Cg::CgLaneRiesenfeld) {
        CgLaneRiesenfeld* ev = (CgLaneRiesenfeld*)e;
        unsigned int n = ev->getN();

        m_polyline->setVertices(Functions::LaneRiesenfeld(vec, n));

            m_renderer->init(m_polyline);
            m_renderer->redraw();

            std::cout << ev->getType() << " " <<  ev->getN() << std::endl;

    }

    if(e->getType() & Cg::CgReset) {
        CgLaneRiesenfeld* ev = (CgLaneRiesenfeld*)e;

        m_polyline->setVertices(vec);

        m_renderer->init(m_polyline);
        m_renderer->redraw();

        std::cout << ev->getType() << " " << std::endl;

    }




    if(e->getType() & Cg::CgRotateEvent) {
        CgRotateEvent* ev = (CgRotateEvent*)e;
        int n = ev->getN();
        double beta = 2*M_PI / n;

        int size = m_polyline->getVertices().size();

        for(int i=0; i<n; i++) {

            for( int j=0; j < size; j++) {

                float x_strich = m_polyline->getVertices().at(j)[0]*cos(beta) - m_polyline->getVertices().at(j)[2]*sin(beta);
                float z_strich = m_polyline->getVertices().at(j)[0]*sin(beta) + m_polyline->getVertices().at(j)[2]*cos(beta);

                m_polyline->addVertices(glm::vec3(x_strich,m_polyline->getVertices().at(j)[1], z_strich));
            }
            beta += 2*M_PI / n;
        }

        m_rotate = new CgRotationBody(Functions::getId(), m_polyline->getVertices(), size);

        delete m_polyline;
        m_polyline = nullptr;


        //same algorithm for cube
        if(ev->getChecked()) {
            /*
            for(int i=0; i < m_rotate->getFaceNormals().size() ; i++) {
                std::vector<glm::vec3> vec;
                vec.push_back(m_rotate->getSchwerpunkt()[i]);
                vec.push_back((m_rotate->getSchwerpunkt()[i]) + (m_rotate->getFaceNormals()[i]) );
                m_polylines.push_back(new CgPolyline(Functions::getId(), vec));
            }
            */

            for(int i=0; i < m_rotate->getVertexNormals().size() ; i++) {
                std::vector<glm::vec3> vec;
                vec.push_back(m_rotate->getVertices()[i]);
                vec.push_back((m_rotate->getVertices()[i]) + (m_rotate->getVertexNormals()[i]) );
                m_polylines.push_back(new CgPolyline(Functions::getId(), vec));
            }

            for( int i=0; i<m_polylines.size(); i++) {
                m_renderer->render(m_polylines[i]);
                m_renderer->init(m_polylines[i]);
            }
        }


        m_renderer->init(m_rotate);
        m_renderer->redraw();

        std::cout << ev->getType() << " " << ev->getChecked()<<std::endl;


    }

    if(e->getType() & Cg::CgMouseEvent)
    {
        CgMouseEvent* ev = (CgMouseEvent*)e;
        std::cout << *ev << std::endl;

         // hier kommt jetzt die Abarbeitung des Events hin...
    }


    if(e->getType() & Cg::CgTrackballEvent)
    {
        CgTrackballEvent* ev = (CgTrackballEvent*)e;


        m_trackball_rotation=ev->getRotationMatrix();
        m_renderer->redraw();

    }


    // die Enums sind so gebaut, dass man alle Arten von KeyEvents über CgEvent::CgKeyEvent abprüfen kann,
    // siehe dazu die CgEvent enums im CgEnums.h
    // momentan werden nur KeyPressEvents gefangen.

    if(e->getType() & Cg::CgKeyEvent)
    {
        CgKeyEvent* ev = (CgKeyEvent*)e;
        std::cout << *ev <<std::endl;

        if(ev->text()=="+")
        {
            glm::mat4 scalemat = glm::mat4(1.);
            scalemat = glm::scale(scalemat,glm::vec3(1.2,1.2,1.2));
            m_current_transformation=m_current_transformation*scalemat;
            m_renderer->redraw();
        }
        if(ev->text()=="-")
        {
            glm::mat4 scalemat = glm::mat4(1.);
            scalemat = glm::scale(scalemat,glm::vec3(0.8,0.8,0.8));

            m_current_transformation=m_current_transformation*scalemat;

            m_renderer->redraw();
        }
        // hier kommt jetzt die Abarbeitung des Events hin...
    }

    if(e->getType() & Cg::WindowResizeEvent)
    {
         CgWindowResizeEvent* ev = (CgWindowResizeEvent*)e;
         std::cout << *ev <<std::endl;
         m_proj_matrix=glm::perspective(45.0f, (float)(ev->w()) / ev->h(), 0.01f, 100.0f);
    }

    if(e->getType() & Cg::LoadObjFileEvent)
    {

        CgLoadObjFileEvent* ev = (CgLoadObjFileEvent*)e;


        ObjLoader* loader= new ObjLoader();
        loader->load(ev->FileName());

        std::cout << ev->FileName() << std::endl;

        std::vector<glm::vec3> pos;
        loader->getPositionData(pos);

         std::vector<glm::vec3> norm;
         loader->getNormalData(norm);

          std::vector<unsigned int> indx;
          loader->getFaceIndexData(indx);



        m_cube->init(pos,norm,indx);
        m_renderer->init(m_cube);
        m_renderer->redraw();
    }

    // an der Stelle an der ein Event abgearbeitet ist wird es auch gelöscht.
    delete e;


}
