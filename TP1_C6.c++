#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

#include <cctype>
using namespace std;

void minusculas(string &texto){		//FUNCION PARA CONVERTIR TEXTO A MINUSCULAS, PARA EVITAR ERRORES CON EL USUARIO
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
	archivo.ignore();		//IGNORAMOS EL ESPACIO LUEGO DE LOS 2 PUNTOS ':'

	minusculas(aux);		//LLAMAMOS LA FUNCION MINUSCULAS

	while(getline(archivo,linea)){
		if (aux==palabra){		//BUSCAMOS LA PALABRA QUE INGRESA EL USUARIO EN EL ARCHIVO
			return linea;		//SI LA ENCUENTRA DEVUELVE EL SIGNIFICADO
		}
		getline(archivo,aux,':');	//SI NO LA ENCUENTRA SIGUE BUSCANDO Y REPETIMOS PROCESO
		minusculas(aux);
		archivo.ignore();
	}
	
	return "palabra no encontrada.";
}
 	
int main(void){
			
	string palabra,significado;
	getline(cin,palabra);		//PEDIMOS LA PALABRA PARA BUSCAR EL SIGNIFICADO
	
	significado = definicion(palabra);
		
	cout<<significado<<endl;

	return 0;
}
			
			
