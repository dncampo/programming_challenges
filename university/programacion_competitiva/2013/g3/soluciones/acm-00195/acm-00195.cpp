/**
 * Title: Anagram
 * URL: http://online-judge.uva.es/p/v1/195.html
 * Resources of interest:
 * Solver group: Yeyo-David
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   Se utiliza backtracking para implementar la solución.
   Para definir el orden en que se ordena el alfabeto se utiliza
   un map(m) en donde de asocia todas las letras con su peso, además
   se define una función compare que permite comparar dos caracteres
   utilizando el map.
**/

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

vector<char> data;
vector<char> in;
map<char, int> m;
char tmp[10000];

bool compare(char c, char d){
   return m[c] < m[d];
}

bool is_solution(){
	return data.size() == in.size();
}

void process_solution(){
	for (unsigned i = 0; i < data.size(); i++) {
	   printf("%c", data[i]);
	}	
	
	printf("\n");
}

void get_candidates(set<char, bool(*)(char, char)> &candidates){
   vector <char> tmp = in;
   
   for(unsigned i = 0; i < data.size(); i++) {
      tmp.erase( find(tmp.begin(), tmp.end(), data[i]));
   }
   for (unsigned i = 0; i < tmp.size(); i++){
      candidates.insert(tmp[i]);
   }
}

void backtracking(){
	if(is_solution()){
		process_solution();
	}else{
		set<char, bool(*)(char, char)> candidates(compare);

		get_candidates(candidates);
		
		for(set<char>::iterator it = candidates.begin(); it != candidates.end(); it++){
			data.push_back(*it);
			backtracking();
			data.pop_back();
		}
	}
}

void init(){
   int index = 1;
   
   for(char c = 'a', d = 'A'; c <= 'z'; c++, d++, index += 2){
      m[c]= index + 1;
      m[d]= index;
   }
}

int main(){
	unsigned n_cases;
   	
	scanf("%u",&n_cases);

   init();
      
	for(unsigned i = 0; i < n_cases; i++) {
      scanf ("%s", tmp);
      
      for(unsigned j = 0; j < strlen (tmp); j++){
         in.push_back (tmp[j]);
      }

      sort(in.begin(), in.end(), compare);    
      backtracking();
      
      data.clear();
      in.clear();
	}

	return 0;
}



