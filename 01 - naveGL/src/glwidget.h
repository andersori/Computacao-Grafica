#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QKeyEvent>
#include <QList>

#include "desenho.h"
#include "nave.h"
#include "bala.h"
#include "inimigo.h"

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    explicit GLWidget(QWidget* parent = 0);
    ~GLWidget();

    void keyPressEvent(QKeyEvent*);

    void initializeGL();
    void paintGL();

private:
    void add_novo_inimigo();

    Nave* nv;
    QList<Bala*> balas;
    QList<Inimigo*> inimigos;
};

#endif // GLWIDGET_H
