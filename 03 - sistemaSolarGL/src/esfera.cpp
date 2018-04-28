#include "esfera.h"
#include <QtOpenGL>
#include <qmath.h>

Esfera::Esfera()
{
    this->cor = new float[3];
    this->cor[0] = 0.0;
    this->cor[1] = 0.0;
    this->cor[2] = 0.0;

    this->centro = new float[3];
    this->centro[0] = 0.0;
    this->centro[1] = 0.0;
    this->centro[2] = 0.0;

    this->angulo = 0.0;
    this->raio = 0.5;
}

Esfera::~Esfera()
{
    delete this->centro;
}

void Esfera::paint()
{
    glPointSize(1);
    glBegin(GL_POINTS);
        glColor3fv(this->cor);
        for(float y_temp = this->raio; y_temp > -this->raio; y_temp-= 0.02)
        {
            for(float ang = 0; ang < 360; ang++)
            {
                float aux = sqrt(pow(raio, 2.0) - pow(y_temp, 2.0));

                float x = aux * cos(ang);
                float z = aux * sin(ang);

                glVertex3f(x, y_temp, z);
            }
        }
    glEnd();
    glFlush();
}


