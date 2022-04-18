

#include "CgQtGLRenderWidget.h"
#include "CgQtGui.h"
#include "CgQtMainApplication.h"
#include "../CgBase/CgEnums.h"
#include "../CgEvents/CgMouseEvent.h"
#include "../CgEvents/CgKeyEvent.h"
#include "../CgEvents/CgWindowResizeEvent.h"
#include "../CgEvents/CgLoadObjFileEvent.h"
#include "../CgEvents/CgTrackballEvent.h"
#include "../CgEvents/CgColorChangeEvent.h"
#include "../CgEvents/CgLaneRiesenfeld.h"
#include "../CgEvents/CgRotateEvent.h"
#include <QSlider>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QPushButton>
#include <QDesktopWidget>
#include <QApplication>
#include <QMessageBox>
#include <QLabel>
#include <QSpinBox>
#include <QCheckBox>
#include <QPushButton>
#include <QGroupBox>
#include <QButtonGroup>
#include <QRadioButton>
#include <QMenuBar>
#include <QActionGroup>
#include <QFileDialog>
#include <iostream>



CgQtGui::CgQtGui(CgQtMainApplication *mw)
    : m_mainWindow(mw)
{
    m_glRenderWidget = new CgQtGLRenderWidget;


    connect(m_glRenderWidget, SIGNAL(mouseEvent(QMouseEvent*)), this, SLOT(mouseEvent(QMouseEvent*)));
    connect(m_glRenderWidget, SIGNAL(viewportChanged(int,int)), this, SLOT(viewportChanged(int,int)));
    connect(m_glRenderWidget, SIGNAL(trackballChanged()), this, SLOT(slotTrackballChanged()));


    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *container = new QHBoxLayout;


    QWidget *opt = new QWidget;
    createOptionPanelExample1(opt);

    QWidget *otheropt = new QWidget;
    createOptionPanelExample2(otheropt);

    QWidget *otheropt2 = new QWidget;
    createOptionPanelExample3(otheropt2);

    QTabWidget* m_tabs = new QTabWidget();
    m_tabs->addTab(opt,"&Color");
    m_tabs->addTab(otheropt,"&LRA");
    m_tabs->addTab(otheropt2,"&Rotation");
    container->addWidget(m_tabs);

    m_tabs->setMaximumWidth(400);

    container->addWidget(m_glRenderWidget);

    QWidget *w = new QWidget;
    w->setLayout(container);
    mainLayout->addWidget(w);

    setLayout(mainLayout);
    setWindowTitle(tr("Übung Computergrafik 1 -  SoSe 2021"));


    /* create Menu Bar */
    m_menuBar = new QMenuBar;
    QMenu *file_menu = new QMenu("&File" );
    file_menu->addAction("&Open Mesh Model", this, SLOT(slotLoadMeshFile()));
    // todo: Add Quit-Action
    m_menuBar->addMenu( file_menu );
    QMenu *settings_menu = new QMenu("&Setting" );
    QMenu *polygon_mode_menu = new QMenu("&Polygon Mode" );

    QAction* m_custom_rot=settings_menu->addAction("&Custom Rotations", m_glRenderWidget, SLOT(slotCustomRotation()));
    m_custom_rot->setCheckable(true);
    m_custom_rot->setChecked(false);

    QAction* m_lighting=settings_menu->addAction("&Lighting on", m_glRenderWidget, SLOT(slotLighting()));
    m_lighting->setCheckable(true);
    m_lighting->setChecked(false);


    QActionGroup* polygonmode_group = new QActionGroup(this);
    polygonmode_group->setExclusive(true);

    QAction* points=polygon_mode_menu->addAction("&Points", m_glRenderWidget, SLOT(slotPolygonPoints()));
    points->setCheckable(true);
    points->setChecked(false);


    QAction* wireframe=polygon_mode_menu->addAction("&Wireframe", m_glRenderWidget, SLOT(slotPolygonWireframe()));
    wireframe->setCheckable(true);
    wireframe->setChecked(true);

    QAction* filled=polygon_mode_menu->addAction("&Filled", m_glRenderWidget, SLOT(slotPolygonFilled()));
    filled->setCheckable(true);
    filled->setChecked(false);



    polygonmode_group->addAction(points);
    polygonmode_group->addAction(wireframe);
    polygonmode_group->addAction(filled);



    // todo: Add Quit-Action
    m_menuBar->addMenu( file_menu );
    m_menuBar->addMenu( settings_menu );
    m_menuBar->addMenu( polygon_mode_menu );


    m_mainWindow->setMenuBar(m_menuBar);



}

QSlider *CgQtGui::createSlider()
{
    QSlider *slider = new QSlider(Qt::Vertical);
    slider->setRange(0, 360 * 16);
    slider->setSingleStep(16);
    slider->setPageStep(15 * 16);
    slider->setTickInterval(15 * 16);
    slider->setTickPosition(QSlider::TicksRight);
    return slider;
}







