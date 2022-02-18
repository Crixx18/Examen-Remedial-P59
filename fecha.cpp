#include "fecha.h"

#include <QString>

Fecha::Fecha(const QString &fecha) {
    setFecha(fecha);
}

Fecha::Fecha() {
    setFecha("Fecha no inicializada.");
}

const QString &Fecha::getFecha() const {
    return this->fecha;
};

void Fecha::setFecha(const QString &fecha) {
    this->fecha = fecha;
}
