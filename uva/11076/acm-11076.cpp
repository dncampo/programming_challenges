/**
 * Title: Add Again
 * URL: http://online-judge.uva.es/p/v110/11076.html
 * Resources of interest:
 * Solver group: sergio
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   Para cada entrada se aplican los siguientes pasos:
   - Primero se calcula la permutacion generalizada de N!/(n1!n2!..nk!)
   donde N es la cantidad de dígitos y n1, n2.. nk es la cantidad de veces
   que se repite cada dígito.
   - Se divide el valor anterior por el N, y se guarda en SUM.
   - Finalmente se itera N veces y se aplica la formula:
     res = sumatoria(  10^i * SUM) para i de 0 a N-1;
**/

#include <cstdio>
#include <set>
using namespace std;

double fact[] = {1,1,2,6,24, 120,720, 5040, 40320, 362880, 3628800, 39916800, 479001600};

long double permut(int n,set<int> & list,  multiset<int> & listdup){
   long double value = fact[n], div = 1;

   for(set<int>::iterator i = list.begin(); i != list.end(); i++ ) {
      div *= fact[listdup.count(*i)];
   }
   
   return value/div;   
}

int main(){
   int n;
   while(scanf("%d", &n) && n != 0 ){
      long double sum = 0;
      int value;
      set<int> list;
      multiset<int> listdup;
      
      for(int i = 0; i < n; i++){
         scanf("%d", &value);
         sum += value;
         list.insert(value);
         listdup.insert(value);         
      }
      if(list.size() == 1) {
         sum = *list.begin();
      } else {
         sum *= (permut(n, list, listdup)/n);
      }

      long double result = 0;

      for(int i = 0; i < n; i++){
         result += sum;
         sum *= 10.0;
      }
      printf("%.0Lf\n", result);
   }
   return 0;
}
