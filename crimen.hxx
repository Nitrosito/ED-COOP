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
  
    ostream& operator<< ( ostream& , const crimen& );
  
