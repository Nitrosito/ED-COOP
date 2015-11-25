/*
 * meteorito.h
 *
 * Copyright  (C) Juan F. Huete
*/
#ifndef __CRIMEN_H
#define __CRIMEN_H


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
  void setCaseNumber(const string & s);

  /**
   * @brief Asigna una fecha
   * @param d Fecha a asignar
   */
  void setDate(const fecha & d);

  /**
   * @brief Asigna un código del tipo de delito según Illinois Uniform Crime Reporting, IUCR
   * @param s Código a asignar
   */
  void setIucr(const string & s);

  void setPrimaryType(const string & s);

  void setDescription(const string & s);

  void setLocationDescription(const string & s);

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

  void setLatitude(double & lat);

  void setLongitude(double & lon);

  /**
    *@brief Convierte una cadena en un crimen
    @param cadena Cadena a convertir
  */
  void setCrimen(string & cadena);



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

  string getIucr( ) const;

  string getPrimaryType( ) const;

  string getDescription( ) const;

  string getLocationDescription( ) const;

  bool getArrest( ) const;

  bool getDomestic( ) const;

  double getLatitude( ) const;

  double getLongitude( ) const;

  /**
   * @brief Operador de asignacion
   * @param
   */
   crimen & operator=(const crimen & c);
   bool operator==(const crimen & x) const;

   bool operator<(const crimen & x) const;
   bool operator>(const crimen & x) const;


 private:
   friend ostream& operator<< ( ostream& , const crimen& );

   //Atributos
   long int ID;             // Identificador del delito
   string casenumber;       // Código del caso
   fecha date;              // Fecha en formato mm/dd/aaaa hh:mm:ss AM/PM
   string iucr;             // Código del tipo de delito según Illinois Uniform Crime Reporting, IUCR
   string primarytype;      // Tipo de delito
   string description;       // Descripción más detallada
   string location_descrip;  // Descripción del tipo de localización
   bool arrest;              // Si hay arrestos o no
   bool domestic;            // Si es un crimen domestico o no
   double latitude;          // Coordenada de latitud
   double longitude;         // Coordenada de longitud
};

  ostream& operator<< ( ostream& , const crimen& );


#include "crimen.hxx"
#endif
