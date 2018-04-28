#ifndef ESFERA_H
#define ESFERA_H

class Esfera
{
public:
    Esfera();
    ~Esfera();

    void paint();

private:
    float* cor;
    float* centro;
    float raio;
    float angulo;
};

#endif // ESFERA_H
