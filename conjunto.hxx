	




conjunto(){
}

conjunto (const conjunto & d){
	vc = d.vc; 
}
	
pair<conjunto::entrada,bool>  find( const long int & id) const{
	pair<conjunto::entrada,bool> aux;
	vector<conjunto::entrada>::iterator it;
	for(it = vc.begin(); it != vc.end(); it++){
		if(it->ID == id){
			aux.first() = it;
			aux.second() = true;
		}
		else
			aux.second() = false;
	}
	return aux;
}

conjunto findIUCR( const string & iucr) const{
	
}

conjunto   findDESCR( const string & descr) const;

bool insert( const conjunto::entrada & e);

bool erase(const long int & id);


bool erase(const  conjunto::entrada & e);
     
conjunto & operator=( const conjunto & org);

size_type size() const{
	return v.size();
}

bool empty() const;

	
	 
	 
	   
	 
private:
 vector<crimen> vc; 


	

  bool cheq_rep( ) const;

  friend ostream &  operator << ( ostream & sal, const conjunto & D);
 

};


ostream &  operator << ( ostream & sal, const conjunto & D);