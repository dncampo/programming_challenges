/**
 * Title: Prime Ring Problem 
 * URL: http://acm.uva.es/p/v5/524.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   + Esta solución trata de simplificar la implementación de acm-00524.cpp y optimizar la forma de impresión.
**/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<char> data;
vector<string> solutions;

char primes[] = {0,1,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0 };


vector<vector<char> > primes;

void process_solution(int n){
   for(int i = 0; i < data.size(); i++){
      if(data[i] > 9){
         solutions[n].append(1, '0' + data[i] / 10 );
         solutions[n].append(1, '0'+ data[i] % 10);
      } else {
         solutions[n].append(1, '0'+data[i] );
      }
      if(i+1 < data.size())
         solutions[n].append(1, ' ');
   }  
   solutions[n].append(1, '\n');
}

bool solution(int n){
   return n == data.size();
}

void get_candidates(vector<char> & c, int size){
   if(data.size() == 0){
      c.push_back(1);
      return;
   }
   char cand[size+1], last_value = *(--data.end());
   
   for(char i = 2; i <= size; i++){
      cand[i] = 1;
   }

   // eliminar los que ya están     
   for(char i = 0; i < data.size(); i++){
      cand[data[i]] = 0;
   }

   for(char i = 2; i <= size; i++){   
      if(cand[i] && primes[i+last_value]){
         if(data.size()+1 == size && !primes[1 + i]){
            continue;
         }
         c.push_back(i);
      }
   }						
}

void backtracking(int n){
   if(solution(n)){
      process_solution(n);
   } else {
      vector<char> candidates;

      get_candidates(candidates, n);

      for(int i = 0; i < candidates.size(); i++){
         data.push_back(candidates[i]);
         backtracking(n);
         data.erase(--data.end());
      }
   }
}

int main(){
   solutions.resize(17);

   backtracking(1);  
   
   for(int i = 2; i < 17; i += 2){
      backtracking(i);
   }
    
  int value, cont = 0;
  
   while(cin >> value){
      if(cont > 0){
         cout << '\n';
      }
      cout << "Case " << ++cont << ":\n" << solutions[value];
  }  
  
  return 0;
}
