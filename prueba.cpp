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
// 	*/
crimen d;
template <typename T>
bool load(conjunto<T>  &  C, const string & s) {
 ifstream fe;
 string cadena;

 cout << "Abrimos "<< s << endl;
 fe.open(s.c_str(), ifstream::in);
 if (fe.fail())
 {
   cerr << "Error al abrir el fichero " << s << endl;
 } else {
   getline(fe,cadena,'\n'); //leo la cabecera del fichero
   crimen aux;
   int i = 0;
    while ( /*!fe.eof()*/i<10 )
      { getline(fe,cadena,'\n');
       	if (!fe.eof()) {
            aux.setCrimen(cadena);
            C.insert(aux);
            i++;
         }
     }
     d = aux;
    fe.close();
    return true;
    }  //else
  fe.close();
  return false;
 }

int main()
{
    conjunto<greater<crimen>> ChicagoDBMayoraMenor;
    conjunto<less<crimen>> ChicagoDBmenoraMayor;

    load(ChicagoDBmenoraMayor, "crimenes.csv");
    load(ChicagoDBMayoraMenor, "crimenes.csv");

    cout << "---------------- MENOR A MAYOR POR ID ----------------" << endl;
    cout << ChicagoDBmenoraMayor << endl;
    cout << "---------------------------------------------------------" << endl;

    cout << endl << "---------------- MAYOR A MENOR POR ID ----------------" << endl;
    cout << ChicagoDBMayoraMenor << endl;
    cout << "---------------------------------------------------------" << endl;

    conjunto<less<crimen> >::iterator it = ChicagoDBmenoraMayor.begin();

    it++;
    it++;
    crimen micrimen=*it;
    it++;
    it++;
    conjunto<less<crimen> >beginico (it,ChicagoDBmenoraMayor.end());
    cout << beginico;
    cout << "---------------------------------------------------------" << endl;
    cout << endl << endl << "-----------------PROBANDO FIND --------------------------" << endl;

    if(it==beginico.end())
        cout << "No se encuentra" << endl;
    else
      cout << "Encontrado " << *it << endl;

    it = beginico.find(micrimen);

    if(it==beginico.end())
        cout << "No se encuentra" << endl;
    else
    cout << *it << endl;

    cout << endl << endl << "-----------------PROBANDO FIND  POR ID ---------------------" << endl;
    it = beginico.find(10231208);
    if(it==beginico.end())
      cout << "No se encuentra" << endl;
    else
    cout << "Encontrado " << *it << endl;


    cout << endl << endl << "-----------------PROBANDO lower_bound ---------------------" << endl;
    cout << "MICRIMEN: " << micrimen << endl;
    it = beginico.lower_bound(micrimen);
    if(it==beginico.end())
      cout << "No se encuentra" << endl;
    else
    cout << "Encontrado " << *it << endl;

    micrimen = *(++it);
    cout << endl << endl << "-----------------PROBANDO upper_bound ---------------------" << endl;
    cout << "MICRIMEN: " << micrimen << endl;
    it = beginico.upper_bound(micrimen);
    if(it==beginico.end())
      cout << "No se encuentra" << endl;
    else
    cout << "Encontrado " << *it << endl;

}
