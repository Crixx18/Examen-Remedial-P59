#ifndef TAREAS_VENTANA_H
#define TAREAS_VENTANA_H

#include <QMainWindow>
#include <QFile>
#include <QDebug>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Tareas; }
QT_END_NAMESPACE

class Tareas : public QMainWindow
{
    Q_OBJECT

public:
    Tareas(QWidget *parent = nullptr);
    ~Tareas();
    void updateUI();

private slots:
    void on_actionAgregar_triggered();
    void on_actionEliminar_triggered();
    void on_actionModificar_triggered();
    void on_actionSalir_triggered();

private:
    Ui::Tareas *ui;
    void clean();
};

#endif // LOGIN_H
