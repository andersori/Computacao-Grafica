#include "desenho.h"
#include <QDebug>

Desenho::Desenho()
{
    this->centro = new float[3];
    this->cor = new float[3];
    this->pos = new float[3];

    this->vivo = true;
    this->deslocacao = 0.1;

    set_cor(0.0, 0.0, 0.0);
    set_pos_x_y(0.0, -1.0);
}

Desenho::~Desenho()
{
    delete this->centro;
    delete this->cor;
    delete this->pos;
}

bool Desenho::colisao(Desenho *d)
{
    float distancia = sqrt(pow((centro[0] - d->get_centro()[0]),2) + pow((centro[1] - d->get_centro()[1]),2));


    if(distancia < (this->raio + d->get_raio()))
    {

        qDebug() << "morreu";
        this->vivo = false;
        return true;
    }
    return false;
}

bool Desenho::is_vivo()
{
    return this->vivo;
}

void Desenho::set_vivo(bool vivo)
{
    this->vivo = vivo;
}

void Desenho::set_cor(float r, float g, float b)
{
    this->cor[0] = r;
    this->cor[1] = g;
    this->cor[2] = b;
}

float *Desenho::get_cor()
{
    return this->cor;
}

float *Desenho::get_centro()
{
    return this->centro;
}

float Desenho::get_raio()
{
    return this->raio;
}

void Desenho::set_raio()
{
    this->raio = sqrt(pow((centro[0] - vertices[0][0]),2) + pow((centro[1] - vertices[0][1]),2));
}

void Desenho::set_pos_x_y(float x, float y)
{
    this->pos[0] = x;
    this->pos[1] = y;
}

void Desenho::set_pos_x(float x)
{
    this->pos[0] = x;
}

void Desenho::set_pos_y(float y)
{
    this->pos[1] = y;
}

void Desenho::mover(Desenho::Direcao dir)
{
    switch (dir) {
    case CIMA :
        this->pos[1] += this->deslocacao;
        this->centro[1] += this->deslocacao;
        break;
    case BAIXO :
        this->pos[1] -= this->deslocacao;
        this->centro[1] -= this->deslocacao;
        break;
    case ESQUERDA :
        this->pos[0] -= this->deslocacao;
        this->centro[0] -= this->deslocacao;
        break;
    case DIREITA :
        this->pos[0] += this->deslocacao;
        this->centro[0] += this->deslocacao;
        break;
    default:
        break;
    }
}
