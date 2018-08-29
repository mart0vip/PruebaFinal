#include "structs.cpp"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

void cargarArchivo(char nombreArchivo[15]) {
    archivo registro;
    int cuenta = 0;

    FILE * novedades = fopen(nombreArchivo, "wb+");

    cout << "ingrese Id de curso (0 para finalizar)." << endl;
    cin >> registro.idCurso;

    while (registro.idCurso) {
        cout << "ingrese Id del estudiante." << endl;
        cin >> registro.idEst;
        cout << "ingrese numero de parcial." << endl;
        cin >> registro.parcial;
        cout << "ingrese nota." << endl;
        cin >> registro.nota;

        fwrite(& registro, sizeof(archivo), 1, novedades);
        cuenta++;

        cout << "ingrese Id de curso (0 para finalizar)." << endl;
        cin >> registro.idCurso;

    }
    cout << "Se han guardado " << cuenta << " registros." << endl;
    fclose(novedades);

}

void procesarNovedades(char * nombreArchivo, Curso * cursos) {

    archivo registro;

    FILE * novedades = fopen(nombreArchivo, "rb");

    fread(& registro, sizeof(archivo), 1, novedades);

    while (!feof(novedades)) {

        cout << registro.idCurso << endl;
        cout << registro.idEst << endl;
        cout << registro.parcial << endl << endl;
        cout << registro.nota << endl;

        fread(& registro, sizeof(archivo), 1, novedades);

    }

    fclose(novedades);

}

int main() {

    Curso * cursos = NULL;
    char * nombreArchivo = "novedades.dat";

    cargarArchivo(nombreArchivo);

    procesarNovedades(nombreArchivo, cursos);

    return 0;
}