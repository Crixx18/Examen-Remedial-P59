#ifndef TAREAS_VENTANA_H
#define TAREAS_VENTANA_H

#include <QMainWindow>
#include <QFile>
#include <QDebug>
#include <QMessageBox>
#include <QTableWidgetItem>

#include <tarea.h>

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
    void pasarTareaAlUI(int indice, Tarea *tarea);
    QTableWidgetItem *buildItem(std::string data);
    QList<Tarea*> tareas;

private slots:
    void on_actionAgregar_triggered();
    void on_actionFinalizar_triggered();
    void on_actionSalir_triggered();

private:
    Ui::Tareas *ui;
};

#endif // LOGIN_H
