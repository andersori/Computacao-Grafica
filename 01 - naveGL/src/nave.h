#ifndef NAVE_H
#define NAVE_H
#include "desenho.h"
#include "bala.h"

class Nave : public Desenho
{
public:
    explicit Nave();
    ~Nave();

    void paint();
    void mover(Direcao);
    Bala* atirar();

private:
    void set_vertice_1(float, float, float);
    void set_vertice_2(float, float, float);
    void set_vertice_3(float, float, float);
    void set_vertice_4(float, float, float);

    void set_centro(float[4][3]);
};

#endif // NAVE_H
