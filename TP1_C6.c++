#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

#include <cctype>
using namespace std;

void minusculas(string &texto){
	for(unsigned int i=0; i<texto.length();i++){
		texto[i] = tolower(texto[i]);
	}
}
string definicion(string palabra){
	ifstream archivo;
	archivo.open("./diccionario.txt");
	if (archivo.fail()){
		return "No se pudo abrir el archivo";
	}
	
	string linea,aux;
	getline(archivo,aux,':');
	archivo.ignore();
	minusculas(aux);
	while(getline(archivo,linea)){
		if (aux==palabra){
			return linea;
		}
		getline(archivo,aux,':');
		minusculas(aux);
		archivo.ignore();
	}
	
	return "palabra no encontrada.";
}
 	
int main(int argc, char const *argv[]){
			
	string palabra,significado;
	getline(cin,palabra);
	
	significado = definicion(palabra);
		
	cout<<significado<<endl;

	return 0;
}
			
			
