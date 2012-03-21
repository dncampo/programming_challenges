/**
 * Title: Generating Fast, Sorted Permutation
 * URL: http://online-judge.uva.es/p/v100/10098.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   Se utiliza backtracking para resolver el problema.
   Primero se ordena la entrada en forma ascendente,
   luego se llama a la funcion backtracking que calcula e imprime cada resultado.
   Hay que tener en cuenta que en la funcion get_candidates hay
   que tener cuidado de no retornar dos candidatos iguales.
**/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> data;
string in;

void get_candidates(vector<char> &candidates){
   for(int i = 0; i < in.size(); i++){
      candidates.push_back(in[i]);
   }
     
   for(int i = 0; i < data.size(); i++){
      vector<char>::iterator it;
      for(it = candidates.begin(); it != candidates.end() && *it != data[i] ; it++);

      if(it != candidates.end())
         candidates.erase(it);
   }
   
   for(int i = 0; i < candidates.size(); i++){
      for (int j = i+1; j < candidates.size();){
         if(candidates[j] == candidates[i]){
            candidates.erase(candidates.begin()+j);
         }else {
            j++;
         }
      }
   }
}

void backtracking(){
	if(data.size() == in.size()){
		for(int i = 0; i < data.size(); i++){
		   printf("%c", data[i]);
		}
		
	   printf("\n");
	}else{
		vector<char> candidates;

		get_candidates(candidates);
		
		for(unsigned i = 0; i < candidates.size(); i++){
			data.push_back(candidates[i]);
			backtracking();
			data.pop_back();
		}
	}
}


int main(){
   int cases;
   
   cin >> cases;
   
   for(int c = 0; c < cases; c++){
      cin >> in;
      
      for(int i = 0; i < in.size()-1; i++){
         for(int j = i+1; j < in.size(); j++){      
            if(in[i] > in[j]){
               swap(in[i], in[j]); 
            }
         }
      }
      
      backtracking();
      cout << endl;
   }
	return 0;
}

