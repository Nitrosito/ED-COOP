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



    //fecha f;
    //long int n= 10222792;


    load(ChicagoDBmenoraMayor, "crimenes.csv");
    load(ChicagoDBMayoraMenor, "crimenes.csv");

    cout << "---------------- MENOR A MAYOR POR ID ----------------" << endl;
    cout << ChicagoDBmenoraMayor << endl;
    cout << "---------------------------------------------------------" << endl;

    cout << endl << "---------------- MAYOR A MENOR POR ID ----------------" << endl;
    cout << ChicagoDBMayoraMenor << endl;
    cout << "---------------------------------------------------------" << endl;


}
//     conjunto::iterator it = ChicagoDB.begin();
//     conjunto::const_iterator cit = ChicagoDB.cbegin();
//     conjunto::description_iterator dit = ChicagoDB.dbegin("OVER $500");
//     conjunto::const_description_iterator dcit = ChicagoDB.dcbegin("SIMPLE");
//     conjunto::arrest_iterator ait = ChicagoDB.abegin();
//     conjunto::const_arrest_iterator acit = ChicagoDB.acbegin();
//
//
//     conjunto::const_arrest_iterator acit_aux;
//
//     while(it != ChicagoDB.end()){
//       cout << "it: " << *it << endl;
//       it++;
//     }
//     it--;
//     cout << "--it" << *--it << endl;
//
//     cout << (it == ChicagoDB.begin()) << endl;
//
//     while(cit != ChicagoDB.cend()){
//       cout << "cit: " << *cit << endl;
//       cit++;
//     }
//
//     cit--;
//     cout << "--cit" << *--cit << endl;
//
//     cout << (cit == ChicagoDB.cbegin()) << endl;
//
//     while(dit != ChicagoDB.dend()){
//       cout << "dit: " << *dit << endl;
//       dit++;
//     }
//
//     dit--;
//     cout << "--dit" << *--dit << endl;
//
//     cout << (dit == ChicagoDB.dbegin("OVER $500")) << endl;
//
//     while(dcit != ChicagoDB.dcend()){
//       cout << "dcit: " << *dcit << endl;
//       dcit++;
//     }
//
//     dcit--;
//     cout << "--dcit" << *--dcit << endl;
//
//     cout << (dcit == ChicagoDB.dcbegin("SIMPLE")) << endl;
//
//     while(ait != ChicagoDB.aend()){
//       cout << "ait: " << *ait << endl;
//       ++ait;
//     }
//
//     ait--;
//     cout << "--ait" << *--ait << endl;
//
//     cout << (ait == ChicagoDB.abegin()) << endl;
//
//     while(acit != ChicagoDB.acend()){
//       cout << "acit: " << *acit << endl;
//       acit++;
//     }
//
//     acit--;
//     cout << "--acit" << *--acit << endl;
//     acit_aux = acit;
//
//     cout << (acit == acit_aux) << endl;
//
//    return 0;
// }
