#ifndef TAREA_A_UI_H
#define TAREA_A_UI_H

#include "tarea.h"
#include "tareas_ventana.h"

#include <QTableWidgetItem>

#include <iostream>

class TareaAUI
{
public:
    TareaAUI(Ui::Tareas ui, int indice, Tarea tarea);

private:
    QTableWidgetItem *buildItem(std::string data);

};

#endif // TAREA_A_UI_H
