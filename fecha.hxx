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

fecha::fecha(const string & s){
string aux;
aux = s.substr(0,2);
sec = stoi(aux);
aux = s.substr(3,2);
min = stoi(aux);
aux = s.substr(6,4);
if(aux.compare("AM") == 0)
	hour = stoi(aux);
else
	hour = 12+(stoi(aux));
aux = s.substr(11,2);
mday = stoi(aux);
aux = s.substr(14,2);
mon = stoi(aux);
aux = s.substr(17.2);
year = stoi(aux);
}

fecha & fecha::operator=(const fecha & f){
	this->sec = f.sec;
	this->min = f.min;
	hour = f.hour;
	mday = f.mday;
	mon = f.mon;
	year = f.year;
}

fecha & fecha::operator=(const string & s){
	fecha f;
	string aux;
	int tam;
	//tam =  @FIXME @nitrosito @ismael
	aux = s.substr(0,2);
	f.mon = atoi(aux);
}
    
 
fecha ostream&::operator<< ( ostream& os, const fecha & f){
   // @todo implementa esta funcion
   if(f.hour < 12)
   	os << f.mon << "/" << f.mday << "/" << f.year << " " << f.hour << ":" << f.min << ":" << f.sec << " AM";
   else
    os << f.mon << "/" << f.mday << "/" << f.year << " " << f.hour << ":" << f.min << ":" << f.sec << " PM";
     
   return os;
 }
   
fecha::bool operator>=(const fecha & f) const{
     	if(this->year > f.year)
		return true;
	else if(this->year < f.year)
		return false;

	else{
		if(this->mon > f.mon)
			return true;
		else if(this->mon < f.mon)
			return false;

		else{
			if(this->mday > f.mday)
				return true;
			else if(this->mday < f.mday)
				return false;
			
			else{
				if(this->hour > f.hour)
					return true;
				else if(this->hour < f.hour)
					return false;

				else{
					if(this->min > f.min)
						return true;
					else if(this->hour < f.hour)
						return false;
					else{
						if(this->sec > f.sec)
							return true;
						else if(this->sec < f.sec)
						       return false;
					}
				}
			}											
		}
	}
}
 
//Compara fechas, sin UNA ES ANTERIOR A otra
  fecha::bool operator<(const fecha & f)const{
    if(this->year < f.year){
      return true;
    }else if(this->year > f.year){
      return false;
    }else{
      if(this->mon < f.mon){
        return true;
      }else if(this->mon < f.mon){
        return false;
      }else{
        if(this->mday < f.mday){
          return true;
        }else if(this-> mday > f.mday){
          return false;
        }else{
          if(this->hour < f.hour){
            return true;
          }else if(this->hour > f.hour){
            return false;
          }else{
            if(this->min < f.min){
              return true;
            }else if(this->min > f.min){
              return false;
            }else{
              if(this->sec < f.sec){
                return true;
              }else if(this->sec >f.sec){
                return false;
              }
            }
          }
        }
      }
    }
  }

  // Compara fechas, si una es ANTERIOR O IGUAL A otra
 fecha::bool operator<=(const fecha & f) const{
   if(this->year < f.year){
     return true;
   }else if(this->year > f.year){
     return false;
   }else{
     if(this->mon < f.mon){
       return true;
     }else if(this->mon < f.mon){
       return false;
     }else{
       if(this->mday < f.mday){
         return true;
       }else if(this-> mday > f.mday){
         return false;
       }else{
         if(this->hour < f.hour){
           return true;
         }else if(this->hour > f.hour){
           return false;
         }else{
           if(this->min < f.min){
             return true;
           }else if(this->min > f.min){
             return false;
           }else{
             if(this->sec <= f.sec){
               return true;
             }else if(this->sec >f.sec){
               return false;
             }
           }
         }
       }
     }
   }
 }
  //Compara fechas, si UNA ES IGUAL A OTRA
  fecha::bool operator==(const fecha & f) const{
    if(this->year == f.year && this->mon == f.mon && this->mday == f.mday && this->hour == f.hour && this->min == f.min && this->sec == f.sec){
      return true;
    }else{
      return false;
    }
  }

 bool operator!=(const fecha & f)const {
	   if(this==f)
		         return false;
	     else
		           return true;
 }
