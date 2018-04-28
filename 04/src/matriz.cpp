#include "matriz.h"
#include <qmath.h>

Matriz::Matriz()
{
}

void Matriz::rotacionar_x(Cubo *c, const double theta)
{
    double** mat = Matriz::criar_matriz();
    double angle = M_PI/180.0*theta;

    mat[0][0] = mat[3][3] = 1.0;
    mat[1][1] = mat[2][2] = cos(angle);
    mat[2][1] = sin(angle);
    mat[1][2] = -mat[2][1];

    for(int i = 0; i < 8; i++)
    {
        Matriz::multiplicar_matriz(c->vertices[i], mat);
    }

    desalocar_matriz(mat);
}

void Matriz::rotacionar_y(Cubo *c, const double theta)
{
    double** mat = Matriz::criar_matriz();
    double angle = M_PI/180.0*theta;

    mat[1][1] = mat[3][3] = 1.0;
    mat[0][0] = mat[2][2] = cos(angle);
    mat[0][2] = sin(angle);
    mat[2][0] = -mat[0][2];

    for(int i = 0; i < 8; i++)
    {
        Matriz::multiplicar_matriz(c->vertices[i], mat);
    }

    desalocar_matriz(mat);
}

void Matriz::rotacionar_z(Cubo *c, const double theta)
{
    double** mat = Matriz::criar_matriz();
    double angle = M_PI/180.0*theta;

    mat[2][2] = mat[3][3] = 1.0;
    mat[0][0] = mat[1][1] = cos(angle);
    mat[1][0] = sin(angle);
    mat[0][1] = -mat[1][0];

    for(int i = 0; i < 8; i++)
    {
        Matriz::multiplicar_matriz(c->vertices[i], mat);
    }

    desalocar_matriz(mat);
}

void Matriz::multiplicar_matriz(double *cubo, double **mm)
{
    //A variavel "cubo" representa somente uma vertice do cubo

    double x = cubo[0];
    double y = cubo[1];
    double z = cubo[2];

    cubo[0] = (x * mm[0][0]) + (y * mm[1][0]) + (z*mm[2][0]);
    cubo[1] = (x * mm[0][1]) + (y * mm[1][1]) + (z*mm[2][1]);
    cubo[2] = (x * mm[0][2]) + (y * mm[1][2]) + (z*mm[2][2]);
}

double **Matriz::criar_matriz()
{
    double** mat = new double*[4];
    for(int i=0;i<4;i++)
        mat[i] = new double[4];

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            mat[i][j] = 0;

    return mat;
}

void Matriz::desalocar_matriz(double **mat)
{
    for(int i=0;i<4;i++)
        delete mat[i];
    delete mat;
}
