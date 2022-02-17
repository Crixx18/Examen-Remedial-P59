#include "tareas_ventana.h"
#include "ui_tareas_ventana.h"
#include <iostream>

using namespace std;

Tareas::Tareas(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Tareas)
{
    ui->setupUi(this);
}

Tareas::~Tareas()
{
    delete ui;
}

void Tareas::updateUI() {
    cout << "[DEBUG] Actualizando UI" << endl;

    ui->tareas->clearContents();

    ui ->tareas->setRowCount(50);
    for (int i = 0; i < 50; i++) {
        string stringinized = to_string(i+1);

        string a = "test a ";
        a += stringinized;
        string b = "test b ";
        b += stringinized;
        string c = "test c ";
        c += stringinized;
        string d = "test d ";
        d += stringinized;
        string e = "test e ";
        e += stringinized;

        ui->tareas->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(a)));
        ui->tareas->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(b)));
        ui->tareas->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(c)));
        ui->tareas->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(d)));
        ui->tareas->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(e)));
    }
}

void Tareas::on_actionAgregar_triggered() {
    updateUI();
    cout << "[DEBUG] Agregar tarea ha sido presionado xd" << endl;
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
