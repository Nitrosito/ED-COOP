#include <iostream>
#include <string>
//#include "fecha.h"
#include <vector>
//#include "crimen.h"
#include "conjunto.h"

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
	fecha una_fecha("11/03/1988 07:30:40 PM");
	string s = "11/04/1988 15:30:40 AM";
	cout << "fecha: " << una_fecha << endl;
	fecha otra_fecha;
	cout << "otra_fecha: " << otra_fecha << endl;
	otra_fecha = una_fecha;
	cout << "otra_fecha: " << otra_fecha << endl;
	otra_fecha = s;
	cout << "otra_fecha: " << otra_fecha << endl;

	string p = otra_fecha.toString();
	cout << "fecha.toString: " << p << endl;
	otra_fecha = s;
	cout << "otra_fecha: " << otra_fecha << endl;
	bool comp = otra_fecha >= otra_fecha;
	cout << "Comparar fechas >: " << comp << endl;

	//vector<int>v;
	//cout << v.size() << endl;

	crimen un_crimen;
	//cout << un_crimen << endl;
	un_crimen.setDate(una_fecha);
	un_crimen.setDomestic(true);
	long int i = 10230953;
	un_crimen.setID((i));
	un_crimen.setCaseNumber("1111111");
	un_crimen.setArrest(false);

	//cout << un_crimen << endl;

	crimen otro_crimen;

	otro_crimen = un_crimen;
	i = i +100;
	otro_crimen.setID(i);

	i = i -200;
	crimen otro_crimen2;
	otro_crimen2.setID(i);



	otro_crimen.setArrest(true);
	crimen tres;

	//cout << (un_crimen == otro_crimen) << endl;

	conjunto un_conjunto;
	cout << un_conjunto.insert(un_crimen) << endl;
	cout << un_conjunto.insert(otro_crimen) << endl;
	cout << un_conjunto.insert(tres) << endl;
	cout << otro_crimen2.getID() << endl;
	cout << un_conjunto.insert(otro_crimen2) << endl;
	cout << un_conjunto << endl;

} 
