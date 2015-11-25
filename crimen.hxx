#include <iostream>

using namespace std;

  crimen::crimen(){
  	ID=0;
  	arrest=false;
  	domestic=false;
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

  void crimen::setID(long int & id){
	  ID=id;
  }

  void crimen::setCaseNumber(const string & s){
	  casenumber=s;
  }

  void crimen::setDate(const fecha & d){
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
  void crimen::setCrimen(string & cadena){
    string s;
    int ini = 0;
    int fin = cadena.find_first_of(",");
    s = cadena.substr(ini,fin);
    if(!s.empty()){
      long int a = stol(s);
      setID(a);
    }
    //cout << "ID: " << s << endl;

    ini = fin+1;
    fin = cadena.find_first_of(",",ini);
    s = cadena.substr(ini,fin-ini);
    //cout << "CaseNumber: " << s << endl;
    setCaseNumber(s);

    ini = fin+1;
    fin = cadena.find_first_of(",",ini);
    s = cadena.substr(ini,fin-ini);
    //cout << "IFecha: " << s << endl;
    fecha f(s);
    setDate(f);

    ini = fin+1;
    fin = cadena.find_first_of(",",ini);

    ini = fin+1;
    fin = cadena.find_first_of(",",ini);
    s = cadena.substr(ini,fin-ini);
    //cout << "IUCR: " << s << endl;
    setIucr(s);

    ini = fin+1;
    fin = cadena.find_first_of(",",ini);
    s = cadena.substr(ini,fin-ini);
    //cout << "primarytype: " << s << endl;
    setPrimaryType(s);

    ini = fin+1;
    fin = cadena.find_first_of(",",ini);
    s = cadena.substr(ini,fin-ini);
    //cout << "description: " << s << endl;
    setDescription(s);

    ini = fin+1;
    fin = cadena.find_first_of(",",ini);
    s = cadena.substr(ini,fin-ini);
    //cout << "location_descrip: " << s << endl;
    setLocationDescription(s);

    ini = fin+1;
    fin = cadena.find_first_of(",",ini);
    s = cadena.substr(ini,fin-ini);
    //cout << "Arrest: " << s << endl;
    bool b;
    (s.compare("true") == 0) ? b = true: b = false;
    setArrest(b);

    ini = fin+1;
    fin = cadena.find_first_of(",",ini);
    s = cadena.substr(ini,fin-ini);
    (s.compare("true") == 0) ? b = true: b = false;
    //cout << "domestic: " << s << endl;
    setDomestic(b);

    ini = fin+1;
    fin = cadena.find_first_of(",",ini);
    //s = cadena.substr(ini,fin-ini);
    //c.setBeat(s);

    ini = fin+1;
    fin = cadena.find_first_of(",",ini);
    //s = cadena.substr(ini,fin-ini);
    //c.setDistrito(s);

    ini = fin+1;
    fin = cadena.find_first_of(",",ini);
    //s = cadena.substr(ini,fin-ini);
    //c.setWard(s);

    ini = fin+1;
    fin = cadena.find_first_of(",",ini);
    //s = cadena.substr(ini,fin-ini);
    //c.setComunity(s);

    ini = fin+1;
    fin = cadena.find_first_of(",",ini);
    //s = cadena.substr(ini,fin-ini);
    //c.setArea(s);

    ini = fin+1;
    fin = cadena.find_first_of(",",ini);
    //s = cadena.substr(ini,fin-ini);
    //c.setFBICode(s);

    ini = fin+1;
    fin = cadena.find_first_of(",",ini);

    ini = fin+1;
    fin = cadena.find_first_of(",",ini);

    ini = fin+1;
    fin = cadena.find_first_of(",",ini);

    ini = fin+1;
    fin = cadena.find_first_of(",",ini);
    s = cadena.substr(ini,fin-ini);
    //cout << "latitude: " << s << endl;
    if(!s.empty()){
      double d=stod(s);
      setLatitude(d);
    }


    ini = fin+1;
    fin = cadena.find_first_of(",",ini);
    s = cadena.substr(ini,fin-ini);
    //cout << "longitude: " << s << endl;
    if(!s.empty()){
      double d=stod(s);
      setLongitude(d);
    }
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

  bool crimen::operator<(const crimen & x) const{
    if(ID < x.getID())
      return true;
    else
      return false;
  }

  bool crimen::operator>(const crimen & x) const{
    if(ID > x.getID())
      return true;
    else
      return false;
  }


  ostream& operator<< ( ostream &os , const crimen& c){
    os << c.ID << "," << c.casenumber << "," << c.date << "," << c.iucr << "," << c.primarytype << "," << c.description << "," << c.location_descrip << "," << c.arrest << "," << c.domestic << "," << c.latitude << "," << c.longitude;
    return os;
  }
