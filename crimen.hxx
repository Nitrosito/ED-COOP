#include <iostream>
using namespace std;
  crimen::crimen(){
	ID=0;
	casenumber="0";
	date=("00/00/0000 00:00:00 AM");	
	iucr="0000";
	primarytype="0";
	description="0";
	location_descrip="0";
	arrest=false;
	domestic=false;
	latitude=0;
	longitude=0;
  } 

  crimen(const crimen& x){
	ID=x.ID;
	casenumber=x.casenumber;
	date=x.date;	
	iucr=x.iucr;
	primarytype=x.primarytype;
	description=x.description;
	location_descrip=x.location_descrip;
	arrest=x.arrest;
	domestic=x.domestic;
	latitude=x.latitude;
	longitude=x.longitude;
  }

  void setID(long int & id){
	this.ID=id;
  }

  void setCaseNumber(const string & s){
	this.casenumber=s;
  }

  void setDate(const fecha & d){
	this.date=d;
  }

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
  
    ostream& operator<< ( ostream& , const crimen& );
  
