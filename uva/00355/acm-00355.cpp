/**
 * Title: The Bases Are Loaded
 * URL: http://uva.onlinejudge.org/external/3/355.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
    + Se utiliza la herramienta de convesión de bases para resolver el problema.
    + Para chequear si un número está en una base inválida se verifica si posee
    algún dígito mayor o igual que su base.
**/

#include <iostream>
#include <map>
#include <string>


using namespace std; 


/*
 * De cualquier base <= 36 a decimal
 */
bool to_decimal (string n, int b, long long int& result) {
   //set up values
   map<char, int> value;
   for (unsigned i = 0; i <= 9; i++) {
      value['0' + i] = i;
   }
   unsigned j = 10;
   for (unsigned i = 'A'; i <= 'Z'; i++, j++) {
      value[i] = j;
   }
   
   long long int multiplier = 1;
   result = 0;
   for (int i = (int)(n.size() - 1); i >= 0; i--) {
      
      //Chequear si el n es válido
      if (value[n[i]] >= b) {
         return false;
      }
      
      result += value[n[i]] * multiplier;
      multiplier *= b;
   }
   return true;
}


/*
 * De decimal a cualquier base <= 36
 */
string from_decimal_str (long long int n, int b) {
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

   int base_a, base_b;
   string number;
   
   long long int tmp;
   while (cin >> base_a >> base_b >> number) {
      if ( to_decimal(number, base_a, tmp) ) {
         cout << number << " base " << base_a << " = " << from_decimal_str(tmp, base_b) << " base " << base_b << endl;
      }
      else {
         cout << number << " is an illegal base " << base_a << " number" << endl;
      }   
   }
   
   return 0;
}

