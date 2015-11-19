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
    while ( /*!fe.eof()*/i<100 )
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
    conjunto ChicagoDB;


    fecha f;
    long int n= 10222792;


    load(ChicagoDB, "crimenes.csv");
    // cout << ChicagoDB.empty() << endl;
    // cout << ChicagoDB.size() << endl;
    // cout << ChicagoDB.erase(n) << endl;
    // cout << ChicagoDB.size() << endl;
    // cout << "crimen a borrar: " << d << endl;
    // cout << ChicagoDB.erase(d) << endl;
    // cout << ChicagoDB.size() << endl;
    conjunto D(ChicagoDB);
    conjunto::description_iterator dit;
    cout << "a" << endl;
    dit = D.dbegin("DOMESTIC BATTERY SIMPLE");

    cout << "dbegin(): "<< *dit << endl << endl << endl << endl;
    dit++;
    cout << "dit++: "<< *dit << endl << endl << endl << endl;
    dit = D.dend();
    //cout << "Ultimo desc: " << *dit << endl;
    dit--;
    cout << "dit--: "<< *dit << endl << endl << endl << endl;

    conjunto::const_iterator it(D.cend());
    --it;
    crimen a = (*D.cbegin()) ;
    D.erase( a);
    cout << "Hemos borrado cbegin(): crimen: " << a  << "size(): "<< endl << endl;
    cout << D.size() << endl;
    cout << D << endl;
    cout << (it == D.cend()) << endl;

		// cout << "PROBANDO ADRESS ITERATOR" << endl;
  //   dit = D.dend();
		// conjunto::arrest_iterator ait;
  //   ait = ChicagoDB.aend();
  //   cout << "Ultimo arrest: " << *ait << endl;
     cout << "Ultimo desc: " << *dit << endl;
     cout << "Ultimo desc: " << (*D.end()) << endl;
		// ait = ChicagoDB.abegin();
		// cout << "Primer arrest: " << *ait << endl;

		

		// conjunto::arrest_iterator a_it2(ait);
		// cout << "Ultimo arrest, copiado a otro it : " << *a_it2 << endl;

		// ait=ChicagoDB.abegin();
		// cout << "Primer Arr+1 :" ;
		// ait++;
		// cout << *ait << endl;
		// ait--;
		// cout << *ait << endl;
		// cout << "es igual? " << (ait==a_it2) << endl;
		// cout << "son distintos? " << (ait!=a_it2) << endl;

   return 0;
}
