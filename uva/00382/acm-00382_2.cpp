/**
 * Title: Perfection
 * URL: http://online-judge.uva.es/p/v3/382.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se calculan todos los divisores propios hasta el 60.000. La idea es que si a / b = c (y resto 0)
   entonces b y c son divisores propios de a, como así también lo son todos los divisores propios de b. 
   Por ello esta información se almacena en un vector de conjuntos (vector<set<unsigned> >). 
   Estas divisiones se las calcula mientras b sea <= sqrt(a).
   Si un número es primo, sólo el 1 es su divisor propio.
   + No es un método que se destaque por ser eficiente, pero es sencillo de entender.

**/


#include <iostream>
#include <cmath>
#include <cstring>
#include <set>
#include <vector>
#include <numeric>

using namespace std;

vector <set<unsigned> > proper;
const unsigned SIZE = 60001;
char list[SIZE];

//calcular los primos
void criba(int limit){
   memset(list, 1, sizeof(list));

   int d_limit = (int) (sqrt(limit));

   for(int i=2; i<=d_limit; i++){
      if(list[i]){
         for(int j=2; j*i<=limit; j++){
            list[j*i] = 0;
         }
      }
   }
}

//divisores propios hasta el 60000
void generate_proper_divisors () {
   criba (SIZE - 1);

   set <unsigned> empty;
   proper.assign (SIZE, empty);

   proper[0] = set<unsigned>();
   set<unsigned> one;
   one.insert (1);
   proper[1] = empty;

   for (unsigned i = 2; i < SIZE; i++) {

      if (1 == list[i]) {//it's prime
         proper[i] = one; //si es primo, sólo el 1 como divisor propio
      }
      else {
         unsigned d = 2;
         unsigned i_limit = (unsigned)sqrt (i);

         while (d <= i_limit) {

            if (i % d == 0) {
               proper[i].insert (proper[d].begin (), proper[d].end ());
               proper[i].insert (i / d);
               proper[i].insert (d);
            }

            d++;
         }
      }
   }
}

//devuelve si un número es PERFECT, ABUNDANT o DEFICIENT
string get_type (unsigned n) {
   unsigned sum = accumulate (proper[n].begin (), proper[n].end (), 0);
   if ( sum > n ) return "ABUNDANT";
   if ( sum < n ) return "DEFICIENT";
   else return "PERFECT";
}


int main () {
   generate_proper_divisors ();

   unsigned n;

   cout << "PERFECTION OUTPUT" << endl;
   while (cin >> n) {
      if (0 == n) break;
      cout.width(5);
      cout << n << "  " << get_type (n) << endl;
   }
   cout << "END OF OUTPUT" << endl;
   return 0;
}
