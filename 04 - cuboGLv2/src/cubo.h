#ifndef CUBO_H
#define CUBO_H
#include <QList>
#include "quadrado.h"

class Cubo
{
public:
    Cubo();
    ~Cubo();

    void paint();

    double** vertices;

private:
    QList<Quadrado*> faces;
};

#endif // CUBO_H
