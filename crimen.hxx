#include <iostream>
using namespace std;
  crimen();

  crimen(const crimen& x);

  void setID(long int & id);

  void setCaseNumber(const string & s);

  void setDate(const fecha & d);

  void setIucr(const string & s);

  void setPrimaryType(const string & s);

  void setDescription(const string & s);

  void setLocationDescription(const string & s);

  void setArrest(bool a);

  void setDomestic(bool d); 

  void setLatitude(double & lat);

  void setLongitude(double & lon);
  
  long int getID( ) const;

  string getCaseNumber( ) const;

  fecha getDate( ) const;

  string getIucr( ) const;

  string getPrimaryType( ) const;

  string getDescription( ) const;

  string getLocationDescription( ) const;

  bool getArrest( ) const;

  bool getDomestic( ) const;

  double getLatitude( ) const;

  double getLongitude( ) const;

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
