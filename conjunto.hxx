
using namespace std;

class ComparacionPorFecha {
 public:
   bool operator()(const crimen &a, const crimen &b) {
     return (a.getDate() < b.getDate()); // devuelve verdadero si el crimen a precede a b en el tiempo
 }
};


/*
//////////  CONJUNTO CLASS //////////////////////////////////
*/
template <typename CMP>
conjunto<CMP>::conjunto(){
}

template <typename CMP>
conjunto<CMP>::conjunto (const conjunto<CMP> & d){
  vc = d.vc;
  comp=d.comp;
}

template <typename CMP>
typename conjunto<CMP>::iterator  conjunto<CMP>::find( const long int & id){
  conjunto<CMP>::iterator sal;
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

template <typename CMP>
typename conjunto<CMP>::const_iterator  conjunto<CMP>::find( const long int & id) const{
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

template <typename CMP>
conjunto<CMP> conjunto<CMP>::findIUCR( const string & iucr) const{
  conjunto aux;
  vector<crimen>::const_iterator it;
  for(it = vc.begin(); it != vc.end(); it++){
    if((*it).getIucr() == iucr){
      aux.insert(*it);
    }
  }
  return aux;
}

template <typename CMP>
conjunto<CMP> conjunto<CMP>::findDESCR( const string & descr) const{
  conjunto aux;
  for (int i = 0; i < vc.size(); i++)
  {
    if (vc[i].getDescription() == descr){
      aux.insert(vc[i]);
    }
  }

  return aux;
}

template <typename CMP>
bool conjunto<CMP>::insert( const tconjunto<CMP>::entrada & e){
  if(find(e.getID()).itv == vc.end()) {
    int posicion = vc.size();
    int i = 0;
    bool mayor = false;

    while( i < vc.size() && !mayor){
      if(comp(e,vc[i])){
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

template <typename CMP>
bool conjunto<CMP>::erase(const long int & id){
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

template <typename CMP>
bool conjunto<CMP>::erase(const  conjunto<CMP>::entrada & e){
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

template <typename CMP>
conjunto<CMP> & conjunto<CMP>::operator=( const conjunto & org){
  vc = org.vc;
  return *this;
}

template <typename CMP>
typename conjunto<CMP>::size_type conjunto<CMP>::size() const{
  return vc.size();
}

template <typename CMP>
bool conjunto<CMP>::empty() const{
  return vc.empty();
}


template <typename CMP>
bool conjunto<CMP>::cheq_rep( ) const{
  //Todos los ID de crimen deben ser mayor que 0 , Tienen que estar ordenados de menor a mayor
  for(int i=0; i < vc.size(); i++){
    if((vc[i].getID() < 0) || ( vc[i].getID() > vc[i+1].getID() ) )
      return false;
  }
  return true;
}

template <typename CMP>
ostream &  operator << ( ostream & os, const conjunto<CMP> & D){
  for(unsigned int i = 0; i < D.size(); i++){
    os << D.vc[i] << endl;
  }
  return os;
}

/*
//////////  CONJUNTO::ITERATOR CLASS //////////////////////////////////
*/
template <typename CMP>
typename conjunto<CMP>::iterator conjunto<CMP>::begin(){
  conjunto<CMP>::iterator sal;
    sal.itv = vc.begin();
          return sal;
}

template <typename CMP>
typename conjunto<CMP>::iterator conjunto<CMP>::end(){
  conjunto<CMP>::iterator sal;
    sal.itv = vc.end();
          return sal;
}

template <typename CMP>
conjunto<CMP>::iterator::iterator(){
}

template <typename CMP>
conjunto<CMP>::iterator::iterator(const conjunto<CMP>::iterator & it){
  *this = it ;
}

template <typename CMP>
typename conjunto<CMP>::entrada & conjunto<CMP>::iterator::operator*(){
  return *itv;
}

template <typename CMP>
typename conjunto<CMP>::iterator  conjunto<CMP>::iterator::operator++(int){    //Post incremento
  conjunto<CMP>::iterator aux(*this);
  ++itv;
  return aux;
}

template <typename CMP>
typename conjunto<CMP>::iterator & conjunto<CMP>::iterator::operator++(){    //Pre incremento
  itv++;
  return *this;
}

template <typename CMP>
typename conjunto<CMP>::iterator conjunto<CMP>::iterator::operator--(int){
  conjunto<CMP>::iterator aux(*this);
  --itv;
  return aux;
}


template <typename CMP>
typename conjunto<CMP>::iterator & conjunto<CMP>::iterator::operator--(){
  itv--;
  return *this;
}


template <typename CMP>
bool conjunto<CMP>::iterator::operator==(const conjunto<CMP>::iterator & it){
  if(itv == it.itv)
    return true;
  else
    return false;
}


template <typename CMP>
bool conjunto<CMP>::iterator::operator!=(const conjunto<CMP>::iterator & it){
  if(itv != it.itv)
    return true;
  else
    return false;
}



/*
//////////  CONJUNTO::CONST_ITERATOR CLASS //////////////////////////////////
*/

template <typename CMP>
typename conjunto<CMP>::const_iterator conjunto<CMP>::cbegin() const{
  conjunto<CMP>::const_iterator sal;
    sal.c_itv = vc.begin();
          return sal;
}

template <typename CMP>
typename conjunto<CMP>::const_iterator conjunto<CMP>::cend() const{
  conjunto<CMP>::const_iterator sal;
    sal.c_itv = vc.end();
          return sal;
}

template <typename CMP>
conjunto<CMP>::const_iterator::const_iterator(){
}

template <typename CMP>
conjunto<CMP>::const_iterator::const_iterator(const conjunto<CMP>::const_iterator & it){
  c_itv = it.c_itv;
}

template <typename CMP>
conjunto<CMP>::const_iterator::const_iterator(const conjunto<CMP>::iterator & it){
  c_itv = it.itv;
}

template <typename CMP>
const typename conjunto<CMP>::entrada & conjunto<CMP>::const_iterator::operator*() const{
  return *c_itv;
}

template <typename CMP>
typename conjunto<CMP>::const_iterator conjunto<CMP>::const_iterator::operator++( int ){
  conjunto<CMP>::const_iterator aux(*this);
  ++c_itv;
  return aux;
}

template <typename CMP>
typename conjunto<CMP>::const_iterator & conjunto<CMP>::const_iterator::operator++(){
  c_itv++;
  return *this;
}

template <typename CMP>
typename conjunto<CMP>::const_iterator conjunto<CMP>::const_iterator::operator--(int){
  conjunto::const_iterator aux(*this);
  --c_itv;
  return aux;
}

template <typename CMP>
typename conjunto<CMP>::const_iterator & conjunto<CMP>::const_iterator::operator--(){
  c_itv--;
  return *this;
}

template <typename CMP>
bool conjunto<CMP>::const_iterator::operator==(const conjunto<CMP>::const_iterator & it){
  if(c_itv == it.c_itv)
    return true;
  else
    return false;
}

template <typename CMP>
bool conjunto<CMP>::const_iterator::operator!=(const conjunto<CMP>::const_iterator & it){
  if(c_itv != it.c_itv)
    return true;
  else
    return false;
}
