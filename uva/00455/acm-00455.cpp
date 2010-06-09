/**
 * Title: Periodic Strings
 * URL: http://uva.onlinejudge.org/external/4/455.html
 * Resources of interest:
 * Solver group: Leo
 * Contact e-mail: bortoli.leonardo at gmail dot com
 * Description of solution:
   + Se analizan todos los posibles substrings que se repitan, hasta quedar con el de menor longitud, y que
   + ademas esta longitud sea un numero divisor de la longitud del string original.
**/
#include<iostream>

using namespace std;

int main(){
   unsigned n, i, c;
   string s;

   cin >> n;
   getline(cin, s); getline(cin, s);

   for(unsigned cases=0; cases<n; cases++){
      getline(cin, s);
  
      c = s.size();
      
      for(unsigned ds=1; ds <= c/2; ds++){
         for(i=0; i < c-ds && s[i] == s[i+ds]; i++);
         if(i == c-ds && !(c % ds)){
            c = ds;
            break;
         }
      }
      
      if(cases > 0)
         cout << '\n';
      
      cout << c << '\n';
      
      getline(cin, s);
   }
   
   return 0;
}
