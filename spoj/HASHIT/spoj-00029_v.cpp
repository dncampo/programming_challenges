/*
Title: HASHIT
Tags: adhoc, hashing, maps
URL: https://www.spoj.pl/problems/HASHIT/
Resources of interest:
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Solution's notes:
    + A vector<string> is used to store the key/value of the hash. It is assumed
    * tht all places for keys (0 to 100) are created. 
*/

#include <iostream>
#include <vector>
#include <string>

#define HASH_SIZE 101
#define COLLISION_ATTEMPTS 19

using namespace std;

void add(vector<string>&, string);
void del(vector<string>&, string);
int create_key(vector<string>&, string);
void print(vector<string>&);
int find(vector<string>&, string);

int main(){
	
	int cases;
	cin >> cases;
	
	for(int i = 0; i < cases ; i++){
		vector <string> hash(HASH_SIZE,"");
		int operations;
		cin >> operations;
		
		for(int j = 0; j < operations; j++){
			string op;
			cin >> op;
			if('A' == op[0]) add(hash, op.substr(4));
			else if ('D' == op[0]) del(hash, op.substr(4));
		}
		print(hash);
	}
	return 0;
}

void add(vector<string>& hash, string val){
    // if the value is already inserted, must be ignored
	if(-1 != find(hash, val))
		return;
	
	int key = create_key(hash,val);

    // if the key already exists in the hash and it doesn't match with the value
    // to be stored, a collision occurs.
	if("" != hash[key]) {
		for(int i = 1; i <= COLLISION_ATTEMPTS; i++){
			int new_key = key + i*i + 23*i;
			new_key %= HASH_SIZE;
			
			if("" == hash[new_key])
			{
				hash[new_key] = val;
				return;
			}
		}	
	}
	else{ //it's ok
		hash[key] = val;
	}
}

void del(vector<string>& hash, string val){
	int key = find(hash, val);
	if(-1 != key)
		hash[key] = "";
		
	return;
}

int find(vector<string>& hash, string val){
	for(int i = 0; i < HASH_SIZE; i++)
		if(val == hash[i]) return i;
	return -1;
}

int create_key(vector<string>& hash, string val){
	int key = 0;
	for(unsigned i = 0; i < val.size(); i++){
		int ch = val[i];
		key += ch * (i + 1);
	}
	key *= 19;
	key %= HASH_SIZE;
	return key;	
}

void print(vector<string>& hash){
	vector<int> vals;
	for (int i = 0; i < HASH_SIZE; i++){
		if("" != hash[i]) vals.push_back(i);
	}
	cout << vals.size() << endl;
	for(unsigned j = 0; j < vals.size(); j++){
		cout << vals[j] << ":" << hash[vals[j]] << endl;
	}
}
