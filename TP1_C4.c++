#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]){

    char caracter_a_reemplazar;
    char caracter_nuevo;

    cout << "Ingrese Caracter a reemplazar: ";
    cin>>caracter_a_reemplazar;
    cin.ignore();
	
	cout << "Ingrese Caracter nuevo: ";
	cin>>caracter_nuevo;

    ifstream archivo;

    archivo.open("./archivo.txt");
    if (!archivo.is_open()){
        cout << "No se ha podido abrir el archivo";
    }

    string texto;
    string aux;

    while (getline(archivo, aux)){
		texto+=aux+'\n';
	}
	archivo.close();

    string caracter_nuevo_str;
    caracter_nuevo_str.push_back(caracter_nuevo);    

	int cont=0;
	for(char c : texto){
        cont++;
		if(c == caracter_a_reemplazar){
			texto.replace(cont-1,1,caracter_nuevo_str);
		}
		
	}
    //FALTA CONTAR EN CUANTAS LINEAS SE REEMPLAZÓ

    ofstream archivo2;
    archivo2.open("./archivo2.txt");
    archivo2<<texto;

    return 0;


}