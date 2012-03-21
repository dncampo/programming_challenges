/**
 * Title: Prime Ring Problem 
 * URL: http://acm.uva.es/p/v5/524.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
    + Idem resolución acm-00524-fast.cpp con algunas optimizaciones:
    + - Utiliza un vector primes_list para precalcular todos los valores 
    + que son posibles expandir a partir de un número dado.
    + - Utiliza un vector candidates que se va actualizando a medida que se
    + realiza elbacktracking. Esto es para evitar tener que generarlo cada 
    + vez que se llama a la función get_candidates.
    + - En todos los vectores y string se reserva de antemano la capacidad necesaria.
**/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<char> data;
char data_size;
vector<char> candidates;

vector<string > solutions;
vector<char > to_solve;
int solutions_index;

char primes[] = {0,1,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0 };

vector<vector<char> > primes_list;

void init(){
   primes_list.resize(17);
   
   for(int i = 1; i < 17; i++){
      for(int j = 1; j < 17; j++){
         if(primes[i+j] && i != j){
            primes_list[i].push_back(j);
         }
      }
   }
   to_solve.assign(17, 1);
   
   for(int i = 3; i < 17; i+=2){
      to_solve[i] = 0;
   }
   
   solutions.resize(17);
   solutions[1].resize(2);   
   solutions[2].resize(4);
   solutions[4].resize(16);
   solutions[6].resize(24);
   solutions[8].resize(64);
   solutions[10].resize(2016);
   solutions[12].resize(27648);
   solutions[14].resize(95040);
   solutions[16].resize(3159936); 
}

void process_solution(int n){
   for(int i = 0; i < data_size; i++){
      if(data[i] > 9){
         char value = data[i]/10;
         solutions[n][solutions_index++] = '0' + value;
         solutions[n][solutions_index++] = '0'+ data[i]-10*value;
      } else {
         solutions[n][solutions_index++] = '0' + data[i];
      }
      
      if(i+1 < data_size)
         solutions[n][solutions_index++] = ' ';
   }  
   
   solutions[n][solutions_index++] = '\n';
}

inline char solution(int n){
   return n == data_size;
}

void get_candidates(vector<char> & c, int size){
   if(data_size == 0){
      c.push_back(1);
      return;
   }

   char last_value = data[data_size-1];
   vector<char> *primesc = &primes_list[last_value];
   char count = primesc->size();
   
   c.reserve(count);

   for(char i = 0; i < count ; i++){   
      char value = (*primesc)[i];
      if(value > size) 
         break;
      if(candidates[value] || data_size+1 == size && !primes[1 + value]){
         continue;
      }
      c.push_back(value);
   }
}

void backtracking(int n){
   if(solution(n)){
      process_solution(n);
   } else {
      vector<char> c;

      get_candidates(c, n);

      for(int i = 0; i < c.size(); i++){
         data[data_size++] = c[i];
         candidates[c[i]] = 1;
         backtracking(n);
         data_size--;
         candidates[c[i]] = 0;
      }
   }
}

void solve(int i){
   solutions_index = 0;
   candidates.clear();
   candidates.assign(i+1, 0);
   data.resize(i);
   backtracking(i);   
   to_solve[i]  = 0;
}

int main(){
   init();

   solve(1);

  int value, cont = 0;

   while(cin >> value){
      if(cont > 0){
         cout << '\n';
      }
      
      if(to_solve[value]){
         solve(value);
      }
      cout << "Case " << ++cont << ":\n" << solutions[value];
  }  
  
  return 0;
}

