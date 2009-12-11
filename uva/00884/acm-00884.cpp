/**
 * Title: 
 * URL: http://online-judge.uva.es/p/v8/884.html
 * Resources of interest: Factorial Factors 
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   Primero se calculan todos los factores primos de un numero.
   Luego se calculan los factores primos para cada factorial con la 
   funcion solve.
   Luego para cada salida se imprime la solución. 
**/

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

struct Factor{
   int value;
   int degree;
};

vector<vector<Factor> > list;
int factors[1000001];

void pfactors(int limit){
   char p[limit+1];
   memset(p, 1, sizeof(p));
   
   list.resize(limit+1);
   
   for(int i=2; i <= (limit+1)/2; i++){
      if(p[i]){
         Factor f = {i, 0};
         for(int j=2; i*j <= limit; j++){
            list[i*j].push_back(f);
            p[i*j] = 0;
         }
      }
   }
   
   for(int i=2; i <= limit; i++){
      if(p[i] == 0){
         for(unsigned j=0; j < list[i].size(); j++){
            int num, div = i / list[i][j].value;
            do{
               num = div;
               div = num / list[i][j].value;
               list[i][j].degree++;
            } while(div * list[i][j].value == num);
         }
      } else{
         Factor f = {i, 1};
         list[i].push_back(f);      
      }
   }
}

void solve(){
   int c = 0;

   pfactors(1000001);
      
   for(int j = 1; j <= 1000000; j++ ){
      for(int i = 0; i < list[j].size(); i++){
         c += list[j][i].degree;
      }
      factors[j] = c;
   }

}
int main(){

   solve();
   int n;
   
   while(cin >> n){
      cout << factors[n] << endl;
   }
   return 0;
}
