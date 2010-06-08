/**
 * Title: Count the factors
 * URL: http://online-judge.uva.es/p/v106/10699.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   Primero se calculan los factores primos de todos los números 
   hasta el número 1000000
   luego para cada entrada se imprime la salida como el problema
   lo indica.
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

void pfactors(int limit){
   char p[limit+1];
   memset(p, 1, sizeof(p));
   
   list.resize(limit+1);
   
   for(int i=2; i <= limit; i++){
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

int main(){
   pfactors(1000001);
   int value;
   
   cin >> value;
   
   while(value != 0){
      cout << value << " : " << list[value].size() <<endl;
      cin >> value;
   }      

   return 0;
}
