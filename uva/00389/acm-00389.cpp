/**
 * Title: Basically Speaking
 * URL: http://uva.onlinejudge.org/external/3/389.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
    + Se utiliza la herramienta de conversión de bases para resolver el problema.
**/


#include <iostream>
#include <map>
#include <string>

using namespace std;


/*
 * De cualquier base <= 36 a decimal
 */
unsigned to_decimal (string n, int b) {
   //set up values
   map<char, int> value;
   for (unsigned i = 0; i <= 9; i++) {
      value['0' + i] = i;
   }
   unsigned j = 10;
   for (unsigned i = 'A'; i <= 'Z'; i++, j++) {
      value[i] = j;
   }
   
   unsigned result = 0, multiplier = 1;
   for (int i = (int)(n.size() - 1); i >= 0; i--) {
      result += value[n[i]] * multiplier;
      multiplier *= b;
   }
   return result;
}


/*
 * De decimal a cualquier base <= 36
 */
string from_decimal_str (unsigned n, int b) {
   const string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   string result = "";
   
   if (0 == n) return "0";
   
   while (n > 0) {
      result = digits[n % b] + result;
      n /= b;
   }
   return result;
}


int main () {

   string a;
   int b, c;
   
   while (cin >> a >> b >> c) {
      unsigned tmp = to_decimal (a, b);
      string res = from_decimal_str (tmp, c);
      
      cout.width(7);
      if (res.size() > 7) {
         cout << "ERROR" << endl;
      }
      else {
         cout << res << endl;
      }

   }

   return 0;
}


