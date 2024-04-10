#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main(void)
{
    ifstream archivo;
    archivo.open("./archive.txt");
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
        return 1;
    }

    int contador=0;
    string linea;
    
    while (getline(archivo, linea)){
        contador++;     //AUMENTAMOS EL CONTADOR A MEDIDA QUE LEEMOS LAS LINEAS DEL ARCHIVO
    }
    archivo.close();

    cout<<"El archivo tiene "<<contador<<" lineas."<<endl;

    return 0;
}
