#include "glwidget.h"
#include <QTimer>
#include <GL/glu.h>
#include "matriz.h"
#include <QDebug>

GLWidget::GLWidget(QWidget* parent) : QGLWidget(parent)
{
    this->setFocus();
    c = new Cubo();

    QTimer* tt = new QTimer();
    connect(tt, SIGNAL(timeout()), this, SLOT(update()));
    tt->start(80);

    this->cont = 9;
}

GLWidget::~GLWidget()
{
    delete c;
}

void GLWidget::initializeGL()
{
    glClearColor(0.0, 1.0, 1.0, 1.0);
    glViewport(0, 0, this->width(), this->height());
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        gluPerspective(45, this->width()/this->height(), 0.001, 100);

    glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

    gluLookAt(0,0,cont, 0,0,0, 1,1,0);

}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    c->paint();
}

void GLWidget::girar(double angulo_x, double angulo_y, double angulo_z)
{
    Matriz::rotacionar_x(c, angulo_x);
    Matriz::rotacionar_y(c, angulo_y);
    Matriz::rotacionar_z(c, angulo_z);
}

void GLWidget::keyPressEvent(QKeyEvent *k)
{
    switch(k->key())
    {
    case Qt::Key_Up:
        gluLookAt(0,0,cont++, 0,0,0, 0,1,0);
        break;

    case Qt::Key_Down:
        gluLookAt(0,0,cont--, 0,0,0, 0,1,0);
        break;

    case Qt::Key_Space:
        gluLookAt(0,0,cont--, 0,0,0, 0,1,1);
        break;

    default:
        break;
    }
}
