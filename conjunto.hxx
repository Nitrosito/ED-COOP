
using namespace std;


/*
//////////  CONJUNTO CLASS //////////////////////////////////
*/

conjunto::conjunto(){
}

conjunto::conjunto (const conjunto & d){
  vc = d.vc;
}

conjunto::iterator  conjunto::find( const long int & id){
  conjunto::iterator sal;
int ini = 0;
  int fin = vc.size()-1;
  int medio;
  bool aux = false;
  while(fin >= ini && aux == false){
    medio  = (fin+ini)/2;
    //buqueda binaria
    if(vc.at(medio).getID() == id){
      aux = true;

    }
    else if(vc.at(medio).getID() < id){
      ini = medio +1;
    }
    else{
      fin = medio -1;
    }
  }
  if(aux)
    sal.itv = vc.begin()+medio;
  else
    sal.itv =vc.end();

  return sal;
}

conjunto::const_iterator  conjunto::find( const long int & id) const{
  conjunto::const_iterator sal;
  int ini = 0;
    int fin = vc.size()-1;
    int medio;
    bool aux = false;
    while(fin >= ini && aux == false){
      medio  = (fin+ini)/2;
      //buqueda binaria
      if(vc.at(medio).getID() == id){
        aux = true;

      }
      else if(vc.at(medio).getID() < id){
        ini = medio +1;
      }
      else{
        fin = medio -1;
      }
    }
    if(aux)
      sal.c_itv = vc.begin()+medio;
    else
      sal.c_itv = vc.end();

    return sal;
}

conjunto conjunto::findIUCR( const string & iucr) const{
  conjunto aux;
  vector<crimen>::const_iterator it;
  for(it = vc.begin(); it != vc.end(); it++){
    if((*it).getIucr() == iucr){
      aux.insert(*it);
    }
  }
  return aux;
}


conjunto conjunto::findDESCR( const string & descr) const{
  conjunto aux;
  for (int i = 0; i < vc.size(); i++)
  {
    if (vc[i].getDescription() == descr){
      aux.insert(vc[i]);
    }
  }

  return aux;
}

bool conjunto::insert( const conjunto::entrada & e){
  if(find(e.getID()).itv == vc.end()) {
    int posicion = vc.size();
    int i = 0;
    bool mayor = false;

    while( i < vc.size() && !mayor){
      if(e.getID() < vc[i].getID()){
        posicion = i;
        mayor = true;
      }
      ++i;
    }
    vc.insert(vc.begin()+posicion,e);
    return true;
  }
  else{
    return false;
    cout << "adios" << endl;
  }
}

bool conjunto::erase(const long int & id){
  int ini = 0;
  int fin = vc.size()-1;
  int medio;
  bool esta = false;
  //conjunto aux;
  while(fin >= ini){
    medio  = (fin+ini)/2;
    //buqueda binaria
    if(vc.at(medio).getID() == id){
      esta = true;
      vc.erase(vc.begin()+medio);
      return esta;
    }
    else if(vc.at(medio).getID() < id){
      ini = medio +1;
    }
    else{
      fin = medio -1;
    }
  }
  return esta;

}


bool conjunto::erase(const  conjunto::entrada & e){
  int ini = 0;
  int fin = vc.size()-1;
  int medio;
  bool esta = false;
  //conjunto aux;
  while(fin >= ini){
    //buqueda binaria
    medio  = (fin+ini)/2;
    if(vc.at(medio).getID() == e.getID()){
      esta = true;
      vc.erase(vc.begin()+medio);
      return esta;
    }
    else if(vc.at(medio).getID() < e.getID()){
      ini = medio +1;
    }
    else{
      fin = medio -1;
    }
  }
  return esta;
}

conjunto & conjunto::operator=( const conjunto & org){
  vc = org.vc;
  return *this;
}

conjunto::size_type conjunto::size() const{
  return vc.size();
}

bool conjunto::empty() const{
  return vc.empty();
}



bool conjunto::cheq_rep( ) const{
  //Todos los ID de crimen deben ser mayor que 0 , Tienen que estar ordenados de menor a mayor
  for(int i=0; i < vc.size(); i++){
    if((vc[i].getID() < 0) || ( vc[i].getID() > vc[i+1].getID() ) )
      return false;
  }
  return true;
}

ostream &  operator << ( ostream & os, const conjunto & D){
  for(unsigned int i = 0; i < D.size(); i++){
    os << D.vc[i] << endl;
  }
  return os;
}

/*
//////////  CONJUNTO::ITERATOR CLASS //////////////////////////////////
*/

conjunto::iterator conjunto::begin(){
  conjunto::iterator sal;
    sal.itv = vc.begin();
          return sal;
}


conjunto::iterator conjunto::end(){
  conjunto::iterator sal;
    sal.itv = vc.end();
          return sal;
}

conjunto::iterator::iterator(){
}


conjunto::iterator::iterator(const conjunto::iterator & it){
  *this = it ;
}

conjunto::entrada & conjunto::iterator::operator*(){
  return *itv;
}

conjunto::iterator  conjunto::iterator::operator++(int){    //Post incremento
  conjunto::iterator aux(*this);
  ++itv;
  return aux;
}

conjunto::iterator & conjunto::iterator::operator++(){    //Pre incremento
  itv++;
  return *this;
}

conjunto::iterator conjunto::iterator::operator--(int){
  conjunto::iterator aux(*this);
  --itv;
  return aux;
}

conjunto::iterator & conjunto::iterator::operator--(){
  itv--;
  return *this;
}

bool conjunto::iterator::operator==(const conjunto::iterator & it){
  if(itv == it.itv)
    return true;
  else
    return false;
}

bool conjunto::iterator::operator!=(const conjunto::iterator & it){
  if(itv != it.itv)
    return true;
  else
    return false;
}



/*
//////////  CONJUNTO::CONST_ITERATOR CLASS //////////////////////////////////
*/


conjunto::const_iterator conjunto::cbegin() const{
  conjunto::const_iterator sal;
    sal.c_itv = vc.begin();
          return sal;
}

conjunto::const_iterator conjunto::cend() const{
  conjunto::const_iterator sal;
    sal.c_itv = vc.end();
          return sal;
}

conjunto::const_iterator::const_iterator(){
}
conjunto::const_iterator::const_iterator(const conjunto::const_iterator & it){
  c_itv = it.c_itv;
}
conjunto::const_iterator::const_iterator(const conjunto::iterator & it){
  c_itv = it.itv;
}
const conjunto::entrada & conjunto::const_iterator::operator*() const{
  return *c_itv;
}
conjunto::const_iterator conjunto::const_iterator::operator++( int ){
  conjunto::const_iterator aux(*this);
  ++c_itv;
  return aux;
}
conjunto::const_iterator & conjunto::const_iterator::operator++(){
  c_itv++;
  return *this;
}
conjunto::const_iterator conjunto::const_iterator::operator--(int){
  conjunto::const_iterator aux(*this);
  --c_itv;
  return aux;
}
conjunto::const_iterator & conjunto::const_iterator::operator--(){
  c_itv--;
  return *this;
}
bool conjunto::const_iterator::operator==(const conjunto::const_iterator & it){
  if(c_itv == it.c_itv)
    return true;
  else
    return false;
}
bool conjunto::const_iterator::operator!=(const conjunto::const_iterator & it){
  if(c_itv != it.c_itv)
    return true;
  else
    return false;
}
