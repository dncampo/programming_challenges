/**
 * Title: GNU = GNU'sNotUnix
 * URL: http://online-judge.uva.es/p/v106/10625.html
 * Resources of interest:
 * Solver group: Leo-Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
    + Definimos una estructura de datos Rule que se utiliza para representar una regla.
    + La solución consiste en simular el problema:
    + 1) Se lee todas las reglas
    + 2) Para cada consulta se realiza un simulación de las n iteraciones
    + 3) Se imprime la solución
**/
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

struct Rule{
   int r;
   unsigned long long rules[94];
   bool empty;
   
   void init(string & str){
      r = str[0] - 33;
      memset(rules, 0, sizeof(rules));
      empty = true;
      
      if(str.size() > 3){
         empty = false;
      
         for(unsigned k=3; k<str.size(); k++){
            rules[str[k] - 33]++;
         }
      }
   }
};

vector<Rule> rules;
unsigned long long letters[94];

void solve(string &initial, int iterations, int query){
   // clean data
   memset(letters, 0, sizeof(letters));
         
   // initial value         
   for(unsigned k=0; k<initial.size(); k++){
      letters[initial[k] - 33]++;
   }
   
   // simulate "n" iterations
   for(int it=0; it<iterations; it++){
      unsigned long long temp[94];
      memset(temp, 0, sizeof(temp));
      vector<int> to_zero;
               
      for(unsigned k=0; k<rules.size(); k++){
         if(letters[rules[k].r] > 0){
            if(rules[k].empty){
               to_zero.push_back(rules[k].r);
            } else{
               for(int w=0; w<94; w++){
                  if(w == rules[k].r){
                     if(rules[k].rules[w] == 0){
                        to_zero.push_back(rules[k].r);
                     } else {
                        temp[w] += (rules[k].rules[w]-1)* letters[rules[k].r];
                     }
                  } else{
                     temp[w] += rules[k].rules[w] * letters[rules[k].r];
                  }
               }
            }
         }
      }
      // update the results of applying the rules
      for(unsigned i = 0; i < to_zero.size(); i++){
         letters[to_zero[i]] = 0;
      }
      for(int i = 0; i < 94; i++){
         letters[i] += temp[i];
      }
   }
   
   // print the solution
   cout << letters[query - 33] << endl;
}

int main(){
   int t, r, q;
   
   cin >> t;
   
   for(int i=0; i<t; i++){
      cin >> r;
      //clean all rules   
      rules.clear();
      
      //read and add new rules
      for(int j=0; j<r; j++){
         string str;
         cin >> str;
         
         Rule rule;
         rule.init(str);

         rules.push_back(rule);
      }
       
      cin >> q;

      // read queries
      for(int j=0; j < q; j++){
         string initial;
         char query;
         int iterations;
         
         cin >> initial >> query >> iterations;

         solve(initial, iterations, query);         
      }
   }
   
   return 0;
}
