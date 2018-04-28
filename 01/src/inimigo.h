#ifndef INIMIGO_H
#define INIMIGO_H
#include "desenho.h"

class Inimigo : public Desenho
{
public:
    explicit Inimigo();
    ~Inimigo();

    void paint();
    void mover(Direcao);

private:
    void set_centro(float[4][3]);

    void set_vertice_1(float, float, float);
    void set_vertice_2(float, float, float);
    void set_vertice_3(float, float, float);
    void set_vertice_4(float, float, float);
};

#endif // INIMIGO_H
