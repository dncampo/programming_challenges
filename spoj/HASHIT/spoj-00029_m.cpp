/*
Title: HASHIT
Tags: adhoc, hashing, maps
URL: https://www.spoj.pl/problems/HASHIT/
Resources of interest:
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Solution's notes:
    + A map<unsigned, string> is used to store the key/value of the hash.
*/

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
		
		for(int j = 0; j < operations; j++){ //try the operations of each case
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
	
	// if the value is already inserted, ignore it
	if(hash.end() != find(hash, val))
		return;
	
	int key = create_key(hash,val);
	
    // if the key exists in the hash, there is a collision
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

//find: search a value in the hash
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
