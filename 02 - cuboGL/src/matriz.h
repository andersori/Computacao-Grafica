#ifndef MATRIZ_H
#define MATRIZ_H
#include "cubo.h"

class Matriz
{
public:
    Matriz();

    static double** rotacionarX(const double theta);
    static double** rotacionarY(const double theta);
    static double** rotacionarZ(const double theta);

    //Esses metodos alteram uma matriz 4x4
    static double** transladar(double **mat, const double x, const double y, const double z);
    static double** escalar(double** mat, const double x, const double y, const double z);
    static double** multiplicarMatriz(double** mat1, double** mat2);

    //Esses metodos alteram o cubo
    static void transladar(Cubo* c, const double x, const double y, const double z);
    static void escalar(Cubo* c, const double x, const double y, const double z);
    static void multiplicarMatriz(Cubo* c, double** mat2);

    //Esse aqui é pra ser utilizado ao fim das operações em matrizes 4x4
    static void setarValores(Cubo* c, double** matIdentidade);

    //Cria uma matriz 4x4
    static double** criarMatriz();

    //Desaloca memoria da função acima
    static void desalocarMatriz(double** mat);

    //Esses funciona
    static void mult_matriz_novo(double*, double**);
};

#endif // MATRIZ_H
