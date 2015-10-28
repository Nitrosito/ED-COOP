#include <iostream>
using namespace std;
  crimen();

  crimen(const crimen& x);

  void setID(long int & id);

  void setCaseNumber(const string & s);

  void setDate(const fecha & d);

  void crimen::setIucr(const string & s){
    iucr = s;
  }

  void crimen::setPrimaryType(const string & s){
    primarytype = s;
  }

  void crimen::setDescription(const string & s){
    description = s;
  }

  void crimen::setLocationDescription(const string & s){
    location_descrip = s;
  }

  void crimen::setArrest(bool a){
    arrest = a;
  }

  void crimen::setDomestic(bool d){
    domestic = d;
  } 

  void crimen::setLatitude(double & lat){
    latitude = lat;
  }

  void crimen::setLongitude(double & lon){
    longitude = lon;
  }
  
  long int crimen::getID( ) const{
    return ID;
  }

  string crimen::getCaseNumber( ) const{
    return casenumber;
  }

  fecha crimen::getDate( ) const{
    return date;
  }

  string crimen::getIucr( ) const{
    return iucr;
  }

  string crimen::getPrimaryType( ) const{
    return primarytype;
  }

  string crimen::getDescription( ) const{
    return description;
  }

  string crimen::getLocationDescription( ) const{
    return location_descrip;
  }

  bool crimen::getArrest( ) const{
    return arrest;
  }

  bool crimen::getDomestic( ) const{
    return domestic;
  }

  double crimen::getLatitude( ) const{
    return latitude;
  }

  double crimen::getLongitude( ) const{
    return longitude;
  }

   crimen & operator=(const crimen & c);
   bool operator==(const crimen & x) const;

   bool operator<(const crimen & x) const;

 private:
   friend ostream& operator<< ( ostream& , const crimen& );
  
   //Atributos 
   long int ID;             // Identificador del delito
   string casenumber;       // Código del caso
   fecha date;              // Fecha en formato mm/dd/aaaa hh:mm:ss AM/PM
   string iucr;             // Código del tipo de delito según Illinois Uniform Crime Reporting, IUCR
   string primarytype;      // Tipo de delito
   string description       // Descripción más detallada
   string location_descrip  // Descripción del tipo de localización
   bool arrest              // Si hay arrestos o no
   bool domestic            // Si es un crimen domestico o no
   double latitude          // Coordenada de latitud
   double longitude         // Coordenada de longitud
};

  ostream& operator<< ( ostream& , const crimen& );
