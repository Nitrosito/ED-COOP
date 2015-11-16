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
crimen d;
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
   crimen aux;
   int i = 0;
    while ( /*!fe.eof()*/i<15 )
      { getline(fe,cadena,'\n');
       	if (!fe.eof()) {
	   //cout << "leo:: "<< cadena << endl <<endl << endl;
	    //Convertir cadena a crimen
            aux.setCrimen(cadena);
            //Insertar cadena en el conjunto

            C.insert(aux);
            i++;
            //cout << C << endl;
         }

     }
     cout << C << endl;
     d = aux;
    fe.close();
    return true;
    }  //else
  fe.close();
  return false;
 }

int main()
{
    conjunto ChicagoDB, D;
    conjunto::iterator it;
    
    fecha f;
    long int n= 10222792;
    

    load(ChicagoDB, "crimenes.csv");
    cout << ChicagoDB.empty() << endl;
    cout << ChicagoDB.size() << endl;
    cout << ChicagoDB.erase(n) << endl;
    cout << ChicagoDB.size() << endl;
    cout << "crimen: " << d << endl;
    cout << ChicagoDB.erase(d) << endl;
    cout << ChicagoDB.size() << endl;
    D = ChicagoDB;
    it = D.end();
    it--;
    D.erase(*it);
    cout << D.size() << endl;
    for(int i = D.size(); i >0 ; i--){
      cout << *it << endl;
      it--;
    }


   return 0;
}
