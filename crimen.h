/* 
 * meteorito.h
 * 
 * Copyright  (C) Juan F. Huete
*/
#ifndef __CRIMEN_H
#define __CRIMEN_H

#include <string>
#include <iostream> 

#include "fecha.h"
//! Clase crimen, asociada a la definición de un crimen 
/*! crimen::crimen,  .....
 * Descripción contiene toda la información asociada a un crimen.
 
 @todo Implementa esta clase, junto con su documentación asociada

*/


class crimen {
 public:
  /**
   * @brief Constructor sin parametros
   * */ 
  crimen();

  /**
   * @brief Construtor a partir dae un objeto crimen
   * @param crimen Objeto el cual que copiara
   */
  crimen(const crimen& x);

  /**
   * @brief Asigna un ID
   * @param id Valor a asignar
   */
  void setID(long int & id);

  /**
   * @brief Asigna un numero de caso
   * @param s Numero de caso a asignar
   */
  void setCaseNumber(const string &  s);

  /**
   * @brief Asigna una fecha
   * @param d Fecha a asignar
   */
  void setDate(const fecha & d);
  // ...
  //

  /**
   * @brief Asigna si esta arrestado // #fixme
   * @param a Valor a asignar
   */
  void setArrest(bool a);

  /**
   * @brief Asigna si es domestico
   * @param d Valor a asignar
   */
  void setDomestic(bool d); 
  // ...
  
  
  /**
   * @brief Obtiene el ID de un caso
   * @return ID del caso
   */
  long int getID( ) const;

  /**
   * @brief Obtiene el numero de Caso
   * @return Numero de caso
   */
  string getCaseNumber( ) const;

  /**
   * @brief Obtiene la fecha
   * @return Fecha
   */
  fecha getDate( ) const;
  // -...

  /**
   * @brief Operador de asignacion
   * @param 
   */
   crimen & operator=(const crimen & c);
   bool operator==(const crimen & x) const;
   bool operator<(const crimen & x) const;
 private:
   friend ostream& operator<< ( ostream& , const crimen& );
   //Atributos 
   long int ID; 
  // ...
};

  ostream& operator<< ( ostream& , const crimen& );


#include "crimen.hxx"
#endif
