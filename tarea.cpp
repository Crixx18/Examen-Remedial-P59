#include "tarea.h"

#include <QString>

Tarea::Tarea(int indice, const QString &nombre, const Fecha fecha, char prioridad, const QString &tipo) {
    this->indice = indice;
    this->nombre = nombre;
    this->fecha = fecha;
    this->prioridad = prioridad;
    this->tipo = tipo;
    this->terminada = false;
}

int Tarea::getIndice() const {
    return indice;
}

const QString &Tarea::getNombre() const {
    return nombre;
}

const Fecha &Tarea::getFecha() const {
    return fecha;
}

char Tarea::getPrioridad() const {
    return prioridad;
}

const QString &Tarea::getTipo() const {
    return tipo;
}

bool Tarea::getTerminada() const {
    return terminada;
}

void Tarea::setIndice(int indice) {
    this->indice = indice;
}

void Tarea::setNombre(const QString &nombre) {
    this->nombre = nombre;
}

void Tarea::setFecha(const Fecha &fecha) {
    this->fecha = fecha;
}

void Tarea::setPrioridad(char prioridad) {
    this->prioridad = prioridad;
}

void Tarea::setTipo(const QString &tipo) {
    this->tipo = tipo;
}

void Tarea::setTerminada(bool terminada) {
    this->terminada = terminada;
}
