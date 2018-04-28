#ifndef MATRIZ_H
#define MATRIZ_H
#include "cubo.h"

class Matriz
{
public:
    Matriz();

    static void rotacionar_x(Cubo* c, const double theta);
    static void rotacionar_y(Cubo* c, const double theta);
    static void rotacionar_z(Cubo* c, const double theta);

private:
    static void multiplicar_matriz(double* cubo, double** mm);

    static double** criar_matriz();
    static void desalocar_matriz(double** mat);
};

#endif // MATRIZ_H
