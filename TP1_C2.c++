#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main(void){

    char caracter;
    cout<<"Ingrese el caracter para la busqueda: ";
    cin>>caracter;

    ifstream archivo;
    archivo.open("./busqueda.txt");
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
        return 1;
    }
    
    string linea;
    int contador=0;

    while (getline(archivo, linea)){
        for (char c : linea) {  //LEEMOS CARACTER POR CARACTER DEL STRING
            if (c == caracter){
                contador++; //AUMENTAMOS EL CONTADOR SI ENCONTRAMOS EL CARACTER EN EL STRING
            }
        }
    }
    archivo.close();
    cout<<"El caracter '"<<caracter<< "' aparece "<<contador<<" veces."<<endl;

}