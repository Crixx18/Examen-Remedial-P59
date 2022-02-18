#include "tareas_ventana.h"
#include "ui_agregar_tarea.h"
#include <iostream>
#include "tarea.h"
#include "agregar_tarea.h"
#include <QMessageBox>

using namespace std;

AgregarTarea::AgregarTarea(Tareas *tareas)
    : QDialog(tareas)
    , ui(new Ui::AgregarTarea) {
    ui->setupUi(this);
    this->tareas = tareas;
}

AgregarTarea::~AgregarTarea() {
    delete ui;
}


void AgregarTarea::on_actionAgregar_released() {
    string nombre_tarea =  ui->nombre->toPlainText().toStdString();
    string tipo_de_tarea =  ui->tipo->toPlainText().toStdString();
    if (nombre_tarea.length() > 80) {
        QMessageBox messageBox;
        messageBox.critical(0, "Error", "La tarea no puede tener más de 80 caracteres.");
        messageBox.setFixedSize(500, 200);
        return;
    }
    if (nombre_tarea.length() < 1) {
        QMessageBox messageBox;
        messageBox.critical(0, "Error", "La tarea debe tener al menos 1 caracter.");
        messageBox.setFixedSize(500, 200);
        return;
    }
    if (tipo_de_tarea.length() > 32) {
        QMessageBox messageBox;
        messageBox.critical(0, "Error", "El tipo no puede tener más de 32 caracteres.");
        messageBox.setFixedSize(500, 200);
        return;
    }
    if (tipo_de_tarea.length() < 1) {
        QMessageBox messageBox;
        messageBox.critical(0, "Error", "El tipo debe tener al menos 1 caracter.");
        messageBox.setFixedSize(500, 200);
        return;
    }
    if (ui->calendario->selectedDate().isNull() || !ui->calendario->selectedDate().isValid()) {
        QMessageBox messageBox;
        messageBox.critical(0, "Error", "Debes seleccionar una fecha válida.");
        messageBox.setFixedSize(500, 200);
    }
    cout << ui->calendario->selectedDate().toString("dd/MM/yyyy").toStdString() << endl;

    Fecha fecha(ui->calendario->selectedDate().toString("dd/MM/yyyy"));

    string prioridad_string = ui->prioridad->currentIndex().data(Qt::DisplayRole).toString().toStdString();
    char prioridad = 'A';
    if (prioridad_string == "Alta") {
        prioridad = 'A';
    } else if (prioridad_string == "Baja") {
        prioridad = 'B';
    } else {
        prioridad = 'M';
    }

    Tarea *tarea = new Tarea(tareas->tareas.size()+1, ui->nombre->toPlainText(), fecha, prioridad, ui->tipo->toPlainText());
    tareas->tareas.append(tarea);

    on_actionCancelar_released();
}

void AgregarTarea::on_actionCancelar_released() {
    cout << "[DEBUG] Cerrando ventana" << endl;
    this->close();
}
