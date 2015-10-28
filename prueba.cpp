#include <iostream>
#include <string>
#include "fecha.h"

using namespace std;



int main(){
	/*string s = "11/03/1988";
	cout << "Imprimo todo el string: " << s << endl;

	int ini = 0;
	int fin = s.find_first_of("/");

	cout << "find_first_of() devuelve un entero a la posición dond encuentre primero lo que pongas entre parentesis: " << s.find_first_of("/") << endl;

	string aux = s.substr(ini,2);
	int i_dec = stoi(aux);
	cout << "mes: " << i_dec << endl;
	cout << "mes: " << aux << endl;

	ini = fin;
	fin = s.find_first_of("/",ini+1);	//hay que buscar desde la posicion siguiente a dond esta el primer "/"

	aux = s.substr(3,2);
	cout << "dia: " << aux << endl;


	cout << "Ini: " << ini << ", Fin: " << fin << endl;
	ini = fin;
	fin = s.size();

	aux = s.substr(6,4);
	cout << "año: " << aux << endl;

	//cout << s.find_first_of(",") << endl;*/
	fecha una_fecha("11/03/1988 07:30:40 AM");
	string s = "11/04/1988 07:30:40 AM";
	cout << "fecha: " << una_fecha << endl;
	fecha otra_fecha;
	cout << "otra_fecha: " << otra_fecha << endl;
	otra_fecha = una_fecha;
	cout << "otra_fecha: " << otra_fecha << endl;
	otra_fecha = s;
	cout << "otra_fecha: " << otra_fecha << endl;
} 
