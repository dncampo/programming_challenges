/**
 * Title: HASHIT
 * URL: https://www.spoj.pl/problems/HASHIT/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
	 + Se utiliza un map<unsigned,string> para guardar cada clave/valor del hash. Esto tiene la 
	 ventaja sobre la implementación que usa vector en que sólo crea las claves que va necesitando,
	 evitando desperdicio innecesario de memoria.	 
**/

#include <iostream>
#include <map>
#include <string>

#define HASH_SIZE 101
#define COLLISION_ATTEMPTS 19

using namespace std;

void add(map<unsigned,string>&, string);
void del(map<unsigned,string>&, string);
int create_key(map<unsigned,string>&, string);
void print(map<unsigned,string>&);
map<unsigned,string>::iterator find(map<unsigned,string>&, string);

int main(){
	
	int cases;
	cin >> cases;
	
	for(int i = 0; i < cases ; i++){
		map <unsigned,string> hash;
		int operations;
		cin >> operations;
		
		for(int j = 0; j < operations; j++){ //ejecutamos las operaciones de cada caso
			string op;
			cin >> op;
			if('A' == op[0]) add(hash, op.substr(4));
			else if ('D' == op[0]) del(hash, op.substr(4));
		}
		print(hash);
	}
	return 0;
}

void add(map<unsigned,string>& hash, string val){
	
	// si el valor ya está ingresado, lo ignoramos
	if(hash.end() != find(hash, val))
		return;
	
	int key = create_key(hash,val);
	
	//si la clave está en el hash y además no se correponde con el valor a ingresar
	//entonces existe una colisión
	map<unsigned,string>::iterator it = hash.find(key);
	if(hash.end() != it) {
		for(int i = 1; i <= COLLISION_ATTEMPTS; i++){
			int new_key = key + i*i + 23*i;
			new_key %= HASH_SIZE;
			
			it = hash.find(new_key);
			if((hash.end() == it)){
				hash.insert(make_pair(new_key,val));
				return;
			}
		}	
	}
	else{ //it's ok
		hash.insert(make_pair(key,val));
	}
}

void del(map<unsigned,string>& hash, string val){
	map<unsigned,string>::iterator it = find(hash, val);
	if(hash.end() != it)
		hash.erase(it);		
	return;
}

//find: busca un valor en el hash
map<unsigned,string>::iterator find(map<unsigned,string>& hash, string val){
	map<unsigned,string>::iterator it = hash.begin();
	while(it != hash.end()){
		if(val == it->second) return it;
		it++;
	}
	return hash.end();
}

int create_key(map<unsigned,string>& hash, string val){
	int key = 0;
	for(unsigned i = 0; i < val.size(); i++){
		int ch = val[i];
		key += ch * (i + 1);
	}
	key *= 19;
	key %= HASH_SIZE;
	return key;	
}

void print(map<unsigned,string>& hash){
	cout << hash.size() << endl;
	map<unsigned,string>::iterator it = hash.begin();
	while (hash.end() != it){
		cout << it->first << ":" << it->second << endl;
		it++;
	}
}
