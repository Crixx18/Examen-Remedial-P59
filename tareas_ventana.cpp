#include "tareas_ventana.h"
#include "ui_tareas_ventana.h"
#include <iostream>
#include "tarea.h"
#include "agregar_tarea.h"

#include <QMessageBox>

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
    int tamanio = 0;

    if (tareas.size() > 0) {
        for (int i = 0; i<tareas.size(); i++) {
            cout << "Tarea: "<<tareas.at(i)->getNombre().toStdString()<< endl;
            if (!tareas.at(i)->getTerminada()) {
                tamanio++;
            }
        }
    }
    ui->tareas->setRowCount(tamanio);
    if (tareas.size() > 0) {
        int columna = 0;
        for (int i = 0; i<tareas.size(); i++) {
            if (!tareas.at(i)->getTerminada()) {
                pasarTareaAlUI(columna, tareas.at(i));
                columna++;
            }
        }
    }
}

void Tareas::pasarTareaAlUI(int indice, Tarea *tarea) {
    QColor blanco(255, 255, 255);
    if (tarea->getPrioridad() == 'A') {
        this->ui->tareas->setItem(indice, 0, buildItem(""));
        QColor color(255, 0, 0);
        this->ui->tareas->item(indice, 0)->setBackgroundColor(color);
    }
    if (tarea->getPrioridad() == 'M') {
        this->ui->tareas->setItem(indice, 0, buildItem(""));
        QColor color(255, 183, 0);
        this->ui->tareas->item(indice, 0)->setBackgroundColor(color);
    }
    if (tarea->getPrioridad() == 'B') {
        this->ui->tareas->setItem(indice, 0, buildItem(""));
        QColor color(246, 255, 0);
        this->ui->tareas->item(indice, 0)->setBackgroundColor(color);
    }
    this->ui->tareas->item(indice, 0)->setTextColor(blanco);
    this->ui->tareas->setItem(indice, 1, buildItem(std::to_string(tarea->getIndice())));
    this->ui->tareas->setItem(indice, 2, buildItem(tarea->getNombre().toStdString()));
    this->ui->tareas->setItem(indice, 3, buildItem(tarea->getTipo().toStdString()));
    this->ui->tareas->setItem(indice, 4, buildItem(tarea->getFecha().getFecha().toStdString()));
}

QTableWidgetItem *Tareas::buildItem(std::string data) {
    QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(data));
    //item->setFlags(item->flags() & Qt::ItemIsEditable & Qt::ItemIsSelectable);
    return item;
}

void Tareas::on_actionAgregar_triggered() {
    cout << "[DEBUG] Agregar tarea ha sido presionado xd" << endl;
    AgregarTarea agregarTarea(this);
    agregarTarea.exec();

    updateUI();
}
void Tareas::on_actionFinalizar_triggered() {
    cout << "[DEBUG] Finalizar tarea ha sido presionado xd" << endl;

    if (ui->tareas->selectedItems().isEmpty()) {
        QMessageBox messageBox;
        messageBox.critical(0, "Error", "No tienes ningún ítem seleccionado.");
        messageBox.setFixedSize(500, 200);
        return;
    }

    int row = ui->tareas->currentRow();
    string indice_string = ui->tareas->item(row, 1)->text().toStdString();
    int indice = stoi(indice_string);
    cout << "La columna de la row " << row << " es " << indice_string << endl;
    tareas.at(indice-1)->setTerminada(true);
    updateUI();
}
void Tareas::on_actionSalir_triggered() {
    cout << "[DEBUG] Me fui" << endl;
    this->close();
}