void CgQtGui::createOptionPanelExample1(QWidget* parent)
{
    QVBoxLayout *tab1_control = new QVBoxLayout();


    /*Example for using a label */

    QLabel *options_label = new QLabel("Farbeinstellung");
    tab1_control->addWidget(options_label);
    options_label->setAlignment(Qt::AlignCenter);


    /*Example for using a spinbox */

    mySpinBox1 = new QSpinBox();
    tab1_control->addWidget(mySpinBox1);
    mySpinBox1->setMinimum(0);
    mySpinBox1->setMaximum(256);
    mySpinBox1->setValue(0);
    //mySpinBox1->setSuffix("   suffix");
    mySpinBox1->setPrefix("R: ");
    connect(mySpinBox1, SIGNAL(valueChanged(int) ), this, SLOT(slotMySpinBox1Changed()) );
    tab1_control->addWidget(mySpinBox1);

    mySpinBox2 = new QSpinBox();
    tab1_control->addWidget(mySpinBox2);
    mySpinBox2->setMinimum(0);
    mySpinBox2->setMaximum(256);
    mySpinBox2->setValue(0);
   // mySpinBox2->setSuffix("   suffix");
    mySpinBox2->setPrefix("G: ");
    connect(mySpinBox2, SIGNAL(valueChanged(int) ), this, SLOT(slotMySpinBox2Changed()) );
    tab1_control->addWidget(mySpinBox2);

    mySpinBox3 = new QSpinBox();
    tab1_control->addWidget(mySpinBox3);
    mySpinBox3->setMinimum(0);
    mySpinBox3->setMaximum(256);
    mySpinBox3->setValue(0);
   // mySpinBox3->setSuffix("   suffix");
    mySpinBox3->setPrefix("B: ");
    connect(mySpinBox3, SIGNAL(valueChanged(int) ), this, SLOT(slotMySpinBox3Changed()) );
    tab1_control->addWidget(mySpinBox3);


    /*Example for using a checkbox

    myCheckBox1 = new QCheckBox("enable Option 1");
    myCheckBox1->setCheckable(true);
    myCheckBox1->setChecked(false);
    connect(myCheckBox1, SIGNAL( clicked() ), this, SLOT(slotMyCheckBox1Changed()) );
    tab1_control->addWidget(myCheckBox1);

    */

    /*Example for using a button */

    QPushButton* myButton1 = new QPushButton("Change colors");
    tab1_control->addWidget(myButton1);

    connect(myButton1, SIGNAL( clicked() ), this, SLOT(slotMyButton1Pressed()) );

    parent->setLayout(tab1_control);

}

void CgQtGui::createOptionPanelExample2(QWidget* parent)
{
    QVBoxLayout *tab2_control = new QVBoxLayout();


    /*Example for using a label */

    QLabel *options_label = new QLabel("Mittelungschritte angeben.");
    tab2_control->addWidget(options_label);
    options_label->setAlignment(Qt::AlignCenter);


    /*Example for using a spinbox */

    mySpinBox4 = new QSpinBox();
    tab2_control->addWidget(mySpinBox4);
    mySpinBox4->setMinimum(0);
    mySpinBox4->setMaximum(10);
    mySpinBox4->setValue(0);
    //mySpinBox1->setSuffix("   suffix");
    //mySpinBox3->setPrefix("R: ");
    connect(mySpinBox4, SIGNAL(valueChanged(int) ), this, SLOT(slotMySpinBox4Changed()) );
    tab2_control->addWidget(mySpinBox4);

    /*Example for using a checkbox

    myCheckBox1 = new QCheckBox("enable Option 1");
    myCheckBox1->setCheckable(true);
    myCheckBox1->setChecked(false);
    connect(myCheckBox1, SIGNAL( clicked() ), this, SLOT(slotMyCheckBox1Changed()) );
    tab1_control->addWidget(myCheckBox1);

    */

    /*Example for using a button */

    QPushButton* myButton2 = new QPushButton("Verfeinern");
    QPushButton* myButton3 = new QPushButton("Reset");
    tab2_control->addWidget(myButton2);
    tab2_control->addWidget(myButton3);

    connect(myButton2, SIGNAL( clicked() ), this, SLOT(slotMyButton2Pressed()) );
    connect(myButton3, SIGNAL( clicked() ), this, SLOT(slotMyButton3Pressed()) );

    parent->setLayout(tab2_control);

}

