#ifndef BALA_H
#define BALA_H
#include "desenho.h"

class Bala : public Desenho
{
public:
    explicit Bala();
    ~Bala();

    void paint();
    void mover(Direcao);

private:
    void set_centro(float[1][3]);
    void set_tamanho(unsigned int);

    int tam;
};

#endif // BALA_H
