/**
 * Title: Prime Distance
 * URL: http://online-judge.uva.es/p/v101/10140.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   Para cada rango de entrada L,U se calcula primero todos los numeros
   primos y luego se recorre linealmente buscando la distancia minima
   y la distancia maxima. Luego se imprime el resultado.
   En caso de no existir numeros primos en el intervalo L,U se imprime
   el siguite mensaje : "There are no adjacent primes."
**/

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

vector<int> list;

void criba(int L,int U){
   char l[U-L+1];
   int d = U-L+1;
   int d_limit = (int) (sqrt(U));
	
   memset(l, 1, sizeof (l));

   for(int i = (L % 2 == 1); i < d; i += 2){
      l[i] = 0;
   }

   for(int i = 3; i <= d_limit; i += 2){
      if (i > L && !l[i-L]) continue;

      int j = L/i*i;
    
      if (j < L) j += i;
      if (j == i) j += i;
      j-=L; 
      for (; j < d; j += i) 
         l[j]=0;
   }
  
   if (L <= 1) l[1-L] = 0;
   if (L <= 2) l[2-L] = 1;

   int distance = 0;  
   
   
  for (int i = 0; i < d;i++) {
      if((L+i)  < 2 ) continue;
	  if (l[i]) list.push_back(L+i);
	  }
	  
}

void solve(int l, int u){
   list.clear();
   
   criba(l, u);
   
   if(list.size() <= 1){
      cout << "There are no adjacent primes." << endl;
      return; 
   }
   
   int im = 1, iM = 1;
   
   int m = list[1] - list[0], M = list[1] - list[0];
   
   for(int i = 1; i < list.size(); i++){
      if(m > (list[i]-list[i-1])){
         m = list[i]-list[i-1];
         im = i;
      }
      if(M < (list[i]-list[i-1])){
         M = list[i]-list[i-1];
         iM = i;
      }
   }
   
   cout  << list[im-1] << "," << list[im] << " are closest, " 
         << list[iM-1] << "," << list[iM] <<" are most distant." << endl;
}
int main(){
   int l, u;
   
   while(cin >> l >> u){
      solve(l, u);
   }
   
   return 0;
}
