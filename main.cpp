#include "structs.cpp"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;






void generarArchivo (char* nombreArchivo){


  FILE * novedades = fopen("novedades.dat","wb+");

  Archivo reg[15] = {{1052,1383073,1,5},{1052,1383073,1,6},{1052,1383073,2,7},
    {1052,1383073,3,1},{1052,1383073,3,2},{1053,1383072,1,1},{1053,1383072,1,6},
    {1053,1383072,2,7},{1053,1383072,3,6},{1053,1383072,4,3},{1053,1383072,4,6},
    {1053,1403050,1,8},{1053,1403050,2,10},{1053,1403050,3,9},{1053,1403050,4,8}
  };

  for(int i =0; i<15; i++){
	  fwrite(&reg[i],sizeof(Archivo),1,novedades);
  }

  fclose(novedades);

}





void cargarArchivo(char nombreArchivo[15]) {
    Archivo registro;
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

        fwrite(& registro, sizeof(Archivo), 1, novedades);
        cuenta++;

        cout << "ingrese Id de curso (0 para finalizar)." << endl;
        cin >> registro.idCurso;

    }
    cout << "Se han guardado " << cuenta << " registros." << endl;
    fclose(novedades);

}

void procesarNovedades(char * nombreArchivo, Curso * cursos) {

    Archivo registro;

    FILE * novedades = fopen(nombreArchivo, "rb");

    fread(& registro, sizeof(Archivo), 1, novedades);

    while (!feof(novedades)) {

        cout << registro.idCurso << endl;
        cout << registro.idEst << endl;
        cout << registro.parcial << endl << endl;
        cout << registro.nota << endl;

        fread(& registro, sizeof(Archivo), 1, novedades);

    }

    fclose(novedades);

}


void AgregarNota(Curso* cursos, Curso curso, Estudiante estudiante, int parcial, int nota){


}



int main() {

    Curso * cursos = NULL;
    char * nombreArchivo = "novedades.dat";

    //cargarArchivo(nombreArchivo);
    //generarArchivo(nombreArchivo);

    procesarNovedades(nombreArchivo, cursos);

    return 0;
}