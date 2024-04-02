#include <iostream>
#include <fstream>
using namespace std;


struct Datos{
	string nombre_apellido;
	int anio;
	string orden;
};

bool abrir_archivo(string direccion, ifstream &archivo){
	archivo.open(direccion);
	if (!archivo.is_open()){
		return true;
	}	
	return false;
}

int main(void) {

	ifstream archivo; 
	string direccion="./personas.txt";
	if (abrir_archivo(direccion,archivo)==true){
		return -1;
		cout<<"no se pudo abrir el archivo"<<endl;
	}
	
	string linea;
	int cont=0;
	while (getline(archivo,linea)){//contamos cuantas personas hay
		cont++;
	}
	
	archivo.close();
	Datos* personas=new Datos[cont];
	
	if (abrir_archivo(direccion,archivo)==true){
		return -1;
		cout<<"no se pudo abrir el archivo"<<endl;
	}

	int indice=0;
	while (archivo>>personas[indice].orden){
		archivo>>personas[indice].anio;
		archivo.ignore();
		getline(archivo,personas[indice].nombre_apellido);
		indice++;
	}
	
	archivo.close();
	
	int anio_maximo=personas[0].anio;
	int anio_minimo=personas[0].anio;
	
	for (int i=0;i<cont;i++){
		if (personas[i].anio>anio_maximo){
			anio_maximo=personas[i].anio;
		}
		if (personas[i].anio<anio_minimo){
			anio_minimo=personas[i].anio;
		}
	}    
	
	cout << "Anio de nacimiento minimo: " << anio_minimo << endl;
	cout << "Anio de nacimiento maximo: " << anio_maximo << endl;
	cout << "Total de registros leidos: " << cont << endl;
	
	// Liberar la memoria asignada  
	delete [] personas;
	
	
	
	return 0;
}

