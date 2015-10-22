/** @brief fichero de implementacion de la clase fecha

*/
fecha::fecha(){
  sec = 0;
  min = 0;
  hour = 0;
  (*this).mday = 0;
  this->mon = 0;
  year = 0;
}

fecha::fecha(const fecha & x){
  sec = x.sec;
  min = x.min;
  hour = x.hour;
  mday = x.mday;
  mon = x.mon;
  year = x.year;
}

fecha & operator=(const fecha & f){
	this->sec = f.sec;
	this->min = f.min;
	hour = f.hour;
	mday = f.mday;
	mon = f.mon;
	year = f.year;
}
  
    
 
 ostream& operator<< ( ostream& os, const fecha & f){
   // @todo implementa esta funcion
   if(f.hour < 12)
   	os << f.mon << "/" << f.mday << "/" << f.year << " " << f.hour << ":" << f.min << ":" << f.sec << " AM";
   else
    os << f.mon << "/" << f.mday << "/" << f.year << " " << f.hour << ":" << f.min << ":" << f.sec << " PM";
     
   return os;
 }
   
   
 
