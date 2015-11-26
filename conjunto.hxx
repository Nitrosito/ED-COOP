
using namespace std;

class FechaCreciente {
 public:
   bool operator()(const crimen &a, const crimen &b) {
     return (a.getDate() < b.getDate()); // devuelve verdadero si el crimen a precede a b en el tiempo
 }
};

class FechaDecreciente {
 public:
   bool operator()(const crimen &a, const crimen &b) {
     return (a.getDate() > b.getDate()); // devuelve verdadero si el crimen a precede a b en el tiempo
 }
};


class CrecienteIUCR{
public:
  bool operator()(const crimen &a, const crimen &b) {
    return (a.getIucr() < b.getIucr()); // devuelve verdadero si el crimen a precede a b en el tiempo
  }
};




/*
//////////  CONJUNTO CLASS //////////////////////////////////
*/
template <typename CMP>
conjunto<CMP>::conjunto(){
}

template <typename CMP>
conjunto<CMP>::conjunto(iterator ini, iterator fin){
  while(ini!=fin){
    vc.push_back(*ini);
    ini++;
  }
}

template <typename CMP>
conjunto<CMP>::conjunto (const conjunto<CMP> & d){
  vc = d.vc;
  comp=d.comp;
}

template <typename CMP>
typename conjunto<CMP>::iterator  conjunto<CMP>::find( const long int & id){
  conjunto<CMP>::iterator sal;
  for(int i=0; i < vc.size();i++){
    if(vc[i].getID()==id){
      sal.itv=vc.begin()+i;
      return sal;
    }
  }
  sal.itv=vc.end();
  return sal;
}


template <typename CMP>
typename conjunto<CMP>::const_iterator  conjunto<CMP>::find( const long int & id) const{
  conjunto<CMP>::const_iterator sal;
  for(int i=0; i < vc.size();i++){
    if(vc[i].getID()==id){
      sal.c_itv=vc.begin()+i;
      return sal;
    }
  }
  sal.c_itv=vc.end();
  return sal;
}

template <typename CMP>
typename conjunto<CMP>::iterator conjunto<CMP>::find(const crimen & c){             //Busqueda binaria y devuelve un iterador a la posicion o end()
    conjunto<CMP>::iterator sal;

    int sup=vc.size()-1;
    int medio;
    int inf = 0;
    while (sup > inf) {
       medio = (inf+sup)/2;
      if (!comp(vc[medio],c) && !comp(c,vc[medio]) ){// comparamos igualdad entre crimen
        sal.itv = vc.begin()+medio;
        return sal;
      }
      else if (comp(vc[medio],c)) // comparamos menor entre crimen
        inf = medio+1;
      else
        sup = medio-1;
    }
    sal.itv=vc.end();
    return sal;
}

template <typename CMP>
typename conjunto<CMP>::const_iterator conjunto<CMP>::find(const crimen & c)const{
    conjunto<CMP>::const_iterator sal;

    int sup=vc.size()-1;
    int inf = 0;
    int medio;
    while (sup > inf) {
      medio = (inf+sup)/2;
      if (!comp(vc[medio],c) && !comp(c,vc[medio]) ){// comparamos igualdad entre crimen
        sal.c_itv = vc.begin()+medio;
        return sal;
      }
      else if (comp(vc[medio],c)) // comparamos menor entre crimen
        inf = medio+1;
      else
        sup = medio-1;
    }
    sal.c_itv=vc.end();
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
bool conjunto<CMP>::insert( const conjunto<CMP>::entrada & e){
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

template <typename CMP>
typename conjunto<CMP>::iterator conjunto<CMP>::lower_bound (const entrada & x){
  conjunto<CMP>::iterator sal;
  int sup=vc.size()-1;
  int medio;
  int inf = 0;
  while (sup > inf) {
     medio = (inf+sup)/2;
    if (!comp(vc[medio],x)){
      sal.itv=vc.begin()+medio;
      return sal;
    }
    else if (comp(vc[medio],x)) // comparamos menor entre crimen
      inf = medio+1;
    else
      sup = medio-1;
  }
  sal.itv=vc.end();
  return sal;
}

template <typename CMP>
typename conjunto<CMP>::iterator conjunto<CMP>::upper_bound (const entrada & x){
  conjunto<CMP>::iterator sal;
  int sup=vc.size()-1;
  int medio;
  int inf = 0;
  while (sup > inf) {
     medio = (inf+sup)/2;
    if (comp(vc[medio],x)){
      sal.itv=vc.begin()+medio;
      return sal;
    }
    else if (!comp(vc[medio],x)) // comparamos menor entre crimen
      inf = medio+1;
    else
      sup = medio-1;
  }
  sal.itv=vc.end();
  return sal;
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
bool conjunto<CMP>::const_iterator::operator==(const typename conjunto<CMP>::const_iterator & it){       //esto seria const typename conjunto<CMP>::const_iterator & it???????
  if(c_itv == it.c_itv)
    return true;
  else
    return false;
}

template <typename CMP>
typename conjunto<CMP>::const_iterator conjunto<CMP>::lower_bound (const entrada & x) const{ //PREGUNTAR
    conjunto::const_iterator cit;
    cit=begin();

    while(cit!=end()){
        if(!comp(*cit,x))
        return cit;

        cit++;
    }
    return end();

}

template <typename CMP>
typename conjunto<CMP>::const_iterator conjunto<CMP>::upper_bound (const entrada & x) const{
    conjunto::const_iterator cit;
    cit=begin();

    while(cit!=end()){
        if(comp(*cit,x))
        return cit;

        cit++;
    }
    return end();
}


template <typename CMP>
bool conjunto<CMP>::const_iterator::operator!=(const conjunto<CMP>::const_iterator & it){
  if(c_itv != it.c_itv)
    return true;
  else
    return false;
}
