#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(void){
	
	ifstream archivo;
	archivo.open("./oraciones.txt");
	if (archivo.fail()){
		cout << "No se ha podido abrir el archivo" << endl;
		return 1;
	}
	
	string texto;
	string aux;
	
	getline(archivo,aux,'.');	//LEEMOS HASTA EL '.' QUE ES LO QUE MARCA EL FIN DE UNA ORACIÓN
	while (!archivo.eof()) {
		texto+=aux+"." + '\n';	//CREAMOS EL TEXTO Y AGREGAMOS EL ENTER PARA HACER LAS LINEAS CORRESPONDIENTES
		archivo.ignore();		//BORRAMOS EL ESPACIO QUE SE ENCUENTRA LUEGO DE UN '.' EN UNA ORACION
				
		getline(archivo,aux,'.');//REPETIMOS EL PROCESO
	}
	
	ofstream archivo2;
	archivo2.open("./oraciones.txt");
	archivo2<<texto;
	archivo2.close();
	
	return 0;
}
	
	
