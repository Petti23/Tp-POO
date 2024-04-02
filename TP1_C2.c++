#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main(int argc, char const *argv[]){

    char caracter;
    cout<<"Ingrese el caracter para la busqueda";
    cin>>caracter;

    ifstream archivo;
    archivo.open("./palabras.txt");
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
        return 1;
    }
    
    string linea;
    int contador=0;

    while (getline(archivo, linea)){
        for (char c : linea) {
            if (c == caracter){
                contador++;
            }
        }
    }
    archivo.close();
    cout<<"El caracter"<<caracter<< "aparece"<<contador<<"veces."<<endl;

}