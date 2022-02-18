#include <iostream>

#include <tareas_ventana.h>

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>
#include <QString>

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
    int exit = app.exec();

    cout<< "Llegando al final"<<endl;

    if (tareas.tareas.isEmpty()) {
        return exit;
    }

    // El archivo con los datos se guarda automáticamente en build\debug cuando el programa se cierra.
    cout << "El archivo se estará guardando en: "<<app.applicationDirPath().toStdString()<< endl;
    string dataPath = app.applicationDirPath().toStdString() + "/data.csv";

    QFile archivo(QString::fromStdString(dataPath));

    if(archivo.open(QIODevice::WriteOnly|QIODevice::Text)){
        QTextStream datosArchivo(&archivo);
        for (int i = 0; i < tareas.tareas.size(); i++ ){
            datosArchivo<<tareas.tareas.at(i)->getIndice();
            datosArchivo<<";";
            datosArchivo<<tareas.tareas.at(i)->getNombre();
            datosArchivo<<";";
            datosArchivo<<tareas.tareas.at(i)->getFecha().getFecha();
            datosArchivo<<";";
            datosArchivo<<tareas.tareas.at(i)->getPrioridad();
            datosArchivo<<";";
            datosArchivo<<tareas.tareas.at(i)->getTipo();
            datosArchivo<<";";
            datosArchivo<<tareas.tareas.at(i)->getTerminada();
            datosArchivo<<"\n";
        }
    }
    archivo.close();

    return exit;
}
