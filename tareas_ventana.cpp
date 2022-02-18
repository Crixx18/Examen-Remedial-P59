#include "tareas_ventana.h"
#include "ui_tareas_ventana.h"
#include <iostream>
#include "tarea.h"
#include "agregar_tarea.h"

using namespace std;

Tareas::Tareas(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Tareas) {
    ui->setupUi(this);
}

Tareas::~Tareas() {
    delete ui;
}

void Tareas::updateUI() {
    cout << "[DEBUG] Actualizando UI" << endl;

    ui->tareas->clearContents();
    ui->tareas->setRowCount(tareas.size());

    if (tareas.size() > 0) {
        for (int i = 0; i<tareas.size(); i++) {
            pasarTareaAlUI(i, tareas.at(i));
        }
    }
}

void Tareas::pasarTareaAlUI(int indice, Tarea *tarea) {
    if (tarea->getPrioridad() == 'A') {
        this->ui->tareas->setItem(indice, 0, buildItem("Alta"));
    }
    if (tarea->getPrioridad() == 'M') {
        this->ui->tareas->setItem(indice, 0, buildItem("Mediana"));
    }
    if (tarea->getPrioridad() == 'B') {
        this->ui->tareas->setItem(indice, 0, buildItem("Baja"));
    }
    this->ui->tareas->setItem(indice, 1, buildItem(std::to_string(tarea->getIndice())));
    this->ui->tareas->setItem(indice, 2, buildItem(tarea->getNombre().toStdString()));
    this->ui->tareas->setItem(indice, 3, buildItem(tarea->getTipo().toStdString()));
    this->ui->tareas->setItem(indice, 4, buildItem(tarea->getFecha().getFecha().toStdString()));
}
QTableWidgetItem *Tareas::buildItem(std::string data) {
    QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(data));
    item->setFlags(item->flags() & Qt::ItemIsEditable);
    return item;
}


void Tareas::on_actionAgregar_triggered() {
    cout << "[DEBUG] Agregar tarea ha sido presionado xd" << endl;
    AgregarTarea agregarTarea(this);
    agregarTarea.exec();

    updateUI();
}
void Tareas::on_actionEliminar_triggered() {
    updateUI();
    cout << "[DEBUG] Eliminar tarea ha sido presionado xd" << endl;
}
void Tareas::on_actionModificar_triggered() {
    updateUI();
    cout << "[DEBUG] Agregar tarea ha sido presionado xd" << endl;
}
void Tareas::on_actionSalir_triggered() {
    cout << "[DEBUG] Me fui" << endl;
    this->close();
}
