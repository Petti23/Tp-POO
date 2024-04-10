#include <iostream>
#include <fstream>
using namespace std;

struct Datos{
	string nombre_apellido;
	int anio;
	string orden;
};

int main(void) {

	ifstream archivo; 
	string direccion="./datos.txt";
	archivo.open(direccion);
	if(!archivo.is_open()){
		cout << "No se pudo abrir el archivo" << endl;
        return 1;
	}
	
	string linea;
	int cont=0;
	while (getline(archivo,linea)){//CONTAMOS CUANTAS PERSONAS HAY
		cont++;
	}
	
	archivo.close();		//CERRAMOS EL ARCHIVO PARA LUEGO ABRIRLO DEVUELTA ASI RESETEAMOS EL PUNTERO DEL MOUSE

	Datos* personas=new Datos[cont];	//PEDIMOS ESPACIO EN LA MEMORIA 
	
	archivo.open(direccion);
	if(!archivo.is_open()){
		cout << "No se pudo abrir el archivo" << endl;
        return 1;
	}

	int indice=0;
	while (archivo>>personas[indice].orden){	//GUARDAMOS DATOS DE LAS PERSONAS
		archivo>>personas[indice].anio;
		archivo.ignore();
		getline(archivo,personas[indice].nombre_apellido);
		indice++;
	}
	
	archivo.close();
	
	int anio_maximo=personas[0].anio;	//ESTABLECEMOS LA PRIMERA EDAD COMO LA DEFAULT PARA COMPARAR
	int anio_minimo=personas[0].anio;	//ESTABLECEMOS LA PRIMERA EDAD COMO LA DEFAULT PARA COMPARAR
	
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

