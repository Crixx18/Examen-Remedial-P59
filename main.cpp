#include <iostream>

#include <tareas_ventana.h>

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QLocale::setDefault(QLocale::English);
    QTranslator traduccion;
    QStringList idiomas;
    idiomas << "Español"<< "Inglés";

    // Creamos un díalogo y le damos a elegir entre dos idiomas: Español e Inglés.
    QString idiomaSeleccionado = QInputDialog::getItem(NULL,
                                                       "Idioma/Language",
                                                       "Seleccione un idioma/Select a language",
                                                       idiomas);
    if (idiomaSeleccionado == "Inglés"){
        traduccion.load("en_EN.qm");
        app.installTranslator(&traduccion);
    }

    Tareas tareas;
    tareas.show();
    return app.exec();
}
