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
  mon = stoi(aux);
  aux = s.substr(3,2);
  mday = stoi(aux);
  aux = s.substr(6,4);
  year = stoi(aux);
  aux = s.substr(11,2);
  hour = stoi(aux);
  aux = s.substr(14,2);
  min = stoi(aux);
  aux = s.substr(17,2);
  sec = stoi(aux);
  aux = s.substr(20,2);
  if(aux.compare("PM") == 0)
    hour = 12+hour;

}

fecha::fecha(const fecha& f){
  sec = f.sec;
  min = f.min;
  hour = f.hour;
  mday = f.mday;
  mon = f.mon;
  year = f.year;
}

fecha & fecha::operator=(const fecha & f){
	this->sec = f.sec;
	this->min = f.min;
	hour = f.hour;
	mday = f.mday;
	mon = f.mon;
	year = f.year;

  return *this;
}

fecha & fecha::operator=(const string & s){
	fecha f(s);
  *this = f;

  return *this;
}

string fecha::toString()const{
  string s = to_string(mon)+"/"+to_string(mday)+"/"+to_string(year)+" ";
  string m;
  if(hour < 12){
    s = s+to_string(hour);
    m = " AM";
  }
  else{
    s = s+to_string(hour-12);
    m = " PM";
  }
  s = s+":"+to_string(min)+":"+to_string(sec)+m;
  return s;
}    

  //Compara fechas, si UNA ES IGUAL A OTRA
bool fecha::operator==(const fecha & f) const{
  if(this->year == f.year && this->mon == f.mon && this->mday == f.mday && this->hour == f.hour && this->min == f.min && this->sec == f.sec){
    return true;
  }else{
    return false;
  }
}

//Compara fechas, sin UNA ES ANTERIOR A otra
bool fecha::operator<(const fecha & f)const{
    if(this->year < f.year){
      return true;
    }else if(this->year > f.year){
      return false;
    }else{
      if(this->mon < f.mon){
        return true;
      }else if(this->mon > f.mon){
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
              }else if(this->sec >=f.sec){
                return false;
              }
            }
          } 
        }
      }
    }
}

bool fecha::operator>(const fecha & f) const{
  if(year > f.year){
    return true;
  }
  else if(year < f.year){
    return false;
  }
  else{
    if(mon > f.mon){
    return true;
    }
    else if(mon < f.mon){
      return false;
    }
    else{
      if(mday > f.mday){
      return true;
      }
      else if(mday < f.mday){
        return false;
      }
      else{
        if(hour > f.hour){
        return true;
        }
        else if(hour < f.hour){
          return false;
        }
        else{
          if(min > f.min){
          return true;
          }
          else if(min < f.min){
            return false;
          }
          else{
            if(sec > f.sec){
            return true;
            }
            else{
              return false;
            }
          }
        }
      }
    }
  }
}

// Compara fechas, si una es ANTERIOR O IGUAL A otra
bool fecha::operator<=(const fecha & f) const{
 if(this->year < f.year){
   return true;
  }
  else if(this->year > f.year){
   return false;
  }
  else{
   if(this->mon < f.mon){
     return true;
    }
    else if(this->mon < f.mon){
     return false;
    }
    else{
     if(this->mday < f.mday){
       return true;
      }
      else if(this-> mday > f.mday){
       return false;
      }
      else{
       if(this->hour < f.hour){
         return true;
        }
        else if(this->hour > f.hour){
         return false;
        }
        else{
         if(this->min < f.min){
           return true;
          }
          else if(this->min > f.min){
           return false;
          }
          else{
           if(this->sec <= f.sec){
             return true;
            }
            else if(this->sec >f.sec){
             return false;
            }
          }
        }
      }
    }
  }
}

   
bool fecha::operator>=(const fecha & f) const{
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
						if(this->sec >= f.sec)
							return true;
						else if(this->sec < f.sec)
						       return false;
					}
				}
			}											
		}
	}
}

  
bool fecha::operator!=(const fecha & f)const {
  if(*this==f)
    return false;
  else
    return true;
}

ostream& operator<<( ostream &os, const fecha & f){
  os << f.mon << "/" << f.mday << "/" << f.year << " " << f.hour << ":" << f.min << ":" << f.sec; 
  return os;
}