/**
 * Title: Number Sequence
 * URL: http://icpcres.ecs.baylor.edu/onlinejudge/external/107/10706.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
    + Se diferencian 5 rangos distintos, que son: [1; 9], [10; 99], [100; 999], 
    [1000; 9999], [10000; 999999]. Luego dependiendo de la posición 'i' que se requiera
    conocer se aplican distintos tipos de fórmulas. Por ejemplo para un 'i' que esta
    entre 1 y 45, se utiliza la fórmula [X * (X + 1)] / 2, para encontrar el valor 
    solicitado en el problema. 
    Una vez que identificamos la fórmula 'f' a utilizar, se hace una búsqueda lineal con
    los índeces 'j' e 'j + 1' sobre 'f' tal que: f(j) <= num <= f(j + 1). Una vez
    alcanzado dicho valor se lo imprime a través de un arreglo que continue los 
    números hasta el 33000, dispuestos de la forma: 1234567....3299933000.
**/

#include <iostream>
#include <sstream>

#define F_1(X) ((X) * (X + 1)) /* (X + (X + 1))      */
#define F_2(X) (F_1(X) >> 1)   /* (X + (X + 1)) / 2  */
#define F_3(X) (F_1(X) << 1)   /* (X + (X + 1)) * 2  */


using namespace std;

string v_0;
void fill_v () {
   string res;
   for (unsigned j = 0; j <= 33000; j++) {
      stringstream ss;
      ss << j;
      ss >> res;
      v_0 +=res;
   }
}


inline void print (unsigned const val, unsigned const i) {
   if (val) 
      cout << v_0[val] << '\n';
   else
      cout << i % 10 << '\n'; // val == num
}


inline unsigned eval_func (unsigned const i) {
   if (i <= 9) 
      return F_2(i);
   else if (i <= 99) 
      return F_1(i) - 9 * i + 36;
   else if (i <= 999) 
      return F_2(i) * 3 - 108 * i + 4887;
   else if (i <= 9999) 
      return F_3(i) - 1107 * i + 503388;
   else 
      return F_2(i) * 5 - 11106 * i + 50488389;
}


void solve (unsigned const num) {
   register unsigned index, end;
   
   if (num <= 45) 
      index = 1, end = 9;
   else if (num <= 9045) 
      index = 10, end = 99;
   else if (num <= 1395495) 
      index = 100, end = 999;
   else if (num <= 189414495) 
      index = 1000, end = 9999;
   else 
      index = 10000, end = 31267; // max i tal que: eval_func (i) <= 2^31 - 1
   
   // búsqueda lineal con la formula adecuada
   unsigned calc_1 = eval_func (index), calc_2;
   for (; index <= end; index++) {
      calc_2 = eval_func (index + 1);
      
      if (calc_1 <= num && num < calc_2) 
         break;
         
      calc_1 = calc_2;
   }
   print (num - calc_1, index);
}


int main () {
   fill_v();
   unsigned n_cases, num;
   
   cin >> n_cases;   
   for (unsigned i = 0; i < n_cases; i++) {
      cin >> num;
      solve (num);
   }
   return 0;
}

