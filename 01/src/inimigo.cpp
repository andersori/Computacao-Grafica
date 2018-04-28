#include "inimigo.h"
#include <QtOpenGL>

Inimigo::Inimigo()
{
    this->vertices = new float*[4];
    for(int i=0; i < 4;i++)
        this->vertices[i] = new float[3];

    set_vertice_1(-0.08, 0.0, 0.0);
    set_vertice_2(0.08, 0.0, 0.0);
    set_vertice_3(0.08, 0.1, 0.0);
    set_vertice_4(-0.08, 0.1, 0.0);

    set_raio();
}

Inimigo::~Inimigo()
{
    for(int i = 0; i < 6; i++)
    {
        delete vertices[i];
    }
    delete vertices;
}

void Inimigo::paint()
{
    float temp[4][3] = {{vertices[0][0] + pos[0] ,
                         vertices[0][1] + pos[1] ,
                         vertices[0][2] + pos[2] },

                        {vertices[1][0] + pos[0] ,
                         vertices[1][1] + pos[1] ,
                         vertices[1][2] + pos[2] },

                        {vertices[2][0] + pos[0] ,
                         vertices[2][1] + pos[1] ,
                         vertices[2][2] + pos[2] },

                        {vertices[3][0] + pos[0] ,
                         vertices[3][1] + pos[1] ,
                         vertices[3][2] + pos[2] },
                       };

    set_centro(temp);

    glBegin(GL_QUADS);
    glColor3fv(cor);
        glVertex3fv(temp[0]);
        glVertex3fv(temp[1]);
        glVertex3fv(temp[2]);
        glVertex3fv(temp[3]);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3fv(centro);
    glEnd();
    glFlush();

    mover(Desenho::BAIXO);
}

void Inimigo::mover(Desenho::Direcao dir)
{
    Desenho::mover(dir);
    if(this->centro[1] < -1.0)
    {
        this->pos[1] = 1.0;
    }
    if(this->pos[1] > 1.0 && this->centro[1] > 1.0)
    {
        this->pos[1] = -1.0;
    }

    if(this->centro[0] < -1.0)
    {
        this->pos[0] = 1.0;
    }

    if(this->centro[0] > 1.0)
    {
        this->pos[0] = -1.0;
    }
}

void Inimigo::set_vertice_1(float x, float y, float z)
{
    this->vertices[0][0] = x;
    this->vertices[0][1] = y;
    this->vertices[0][2] = z;
}

void Inimigo::set_vertice_2(float x, float y, float z)
{
    this->vertices[1][0] = x;
    this->vertices[1][1] = y;
    this->vertices[1][2] = z;
}

void Inimigo::set_vertice_3(float x, float y, float z)
{
    this->vertices[2][0] = x;
    this->vertices[2][1] = y;
    this->vertices[2][2] = z;
}

void Inimigo::set_vertice_4(float x, float y, float z)
{
    this->vertices[3][0] = x;
    this->vertices[3][1] = y;
    this->vertices[3][2] = z;
}

void Inimigo::set_centro(float temp[4][3])
{
    float x_max = temp[0][0];
    float y_max = temp[0][1];

    float x_min = temp[0][0];
    float y_min = temp[0][1];

    //procurando maiores
    for(int i=0;i<4;i++)
    {
        if (x_max < temp[i][0])
            x_max = temp[i][0];

        if (y_max < temp[i][1])
            y_max = temp[i][1];
    }

    //procurando menores
    for(int i=0;i<4;i++)
    {
        if (x_min > temp[i][0])
            x_min = temp[i][0];

        if (y_min > temp[i][1])
            y_min = temp[i][1];
    }

    this->centro[0] = (x_max + x_min) / 2.0;
    this->centro[1] = (y_max + y_min) / 2.0;
}
