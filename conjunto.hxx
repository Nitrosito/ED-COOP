
using namespace std;


/*
//////////  CONJUNTO CLASS //////////////////////////////////
*/

conjunto::conjunto(){
}

conjunto::conjunto (const conjunto & d){
	vc = d.vc;
}

conjunto::iterator  conjunto::find( const long int & id) const{

}

conjunto::const_iterator  conjunto::find( const long int & id) const{

}

pair<conjunto::entrada,bool>  conjunto::find( const long int & id) const{
	pair<conjunto::entrada,bool> aux;
	int ini = 0;
	int fin = vc.size()-1;

	aux.second = false;
	while(fin >= ini && aux.second == false){
		int medio  = (fin+ini)/2;
		cout << "Buscando...." << endl;
		//buqueda binaria
		if(vc.at(medio).getID() == id){
			aux.first = vc.at(medio);
			aux.second = true;

		}
		else if(vc.at(medio).getID() < id){
			ini = medio +1;
		}
		else{
			fin = medio -1;
		}
	}
	return aux;
}

conjunto conjunto::findIUCR( const string & iucr) const{		//Preguntar si se deja con it o lo hacemos con []
	conjunto aux;
	vector<crimen>::const_iterator it;
	for(it = vc.begin(); it != vc.end(); it++){
		if(it->getIucr() == iucr){
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
	cout << "h" << endl;
	if(!find(e.getID()).second){
		int posicion = vc.size();
		int i = 0;
		bool mayor = false;

		while( i < vc.size() && !mayor){
			if(e.getID() < vc[i].getID()){
				posicion = i;
				mayor = true;
			}
			++i;
			cout << "hola" << endl;
		}
		cout << "antes insert:" << posicion <<endl;
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
	int medio  = (fin+ini)/2;
	bool esta = false;
	conjunto aux;
	while(fin >= ini){
		//buqueda binaria
		if(vc.at(medio).getID() == id){
			esta = true;
			vc.erase(vc.begin()+medio);
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
	int medio  = (fin+ini)/2;
	bool esta = false;
	conjunto aux;
	while(fin >= ini){
		//buqueda binaria
		if(vc.at(medio).getID() == e.getID()){
			esta = true;
			vc.erase(vc.begin()+medio);
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
		//os << D.vc.size() << endl;
		os << D.vc.at(i) << endl;
	}
	return os;
}

/*
//////////  CONJUNTO::ITERATOR CLASS //////////////////////////////////
*/

conjunto::iterator conjunto::begin() const{
	conjunto::iterator sal;
		sal.itv = vc.begin();
	        return sal;
}


conjunto::iterator conjunto::end() const{
	conjunto::iterator sal;
		sal.itv = vc.end();
	        return sal;
}

conjunto::iterator::iterator(){
}


conjunto::iterator::iterator(const conjunto::iterator & it)
  itv = it.itv;
}

const conjunto::entrada & operator*() const{
	return *itv;
}

conjunto::iterator iterator operator++(int){		//Post incremento
	conjunto::iterator aux;
	aux = this;
	++(*this);
	return aux;
}

conjunto::iterator iterator & operator++(){		//Pre incremento
	*this++;
	return this;
}

conjunto::iterator iterator operator--(int){
	conjunto::iterator aux;
	aux = this;
	--(*this);
	return aux;
}

conjunto::iterator iterator & operator--(){
	*this--;
	return this;
}

bool conjunto::iterator operator==(const iterator & it){
	if(itv == it.itv)
		return true;
	else
		return false;
}

bool conjunto::iterator operator!=(const iterator & it){
	if(itv != it.itv)
		return true;
	else
		return false;
}



/*
//////////  CONJUNTO::CONST_ITERATOR CLASS //////////////////////////////////
*/


conjunto::const_iterator const_iterator cbegin() const{
	conjunto::iterator sal;
		sal.c_itv = vc.begin();
	        return sal;
}

conjunto::const_iterator const_iterator cend() const{
	conjunto::iterator sal;
		sal.itv = vc.end();
	        return sal;
}

conjunto::const_iterator::const_iterator(){
}
conjunto::const_iterator::const_iterator(const const_iterator & it){
	itv = it.c_itv;
}
conjunto::const_iterator::const_iterator(const iterator & it){
	itv = it.c_itv;
}
const conjunto::entrada & conjunto::const_iterator operator*() const{
	return *c_itv;
}
conjunto::const_iterator const_iterator operator++( int ){
	conjunto::const_iterator aux;
	aux = *c_itv;
	++(*c_itv);
	return aux;
}
conjunto::const_iterator const_iterator & operator++(){
	*c_itv++;
	return *this;
}
conjunto::const_iterator const_iterator operator--(int){
	conjunto::const_iterator aux;
	aux = *c_itv;
	--(*c_itv);
	return aux;
}
conjunto::const_iterator const_iterator & operator--(){
	*c_itv--;
	return *this;
}
bool conjunto::const_iterator operator==(const const_iterator & it){
	if(c_itv == it)
		return true;
	else
		return false;
}
bool conjunto::const_iteratoroperator!=(const const_iterator & it){
	if(c_itv != it)
		return true;
	else
		return false;
}



// ============================== description iterator ===============================

conjunto::description_iterator  dbegin(const string & descr) const{
	conjunto::description_iterator d_it;
	d_it.c_itv = findDESCR(descr).vc.begin();
	return d_it;
}


conjunto::description_iterator  dend( ) const{
	conjunto::description_iterator d_it;
	d_it.c_itv = findDESCR(descr).vc.end();
	return d_it;
}


conjunto::description_iterator::description_iterator(){
}
conjunto::description_iterator::description_iterator(const description_iterator & it){
	descr = it.descr;
  	c_itv = it.c_itv;
}

const conjunto::entrada & conjunto::description_iterator operator*() const{
  	return *c_itv;																		//NO SE SI ES ESO LO QUE HAY QUE PONER
}
description_iterator conjunto::description_iterator operator++( int ){
  	conjunto::description_iterator aux;
  	aux = c_itv;
  	c_itv++;
  	return aux;
}
description_iterator & conjunto::description_iterator operator++(){
  	c_itv++;
  	return *this;
}
description_iterator conjunto::description_iterator operator--(int){
	conjunto::description_iterator aux;
  	aux = c_itv;
  	c_itv--;
  	return aux;
}
description_iterator & conjunto::description_iterator operator--(){
  	c_itv--;
  	return *this;
}
bool conjunto::description_iterator operator==(const description_iterator & it){
  	if(c_itv == it.c_itv && descr.compare(it.descr) == 0)
  		return true;
  	else
  		return false;
}
bool conjunto::description_iterator operator!=(const description_iterator & it){
  	if(c_itv != it.c_itv && descr.compare(it.descr) != 0)
  		return true;
  	else
  		return false;
}
