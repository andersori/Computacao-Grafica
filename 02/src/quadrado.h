#ifndef QUADRADO_H
#define QUADRADO_H

class Quadrado
{
public:
    Quadrado();
    Quadrado(const char* descricao);
    virtual ~Quadrado();

    const char* getDescricao();

    float *getCor() const;
    void setCor(float r, float g, float b);
    void paint();

    void setVertices(double *, double *, double *, double *);

    void setVertices(int vertice_i, double x, double y, double z);

private:
    double** vertices;
    float* cor;

    const char* descricao;
};

#endif // QUADRADO_H
