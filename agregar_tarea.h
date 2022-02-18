#ifndef AGREGAR_TAREA_H
#define AGREGAR_TAREA_H

#include <QMainWindow>
#include <QFile>
#include <QDebug>
#include <QMessageBox>
#include <QTableWidgetItem>

#include <tarea.h>
#include <tareas_ventana.h>

QT_BEGIN_NAMESPACE
namespace Ui { class AgregarTarea; }
QT_END_NAMESPACE

class AgregarTarea : public QDialog
{
    Q_OBJECT

public:
    AgregarTarea(Tareas *tareas = nullptr);
    ~AgregarTarea();

private slots:
    void on_actionAgregar_released();
    void on_actionCancelar_released();
private:
    Ui::AgregarTarea *ui;
    Tareas *tareas;
};

#endif // LOGIN_H
