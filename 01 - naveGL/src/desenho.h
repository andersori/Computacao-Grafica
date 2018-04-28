#ifndef DESENHO_H
#define DESENHO_H

class Desenho
{
public:
    enum Direcao{
        CIMA,
        BAIXO,
        ESQUERDA,
        DIREITA
    };

    explicit Desenho();
    virtual ~Desenho();

    virtual void paint() = 0;//Classes filhas devem implementar
    virtual void mover(Direcao);//Podem ser redefinidas pelas filhas

    bool colisao(Desenho*);
    bool is_vivo();

    void set_vivo(bool);
    void set_cor(float, float, float);

    float* get_cor();
    float* get_centro();
    float get_raio();

    void set_pos_x_y(float, float);
    void set_pos_x(float);
    void set_pos_y(float);

protected:
    //virtual void set_centro(float*[3]) = 0;//Classes filhas devem implementar

    void set_raio();

    float* centro;
    float** vertices;
    float* cor;
    float* pos;

    bool vivo;
    float deslocacao;
    float raio;
};

#endif // DESENHO_H
