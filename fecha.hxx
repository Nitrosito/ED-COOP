/** @brief fichero de implementacion de la clase fecha

*/
fecha::fecha(){
  // @todo implementar esta funcion
}

fecha::fecha(const fecha & x){
 // @todo implementar esta funcion
}
  
    
 
 ostream& operator<< ( ostream& os, const fecha & f){
   // @todo implementa esta funcion
     
   // os << f.getYear() ;
   return os;
 }
   
   
 bool operator>=(const fecha & f) const{
	if(this->year >= f.year)
		return true;
	else{
		if(this->mon >= f.mon)
			return true;
		else{
			if(this->mday >= f.mday)
				return true;
			else{
				if(this->hour >= f.hour)
					return true;
				else{
					if(this->min >= f.min)
						return true;
					else{
						if(this->sec >= f.sec)
							return true;
						else
							return false;
					}
				}
			}
		
		}

	}
 }
