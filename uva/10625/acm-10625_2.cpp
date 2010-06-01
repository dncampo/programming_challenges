/**
 * Title: GNU = GNU'sNotUnix
 * URL: http://online-judge.uva.es/p/v106/10625.html
 * Resources of interest:
 * Solver group: Leo-Yeyo
 * Contact e-mail: bortoli.leonardo at gmail dot com
 * Description of solution:
    + Otra implementacion con el mismo enfoque que la anterior
**/
#include<iostream>
#include<cstring>

using namespace std;

unsigned long long letters[94];
int rules[94][94];
bool has_rule[94];

int main(){
   int t, r, q;
   
   cin >> t;
   for(int cases=0; cases<t; cases++){
      memset(rules, 0, sizeof(rules));
      memset(has_rule, false, sizeof(has_rule));
      
      cin >> r;
      
      string rule;
      for(int i_rules=0; i_rules<r; i_rules++){
         cin >> rule;
         
         has_rule[rule[0] - 33] = true;
         if(rule.size() < 4){
            rules[rule[0] - 33][rule[0] - 33] = -1;
         } else{
            for(unsigned i=3; i<rule.size(); i++){
               rules[rule[0] - 33][rule[i] - 33]++;
            }
            
            rules[rule[0] - 33][rule[0] - 33]--;
         }
      }
      
      string initial;
      char ch;
      int iterations;
      
      cin >> q;
      for(int i_queries=0; i_queries<q; i_queries++){
         memset(letters, 0, sizeof(letters));
         
         cin >> initial >> ch >> iterations;
         
         for(unsigned i=0; i<initial.size(); i++){
            letters[initial[i] - 33]++;
         }
         
         for(int it=0; it<iterations; it++){
            unsigned long long tmp[94];
            memset(tmp, 0, sizeof(tmp));
            
            for(int i_letters=0; i_letters<94; i_letters++){
               if(has_rule[i_letters]){
                  for(int i_rules=0; i_rules<94; i_rules++){
                     if(rules[i_letters][i_rules] >= 0){
                        tmp[i_rules] += rules[i_letters][i_rules] * letters[i_letters];
                     } else{
                        tmp[i_rules] -= (-rules[i_letters][i_rules]) * letters[i_letters];
                     }
                  }
               }
            }
            
            for(int i=0; i<94; i++){
               letters[i] += tmp[i];
            }
         }
         
         cout << letters[ch - 33] << '\n';
      }
   }
   
   return 0;
}
