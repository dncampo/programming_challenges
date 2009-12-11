/**
 * Title: Prime Words
 * URL: http://online-judge.uva.es/p/v109/10924.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   primero se calculan los primeros primos menores a 1040.
   luego se define un mapa m que asocia cada letra con su peso.
   utilizando el mapa se suma el peso total y por ultimo
   se verifica ese peso es o no primo para imprimir la salida.
**/

#include<iostream>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> primes;

void criba(int limit){
   char list[limit+1];
   memset(list, 1, sizeof(list));

   int d_limit = (int) (sqrt(limit));

   for(int i=2; i<=d_limit; i++){
      if(list[i]){
         for(int j=2; j*i<=limit; j++){
            list[j*i] = 0;
         }
      }
   }
   
   for(int i = 1; i <= limit; i++){
      if(list[i]){
         primes.push_back(i);
      }
   }
}

int main(){
   criba(1040);
   string line;
   map<char, int> m;
   char c = 'a';
   
   for(int i = 1; i <=26; i++){
      m[c++] = i;
   }
   c = 'A';
   for(int i = 1; i <=26; i++){
      m[c++] = 26+i;
   }
   
   while(cin >> line){
      int c = 0;
      for(int i = 0; i < line.size(); i++){
         c += m[line[i]];
      }

      vector<int>::iterator it = find( primes.begin(), primes.end(), c);
 
      if( it == primes.end() ) {
        cout << "It is not a prime word." << endl;
      } else {
        cout << "It is a prime word."<< endl;      
      }
   }
   
   return 0;
}

