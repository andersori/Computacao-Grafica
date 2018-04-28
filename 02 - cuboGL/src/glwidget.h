#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include "cubo.h"

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    explicit GLWidget(QWidget *parent = 0);
    ~GLWidget();

    void initializeGL();
    void paintGL();

    void girar_open_gl(double, double, double);
    void girar_propria(double, double, double);

private:
    Cubo* cub;

};

#endif // GLWIDGET_H
