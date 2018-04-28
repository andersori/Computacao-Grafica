#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QGLWidget>
#include <QKeyEvent>

#include "cubo.h"

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    explicit GLWidget(QWidget* parent = 0);
    ~GLWidget();

    void initializeGL();
    void paintGL();

    void girar(double, double, double);

private:
    void keyPressEvent(QKeyEvent*);

    Cubo* c;
    int cont;
};

#endif // GLWIDGET_H
