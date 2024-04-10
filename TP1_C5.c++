#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

struct Datos{
    int orden;
    int edad;
    string nombre;
    string apellido;
};

int main(void){

    ifstream archivo;
    archivo.open("./anios.txt");
    if (!archivo.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        return 1;
    }

    Datos personas;
    int cont=0;
    while(!archivo.eof()){
        archivo >> personas.orden >> personas.edad >> personas.nombre >> personas.apellido;
        if (personas.edad<1995){    //COMPARAMOS EDAD PARA SABER SI NACIÓ ANTES DE 1995
            cont++;
        }
    }
    archivo.close();

    cout<<"Hay "<<cont<<" nacidos antes de 1995."<<endl;

    return 0;
}