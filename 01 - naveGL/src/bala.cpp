#include "bala.h"
#include <QtOpenGL>
#include <QDebug>

Bala::Bala()
{
    this->vertices = new float*[1];
    this->vertices[0] = new float[1];

    this->vertices[0][0] = 0.0;
    this->vertices[0][1] = 0.0;
    this->vertices[0][2] = 0.0;

    this->deslocacao = 0.06;
    set_tamanho(5);
}

Bala::~Bala()
{
    delete this->vertices[0];
    delete this->vertices;
}

void Bala::paint()
{
    float temp[1][3] = {{
                            vertices[0][0] + pos[0],
                            vertices[0][1] + pos[1],
                            vertices[0][2] + pos[2]
                        }};

    set_centro(temp);

    if(temp[0][1] > 1.0)
    {
        this->vivo = false;
    }
    else
    {
        glPointSize(this->tam);
        glBegin(GL_POINTS);
            glColor3fv(cor);
            glVertex3fv(temp[0]);
        glEnd();
        glFlush();

        mover(Desenho::CIMA);
    }
}

void Bala::mover(Desenho::Direcao dir)
{
    Desenho::mover(dir);
}

void Bala::set_centro(float temp[1][3])
{
    this->centro[0] = temp[0][0];
    this->centro[1] = temp[0][1];
    this->centro[2] = temp[0][2];
}

void Bala::set_tamanho(unsigned int tam)
{
    this->tam = tam;
    this->raio = tam / 100.0;
}
