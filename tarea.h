#ifndef TAREA_H
#define TAREA_H

#include <QObject>
#include "fecha.h"

class Tarea : public QObject {
    Q_OBJECT

public:
    explicit Tarea(QObject *parent = nullptr);
    Tarea(int indice, const QString &nombre, const Fecha fecha, char prioridad, const QString &tipo);

    int getIndice() const;
    void setIndice(int newIndice);
    const QString &getNombre() const;
    void setNombre(const QString &nombre);
    const Fecha &getFecha() const;
    void setFecha(const Fecha &fecha);
    char getPrioridad() const;
    void setPrioridad(char prioridad);
    const QString &getTipo() const;
    void setTipo(const QString &tipo);
    bool getTerminada() const;
    void setTerminada(bool newTerminada);

signals:
private:
    int indice;
    QString nombre;
    Fecha fecha;
    char prioridad;
    QString tipo;
    bool terminada;
};


#endif // TAREA_H
