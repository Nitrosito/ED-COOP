conjunto(){
}

conjunto (const conjunto & d){
	vc = d.vc; 
}
	
pair<conjunto::entrada,bool>  find( const long int & id) const{
	pair<conjunto::entrada,bool> aux;
	int ini = 0;
	int fin = vc.size()-1;
	int medio  = (fin+ini)/2;
	aux.second = false;
	while(fin >= ini && aux.second == false){
		//buqueda binaria
		if(vc.at(medio) == id){
			aux.first = vc.at(medio);
			aux.second = true;

		}
		else if(vc.at(medio) < id){
			ini = medio +1;
		}
		else{
			fin = medio -1;
		}
	}
	return aux;
}

conjunto findIUCR( const string & iucr) const{
	conjunto aux;
	vector<conjunto::entrada>::iterator it;
	for(it = vc.begin(); it != vc.end(); it++){
		if(it->iucr == iucr){
			aux.insert(*it);
		}
	}	
	return aux;
}


conjunto   findDESCR( const string & descr) const;

bool insert( const conjunto::entrada & e);

bool erase(const long int & id);


bool erase(const  conjunto::entrada & e);
     
conjunto & operator=( const conjunto & org);

size_type size() const{
	return v.size();
}

bool empty() const{
	if(vc.size() == 0)
		return true;

	return false;
}

	

bool cheq_rep() const{
	//Todos los ID de crimen deben ser mayor que 0 , Tienen que estar ordenados de menor a mayor
	while(int i=0; i < vc.size()-1; i++){
		if((vc.at(i).getID() > 0) == false || ( vc.at(i).getID() > vc.at(i+1).getID() ) 
			return false;
	}
	return true;
}

friend ostream &  operator << ( ostream & sal, const conjunto & D);
 

};


ostream &  operator << ( ostream & sal, const conjunto & D);
