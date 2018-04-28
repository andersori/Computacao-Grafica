#include "glwidget.h"
#include <QTimer>

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    this->e = new Esfera();
    QTimer* tt = new QTimer();
    connect(tt, SIGNAL(timeout()), this, SLOT(update()));
    tt->start(80);
}

GLWidget::~GLWidget()
{

}

void GLWidget::initializeGL()
{
    glClearColor(0.0, 1.0, 1.0, 1.0);
    glViewport(0.0, 0.0, this->width(), this->height());
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        glOrtho(-this->width()/2.0, this->width()/2.0,
                -this->height()/2.0, this->height()/2.0,
                10, 10);

    glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    e->paint();
    glRotatef(45, 1.0, 1.0, 1.0);
}
