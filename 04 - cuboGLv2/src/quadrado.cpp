#include "quadrado.h"
#include <QtOpenGL>

Quadrado::Quadrado()
{
    this->cor = new float[3];
    this->vertices = new double*[4];
    for(int i=0;i<4;i++){
        this->vertices[i]=new double [4];
    }

    this->descricao = "";
}

Quadrado::Quadrado(const char *descricao) : Quadrado()
{
    this->descricao = descricao;
}

Quadrado::~Quadrado()
{
    delete cor;

    for(int j=0;j<4;j++){
        delete vertices[j];
    }
    delete vertices;
}

const char *Quadrado::getDescricao()
{
    return this->descricao;
}

float *Quadrado::getCor() const
{
    return cor;
}

void Quadrado::setCor(float r,float g,float b)
{
    cor[0]=r;
    cor[1]=g;
    cor[2]=b;
}

void Quadrado::paint()
{
    glBegin(GL_QUADS);
    glColor3fv(cor);
    glVertex4dv(vertices[0]);
    glVertex4dv(vertices[1]);
    glVertex4dv(vertices[2]);
    glVertex4dv(vertices[3]);
    glEnd();
    glFlush();
}

void Quadrado::setVertices(double *a, double *b, double *c, double *d)
{
    this->vertices[0]=a;
    this->vertices[1]=b;
    this->vertices[2]=c;
    this->vertices[3]=d;
}

void Quadrado::setVertices(int vertice_i, double x, double y, double z)
{
    if(vertice_i<4){
        this->vertices[vertice_i][0] = x;
        this->vertices[vertice_i][1] = y;
        this->vertices[vertice_i][2] += z;
    }
}

