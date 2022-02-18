#ifndef FECHA_H
#define FECHA_H

#include <QString>

class Fecha
{
public:
    Fecha(const QString &fecha);
    Fecha();

    void setFecha(const QString &fecha);
    const QString &getFecha() const;
private:
    QString fecha;
};

#endif // FECHA_H
