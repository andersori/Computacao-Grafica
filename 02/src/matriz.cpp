#include "matriz.h"
#include <qmath.h>
#include <QDebug>

Matriz::Matriz()
{

}

double **Matriz::rotacionarX(const double theta)
{
    double** c = Matriz::criarMatriz();
    double s = M_PI/180.0*theta;

    c[0][0] = c[3][3] = 1.0;
    c[1][1] = c[2][2] = cos(s);
    c[2][1] = sin(s);
    c[1][2] = -c[2][1];

    return c;
}

double **Matriz::rotacionarY(const double theta)
{
    double** c = Matriz::criarMatriz();
    double s = M_PI/180.0*theta;

    c[1][1] = c[3][3] = 1.0;
    c[0][0] = c[2][2] = cos(s);
    c[0][2] = sin(s);
    c[2][0] = -c[0][2];

    return c;
}

double **Matriz::rotacionarZ(const double theta)
{
    double** c = Matriz::criarMatriz();
    double s = M_PI/180.0*theta;

    c[2][2] = c[3][3] = 1.0;
    c[0][0] = c[1][1] = cos(s);
    c[1][0] = sin(s);
    c[0][1] = -c[1][0];

    return c;
}

double **Matriz::transladar(double** mat, const double x, const double y, const double z)
{
    mat[0][0] += x;
    mat[1][0] += x;
    mat[2][0] += x;
    mat[3][0] += x;

    mat[0][1] += y;
    mat[1][1] += y;
    mat[2][1] += y;
    mat[3][1] += y;

    mat[0][2] += z;
    mat[1][2] += z;
    mat[2][2] += z;
    mat[3][2] += z;

    qDebug() << "Transladar: ok";
    return mat;
}

double **Matriz::escalar(double **mat, const double x, const double y, const double z)
{

    mat[0][0] *= x;
    mat[1][0] *= x;
    mat[2][0] *= x;
    mat[3][0] *= x;

    mat[0][1] *= y;
    mat[1][1] *= y;
    mat[2][1] *= y;
    mat[3][1] *= y;

    mat[0][2] *= z;
    mat[1][2] *= z;
    mat[2][2] *= z;
    mat[3][2] *= z;

    qDebug() << "Escalar: ok";
    return mat;
}

double** Matriz::multiplicarMatriz(double **mat1, double **mat2)
{
    double** mat3 = Matriz::criarMatriz();
    int M1L=4, M2C=4;
    for(int linha=0; linha<M1L; linha++)
    {
        for(int coluna=0; coluna<M2C; coluna++)
        {
          double somaprod=0;

          for(int i=0; i<M1L; i++){
              somaprod+=mat1[linha][i]*mat2[i][coluna];
          }

          mat3[linha][coluna]=somaprod;
        }
    }
    qDebug() << "Multiplicação de matriz: ok";
    return mat3;
}

void Matriz::setarValores(Cubo *c, double **matIdentidade)
{
    qDebug() << "Entrei em Setar valores";
    int M1L=8, M2C=4;
    for(int linha=0; linha<M1L; linha++)
    {
        for(int coluna=0; coluna<M2C; coluna++)
        {
          double somaprod=0;

          for(int i=0; i<M2C; i++){
              somaprod+=c->vertices[linha][i]*matIdentidade[i][coluna];
          }

          c->vertices[linha][coluna]=somaprod;
        }
    }
    qDebug() << "Setar valores: ok";
}

double **Matriz::criarMatriz()
{
    double** mat = new double*[4];
    for(int i=0;i<4;i++)
        mat[i] = new double[4];

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            mat[i][j] = 0;

    return mat;
}

void Matriz::desalocarMatriz(double **mat)
{
    for(int i=0;i<4;i++)
        delete mat[i];
    delete mat;
}


void Matriz::transladar(Cubo *c, const double x, const double y, const double z)
{
    //escalar(c,x,y,z);
    for(int i=0;i<8;i++)
    {
        c->vertices[i][0] += x;
        c->vertices[i][1] += y;
        c->vertices[i][2] += z;
    }
}

void Matriz::escalar(Cubo *c, const double x, const double y, const double z)
{
    for(int i=0;i<8;i++)
    {
        c->vertices[i][0] *= x;
        c->vertices[i][1] *= y;
        c->vertices[i][2] *= z;
    }
}

void Matriz::multiplicarMatriz(Cubo *c, double **mat2)
{
    int M1L=8, M2C=4;
    for(int linha=0; linha<M1L; linha++)
    {
        for(int coluna=0; coluna<M2C; coluna++)
        {
          double somaprod=0;

          for(int i=0; i<M2C; i++){
              somaprod+=c->vertices[linha][i]*mat2[i][coluna];
          }

          c->vertices[linha][coluna]=somaprod;
        }
    }
    Matriz::desalocarMatriz(mat2);
}


void Matriz::mult_matriz_novo(double * cubo, double **mm)
{
    double x = cubo[0];
    double y = cubo[1];
    double z = cubo[2];

    cubo[0] = (x * mm[0][0]) + (y * mm[1][0]) + (z*mm[2][0]);
    cubo[1] = (x * mm[0][1]) + (y * mm[1][1]) + (z*mm[2][1]);
    cubo[2] = (x * mm[0][2]) + (y * mm[1][2]) + (z*mm[2][2]);

    Matriz::desalocarMatriz(mm);
}
