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

  crimen::crimen(const crimen& x){
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
	  ID=id;
  }

  void setCaseNumber(const string & s){
	  casenumber=s;
  }

  void setDate(const fecha & d){
	  date=d;
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

  crimen & crimen::operator=(const crimen & x){
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

   bool crimen::operator==(const crimen & x) const{
    if(this->ID == x.ID && this-> casenumber == x.casenumber && this->date == x.date && this->iucr == x.iucr && this->primarytype == x.primarytype && this->description == x.description 
      && this->location_descrip == x.location_descrip && this->arrest == x.arrest && this->domestic == x.domestic && this->latitude == x.latitude && this->longitude == x.longitude){
        return true;
    }
    else{
        return false;
    }
   }

   bool operator<(const crimen & x) const{
      if(date < x.date)
        return true;
      else
        return false;
   }
  
    ostream& operator<< ( ostream& , const crimen& );
  
