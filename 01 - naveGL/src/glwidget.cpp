#include "glwidget.h"
#include <QTimer>
#include <QDebug>
#include <QDateTime>

GLWidget::GLWidget(QWidget* parent) : QGLWidget(parent)
{
    qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);

    this->nv = new Nave();
    this->setFocus();

    QTimer* tt = new QTimer();
    connect(tt, SIGNAL(timeout()), this, SLOT(update()));
    tt->start(80);

    for(int i = 0; i<3;i++)
        add_novo_inimigo();
}

GLWidget::~GLWidget()
{
    delete this->nv;
}

void GLWidget::keyPressEvent(QKeyEvent *k)
{
    switch(k->key())
    {
        case Qt::Key_Up:
            nv->mover(Desenho::CIMA);
            break;
        case Qt::Key_W:
            nv->mover(Desenho::CIMA);
            break;

        case Qt::Key_Down:
            nv->mover(Desenho::BAIXO);
            break;
        case Qt::Key_S:
            nv->mover(Desenho::BAIXO);
            break;

        case Qt::Key_Left:
            nv->mover(Desenho::ESQUERDA);
            break;
        case Qt::Key_A:
            nv->mover(Desenho::ESQUERDA);
            break;

        case Qt::Key_Right:
            nv->mover(Desenho::DIREITA);
            break;
        case Qt::Key_D:
            nv->mover(Desenho::DIREITA);
            break;

        case Qt::Key_Space:
            if(nv->is_vivo())
            {
                qDebug() << "Atirou";
                balas.append(nv->atirar());
            }
            break;

        default:
            break;
    }
}

void GLWidget::initializeGL()
{
    glViewport(0, 0, this->width(), this->height());
    glClearColor(0.0, 1.0, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-this->width()/2.0, this->width()/2.0,
                -this->height()/2.0, this->height()/2.0,
                10, 10);

    glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    if(nv->is_vivo()){
        nv->paint();

        for(int i = 0; i < inimigos.size(); i++)
        {
            Inimigo* ini = inimigos.at(i);

            if(ini->is_vivo())
            {
                ini->paint();
                nv->colisao(ini);
            }
            else{
                qDebug() << "Um inimigo foi morto";
                inimigos.removeAt(i);
                add_novo_inimigo();
            }
        }
    }

    for(int i = 0; i < balas.size();i++)
    {
        Bala* b = balas.at(i);

        if(b->is_vivo())
        {
            b->paint();
            for(int j = 0; j < inimigos.size(); j++)
            {
                Inimigo* temp = inimigos.at(j);
                if(temp->colisao(b))
                {
                    b->set_vivo(false);
                }
            }
        }
        else{
            qDebug() << "Removeu uma Bala da lista.";
            balas.removeAt(i);
        }

    }

}

void GLWidget::add_novo_inimigo()
{
    int pos_x = qrand()%10;
    Inimigo* ini = new Inimigo();

    if(pos_x%2 == 0)
    {
        float pos = pos_x/10.0;
        ini->set_pos_x_y(pos, 1.0);
    }
    else
    {
        float pos = -(pos_x/10.0);
        ini->set_pos_x_y(pos, 1.0);
    }

    inimigos.append(ini);
}
