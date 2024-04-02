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

int main(int argc, char const *argv[]){

    ifstream archivo;
    archivo.open("./datos.txt");
    if (!archivo.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        return 1;
    }

    Datos personas;
    int cont=0;
    while(!archivo.eof()){
        archivo >> personas.orden >> personas.edad >> personas.nombre >> personas.apellido;
        if (personas.edad<1995){
            cont++;
        }
    }
    archivo.close();

    cout<<"Hay "<<cont<<" de 1995."<<endl;

    return 0;
}