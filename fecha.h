/**
 * @file fecha.h
 * @brief Fichero cabecera para fecha
 * 
 *
*/
#ifndef __FECHA_H
#define __FECHA_H

#include <string>
#include <iostream> 


//! Clase fecha, asociada a la 
/*! fecha::fecha,  .....
 * Descripción contiene toda la información asociada a una fecha con el formato  mm/dd/aaaa hh:mm:ss AM/PM
 @todo Escribe la documentación de la clase
 @todo Implementar esta clase

*/
using namespace std;
class fecha {

public:
  /**@brief Constructor sin parametros
   */
 fecha (); //Constructor de fecha por defecto

 /**@brief Constructor con parametros: Recibe un string
  * @param fecha formato mm/dd/aaaa  hh:mm:ss AM/PM
  */

 fecha (const string & s); // s es un string con el formato mm/dd/aaaa  hh:mm:ss AM/PM

 /**@brief Constructor de copia
  *@param fecha f
  */
 fecha(const fecha& f);//Constructor de copia


 /**@brief operador de asignación
  * @param fecha fecha origen
  */
 fecha & operator=(const fecha & f);
 
 
 /**@brief operador de asignación
  * @param cadena con formato mm/dd/aaaa  hh:mm:ss AM/PM
  */
 fecha & operator=(const string & s); // s es un string con el formato mm/dd/aaaa hh:mm:ss AM/PM

 /**@brief función que convierte la fecha a un string
  */
 string toString()const; //convierte la fecha a un string

// Operadores relacionales
/**@brief operador ==
 * @param fecha &f
 */
 bool operator==(const fecha & f) const;
 /**@brief operador <
 * @param fecha &f
 * @return devuelve true si es la misma fecha, false en caso contrario
 */
 bool operator<(const fecha & f)const;
 /**@brief operador >
 * @param fecha &f
 * @return devuelve true si es una fecha anterior, false en caso contrario
 */
 bool operator>(const fecha & f) const;
 /**@brief operador <=
 * @param fecha &f
 * @return devuelve true si es una fecha posterior, false en caso contrario
 */
 bool operator<=(const fecha & f)const;
 /**@brief operador >=
 * @param fecha &f
 * @return devuelve true si es una fecha anterior o la misma fecha, false en caso contrario
 */
 bool operator>=(const fecha & f) const;
 /**@brief operador !=
 * @param fecha &f
 * @return devuelve true si es una fecha posterior o la misma fecha, false en caso contrario
 */
 bool operator!=(const fecha & f)const;

private:
  int  sec;   // seconds of minutes from 0 to 61
  int  min;   // minutes of hour from 0 to 59
  int  hour;  // hours of day from 0 to 24
  int  mday;  // day of month from 1 to 31
  int  mon;   // month of year from 0 to 11
  int  year;  // year since 2000

  /**@brief operador <<
   * @param ostream &os
   * @param fecha &f
   */
friend  ostream& operator<< ( ostream &os, const fecha & f); 
};

/* @brief imprime fecha con el formato  mm/dd/aaaa hh:mm:ss AM/PM
*/
 ostream& operator<<( ostream& os, const fecha & f); 

#include "fecha.hxx" // Incluimos la implementacion.


#endif
