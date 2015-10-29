	




conjunto(){
}

conjunto (const conjunto & d){
	vc = d.vc; 
}
	
pair<conjunto::entrada,bool>  find( const long int & id) const{
	
}

conjunto findIUCR( const string & iucr) const{
	for(conjunto::v)
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