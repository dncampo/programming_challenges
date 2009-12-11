/**
 * Title: Factors and Factorials
 * URL: http://acm.uva.es/p/v1/160.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   - primero se un vector para todos los factores primos de todos los numeros entre 2 y 100.
   - Para cada numero a partir del 3 se agrega los factores primos del numero anterior.
   - Se ordena cada lista de factores primos en orden creciente.
   - Para cada caso de prueba se imprime la solucion
   
**/

#include<iostream>
#include<iomanip>
#include<vector>
#include<cstring>
#include<algorithm>
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
void add(int index, Factor f){
   for(int i = 0; i < list[index].size(); i++){
      if(list[index][i].value == f.value){
         list[index][i].degree += f.degree;
         return ;
      }
   }
   
   list[index].push_back(f);
}

bool compare(Factor a,Factor b){ 
   return a.value < b.value; 
}

int main(){
   pfactors(100);

   for(int i = 3; i < list.size(); i++){    
      for(int j = 0; j < list[i-1].size(); j++){
         add(i, list[i-1][j]);
      }
   }

   for(int i = 2; i < list.size(); i++){
      sort(list[i].begin(), list[i].end(), compare);
   }
   
   int n;
   
   cin >> n;
   
   while(n > 0){
      cout << setw(3) << n << "! =";
      for(int i = 0; i < list[n].size(); i++){
         if( i > 0 && i % 15 == 0){
            cout << endl << "      ";
         }
         cout << setw(3) << list[n][i].degree;
      }
      cout << endl;
      
      cin >> n;   
   }  
    
   return 0;
}

