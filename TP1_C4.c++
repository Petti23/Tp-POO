#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

int main(void){

    char caracter_a_reemplazar;
    char caracter_nuevo;

    cout << "Ingrese Caracter a reemplazar: ";
    cin>>caracter_a_reemplazar;
    cin.ignore();
	
	cout << "Ingrese Caracter nuevo: ";
	cin>>caracter_nuevo;

    ifstream archivo;

    archivo.open("./texto.txt");
    if (!archivo.is_open()){
        cout << "No se ha podido abrir el archivo";
    }

    string texto;
    string aux;
    int cont_lineas=0;
    int cont_caracteres=0;

    while (getline(archivo, aux,'\n')){
		texto+=aux+'\n';    //CREAMOS EL TEXTO DONDE REEMPLAZAREMOS LOS CARACTERES

        for(char c : aux){  //LEEMOS CARACTER POR CARACTER DEL STRING
		    if(c == caracter_a_reemplazar){
                cont_caracteres++;  //ASEGURAMOS QUE HAYA CARACTERES A REEMPLAZAR EN LA LINEA
            }
        }
        if (cont_caracteres>=1){    
            cont_lineas++;      //CONTAMOS LA LINEA DONDE APARECEN LOS CARACTERES
        }
        cont_caracteres=0;  //RESETEAMOS CONTADOR PARA NO ACUMULAR CARACTERES QUE NO APARECEN EN OTRAS LINEAS
	}
	archivo.close();

    string caracter_nuevo_str;
    caracter_nuevo_str.push_back(caracter_nuevo);   //CONVERTIMOS DE TIPO CARACTER A STRING PARA LA FUNCION .REPLACE 

	int cont=0;
	for(char c : texto){
        cont++;
		if(c == caracter_a_reemplazar){
			texto.replace(cont-1,1,caracter_nuevo_str); //REEMPLAZAMOS LOS CARACTERES EN LA LINEA
		}
	}
    //FALTA CONTAR EN CUANTAS LINEAS SE REEMPLAZÓ

    cout<<"Lineas reemplazadas: "<<cont_lineas<<endl;

    ofstream archivo2;
    archivo2.open("./texto.txt");
    archivo2<<texto;
    archivo2.close();

    return 0;


}