void CgQtGui::createOptionPanelExample3(QWidget* parent)
{
    QVBoxLayout *tab3_control = new QVBoxLayout();


    /*Example for using a label */

    QLabel *options_label = new QLabel("Anzahl Segmente");
    tab3_control->addWidget(options_label);
    options_label->setAlignment(Qt::AlignCenter);


    /*Example for using a spinbox */

    mySpinBox5 = new QSpinBox();
    tab3_control->addWidget(mySpinBox5);
    mySpinBox5->setMinimum(0);
    mySpinBox5->setMaximum(360);
    mySpinBox5->setValue(0);
    connect(mySpinBox5, SIGNAL(valueChanged(int) ), this, SLOT(slotMySpinBox5Changed()) );
    tab3_control->addWidget(mySpinBox5);

    //Example for using a checkbox

    myCheckBox1 = new QCheckBox("Normalen anzeigen");
    myCheckBox1->setCheckable(true);
    myCheckBox1->setChecked(false);
    connect(myCheckBox1, SIGNAL( clicked() ), this, SLOT(slotMyCheckBox1Changed()) );
    tab3_control->addWidget(myCheckBox1);


    /*Example for using a button */

    QPushButton* myButton4 = new QPushButton("Rotieren");
    tab3_control->addWidget(myButton4);


    connect(myButton4, SIGNAL( clicked() ), this, SLOT(slotMyButton4Pressed()) );

    parent->setLayout(tab3_control);

}


void CgQtGui::slotButtonGroupSelectionChanged()
{

}

void CgQtGui::slotMySpinBox1Changed()
{

}

void CgQtGui::slotMySpinBox2Changed()
{

}

void CgQtGui::slotMySpinBox3Changed()
{

}

void CgQtGui::slotMySpinBox4Changed()
{

}

void CgQtGui::slotMySpinBox5Changed()
{

}

void CgQtGui::slotMyCheckBox1Changed()
{

}


void CgQtGui::slotLoadMeshFile()
{



   QString file=  QFileDialog::getOpenFileName(this, tr("Open Obj-File"),"",tr("Model Files (*.obj)"));


    CgBaseEvent* e = new CgLoadObjFileEvent(Cg::LoadObjFileEvent, file.toStdString());

    notifyObserver(e);
}


void CgQtGui::slotTrackballChanged()
{
    CgBaseEvent* e = new CgTrackballEvent(Cg::CgTrackballEvent, m_glRenderWidget->getTrackballRotation());
    notifyObserver(e);
}

void CgQtGui::slotMyButton1Pressed()
{
   CgBaseEvent* e = new CgColorChangeEvent(Cg::CgColorChangeEvent, mySpinBox1->value(), mySpinBox2->value(), mySpinBox3->value());

   std::cout << "button 1 pressed " << std::endl;
   std::cout << "Color 1 changed " << std::endl;
   std::cout << "Color 2 changed " << std::endl;
   std::cout << "Coller 3 changed " << std::endl;

   notifyObserver(e);
}

void CgQtGui::slotMyButton2Pressed()
{
    CgBaseEvent* e = new CgLaneRiesenfeld(Cg::CgLaneRiesenfeld, mySpinBox4->value());

    std::cout << "button 2 pressed " << std::endl;

    notifyObserver(e);
}

void CgQtGui::slotMyButton3Pressed()
{
    CgBaseEvent* e = new CgLaneRiesenfeld(Cg::CgReset);

    std::cout << "button 3 pressed " << std::endl;

    notifyObserver(e);
}

void CgQtGui::slotMyButton4Pressed()
{
    CgBaseEvent* e = new CgRotateEvent(Cg::CgRotateEvent, mySpinBox5->value(), myCheckBox1->isChecked());

    std::cout << "button 4 pressed " << std::endl;

    notifyObserver(e);
}


void CgQtGui::mouseEvent(QMouseEvent* event)
{

   // std::cout << QApplication::keyboardModifiers() << std::endl;

  //  if(QApplication::keyboardModifiers().testFlag(Qt::ControlModifier)==true)
    //    std::cout << Cg::ControlModifier << endl;


   if(event->type()==QEvent::MouseButtonPress)
   {


        CgBaseEvent* e = new CgMouseEvent(Cg::CgMouseButtonPress,
                                          glm::vec2(event->localPos().x() ,event->localPos().y()),
                                          (Cg::MouseButtons)event->button());

        notifyObserver(e);
   }

   if(event->type()==QEvent::MouseMove)
   {
       CgBaseEvent* e= new CgMouseEvent(Cg::CgMouseMove,
                                        glm::vec2(event->localPos().x() ,event->localPos().y()),
                                        (Cg::MouseButtons)event->button());
       notifyObserver(e);
   }



}

void CgQtGui::keyPressEvent(QKeyEvent *event)
{
   CgBaseEvent* e= new CgKeyEvent(Cg::CgKeyPressEvent,(Cg::Key)event->key(),(Cg::KeyboardModifiers)event->nativeModifiers(),event->text().toStdString());
   notifyObserver(e);
}


void CgQtGui::viewportChanged(int w, int h)
{
     CgBaseEvent* e = new CgWindowResizeEvent(Cg::WindowResizeEvent,w,h);
     notifyObserver(e);
}




CgBaseRenderer* CgQtGui::getRenderer()
{
    return m_glRenderWidget;
}





