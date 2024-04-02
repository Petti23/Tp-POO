#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main(int argc, char const *argv[])
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
        contador++;
    }
    archivo.close();

    cout<<contador<<endl;

    return 0;
}
