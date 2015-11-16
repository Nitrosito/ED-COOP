#include "conjunto.h"
#include "crimen.h"
#include "fecha.h"
#include <iostream>
#include <fstream>

using namespace std;
	
	/** @brief lee un fichero de delitos, linea a linea
	@param[in] s nombre del fichero
        @param[in,out] C conjunto sobre el que se lee
	@return true si la lectura ha sido correcta, false en caso contrario
	*/

bool load(conjunto &  C, const string & s) {
 ifstream fe;
 string cadena;

 cout << "Abrimos "<< s << endl;
 fe.open(s.c_str(), ifstream::in);
 if (fe.fail())    
 {
   cerr << "Error al abrir el fichero " << s << endl;
 } else {
   getline(fe,cadena,'\n'); //leo la cabecera del fichero
   cout << cadena << endl;
   int i = 1;
    while ( /*!fe.eof()*/i >0 )
      { getline(fe,cadena,'\n');
       	if (!fe.eof()) {
	   cout << "leo:: "<< cadena << endl <<endl << endl;
	    //Convertir cadena a crimen
            crimen aux;
            // string s;
            // int ini = 0;
            // int fin = cadena.find_first_of(",");
            // s = cadena.substr(ini,fin);
            // long int a = stol(s);
            // aux.setID(a);

            // ini = fin;
            // fin = cadena.find_first_of(",",ini+1);
            // s = cadena.substr(ini,fin-ini);
            // cout << s << endl;
            // aux.setCaseNumber(s);


            // ini = fin;
            // fin = cadena.find_first_of(",",ini+1);
            // s = cadena.substr(ini,fin-ini);
            // cout << s << endl;
            // fecha f(s);
            // aux.setDate(f);  
            aux.setCrimen(cadena);
            //Insertar cadena en el conjunto
            C.insert(aux);
            cout << C << endl;
         }
         i--;
     }
    fe.close();
    return true;
    }  //else
  fe.close();
  return false;
 }

int main()
{
    conjunto ChicagoDB;
    crimen d;
    fecha f;
 
    

    load(ChicagoDB, "crimenes.csv");

   return 0;
}
