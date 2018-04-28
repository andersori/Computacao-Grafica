#include "cubo.h"
#include <QDebug>

#define VERMELHO 1.0, 0.0, 0.0
#define VERDE 0.0, 1.0, 0.0
#define AZUL 0.0, 0.0, 1.0
#define AMARELO 1.0, 1.0, 0.0
#define MARROM 0.0, 0.5, 0.5
#define ROSA 1.0,0.5,0.5

Cubo::Cubo()
{
    this->vertices=new double*[8];
    for(int i=0;i<8;i++){
        this->vertices[i]=new double[4];
    }

    vertices[0][0]=-0.5;
    vertices[0][1]=0.5;
    vertices[0][2]=-0.5;
    vertices[0][3]=1.0;

    vertices[1][0]=-0.5;
    vertices[1][1]=-0.5;
    vertices[1][2]=-0.5;
    vertices[1][3]=1.0;

    vertices[2][0]=0.5;
    vertices[2][1]=-0.5;
    vertices[2][2]=-0.5;
    vertices[2][3]=1.0;

    vertices[3][0]=0.5;
    vertices[3][1]=0.5;
    vertices[3][2]=-0.5;
    vertices[3][3]=1.0;

    vertices[4][0]=0.5;
    vertices[4][1]=-0.5;
    vertices[4][2]=0.5;
    vertices[4][3]=1.0;

    vertices[5][0]=0.5;
    vertices[5][1]=0.5;
    vertices[5][2]=0.5;
    vertices[5][3]=1.0;

    vertices[6][0]=-0.5;
    vertices[6][1]=0.5;
    vertices[6][2]=0.5;
    vertices[6][3]=1.0;

    vertices[7][0]=-0.5;
    vertices[7][1]=-0.5;
    vertices[7][2]=0.5;
    vertices[7][3]=1.0;

    Quadrado *face1 = new Quadrado("Frente");
    face1->setCor(VERMELHO);
    face1->setVertices(vertices[0],vertices[1],vertices[2],vertices[3]);

    Quadrado *face2 = new Quadrado("Lateral Direita");
    face2->setCor(VERDE);
    face2->setVertices(vertices[2],vertices[4],vertices[5],vertices[3]);

    Quadrado *face3 = new Quadrado("Atraz");
    face3->setCor(AZUL);
    face3->setVertices(vertices[5],vertices[4],vertices[7],vertices[6]);

    Quadrado *face4 = new Quadrado("Lateral Esquerda");
    face4->setCor(AMARELO);
    face4->setVertices(vertices[7],vertices[1],vertices[0],vertices[6]);

    Quadrado *face5 = new Quadrado("Baixo");
    face5->setCor(MARROM);
    face5->setVertices(vertices[0],vertices[3],vertices[5],vertices[6]);

    Quadrado *face6 = new Quadrado("Cima");
    face6->setCor(ROSA);
    face6->setVertices(vertices[7],vertices[4],vertices[2],vertices[1]);

    this->faces.append(face1);
    this->faces.append(face2);
    this->faces.append(face3);
    this->faces.append(face4);
    this->faces.append(face5);
    this->faces.append(face6);

}

Cubo::~Cubo()
{
    for(int i=0;i<8;i++){
        delete vertices[i];
    }

    delete vertices;
}

void Cubo::paint()
{
    for(int i = 0; i<faces.size();i++)
    {
        Quadrado* q = faces.at(i);
        q->paint();
    }
}
