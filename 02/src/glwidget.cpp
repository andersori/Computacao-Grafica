#include "glwidget.h"
#include <QTimer>
#include "matriz.h"

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    this->cub = new Cubo();

    QTimer* tt = new QTimer();
    connect(tt, SIGNAL(timeout()), this, SLOT(update()));
    tt->start(80);
}

GLWidget::~GLWidget()
{
    delete this->cub;
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

    glMatrixMode(GL_VIEWPORT);
        glLoadIdentity();
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    cub->paint();
}

void GLWidget::girar_open_gl(double anguloX, double anguloY, double anguloZ)
{
    glRotated(anguloX, 1.0, 0.0, 0.0);
    glRotated(anguloY, 0.0, 1.0, 0.0);
    glRotated(anguloZ, 0.0, 0.0, 1.0);
}

void GLWidget::girar_propria(double anguloX, double anguloY, double anguloZ)
{
    for(int i = 0; i < 8; i++)
    {
        Matriz::mult_matriz_novo(cub->vertices[i], Matriz::rotacionarX(anguloX));
        Matriz::mult_matriz_novo(cub->vertices[i], Matriz::rotacionarY(anguloY));
        Matriz::mult_matriz_novo(cub->vertices[i], Matriz::rotacionarZ(anguloZ));
    }
}
