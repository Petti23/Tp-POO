#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[]){
	
	ifstream archivo;
	archivo.open("./texto.txt");
	if (archivo.fail()){
		cout << "No se ha podido abrir el archivo" << endl;
		return 1;
	}
	
	string texto;
	string aux;
	
	getline(archivo,aux,'.');	
	while (!archivo.eof()) {
		texto+=aux+"." + '\n';
		getline(archivo,aux,'.');
	}
	
	ofstream archivo2;
	archivo2.open("./texto2.txt");
	archivo2<<texto;
	archivo2.close();
	
	return 0;
}
	
	
