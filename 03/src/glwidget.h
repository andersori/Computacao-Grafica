#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include "esfera.h"

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    explicit GLWidget(QWidget *parent = 0);
    ~GLWidget();

    void initializeGL();
    void paintGL();

private:
    Esfera* e;
};

#endif // GLWIDGET_H
