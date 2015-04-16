/**
 * Title: Run-Length Mathematics
 * URL: https://www.spoj.pl/problems/RLM/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se leen los operandos "codificados".
   + Se pasan los operandos a decimal y se realiza la operación.
   + Se convierte el resultado a través de la función RLE (Run-length encoding)

**/

#include <iostream>

using namespace std;

unsigned long long pow[] =
               { 1ULL, 10ULL, 100ULL, 1000ULL, 10000ULL,
                 100000ULL, 1000000ULL, 10000000ULL, 100000000ULL, 1000000000ULL,
                 10000000000ULL, 100000000000ULL, 1000000000000ULL, 10000000000000ULL, 100000000000000ULL,
                 1000000000000000ULL, 10000000000000000ULL, 100000000000000000ULL, 1000000000000000000ULL,
                 10000000000000000000ULL };


unsigned long long get_decimal(string &n) {
   unsigned idx = 0, actual = n.size() - 1;
   long long dec = 0;

   for (int i = actual; i >= 0; i -= 2) {
      for (int j = 0; j < (n[i - 1] - '0'); j++, idx++) {
         dec += pow[idx] * (n[i] - '0');
      }
   }
   return dec;
}

string normalise(char a, unsigned cnt) {
   string ret = "";

   while (cnt > 9) {
      cnt -= 9;
      ret += '9';
      ret += a;
   }
   if (cnt > 0) {
      char cnt_c = cnt + '0';
      ret += cnt_c;
      ret += a;
   }
   return ret;
}

string rle(unsigned long long n) {
   string ret = "";

   if (0 == n) {
      return "10";
   }

   while (n > 0) {

      char a = n % 10, cnt = 1, res;
      n /= 10;

      while (a == (res = n % 10) && n > 0) {
         cnt++;
         n /= 10;
      }

      if (cnt > 9) {
         ret = normalise(a + '0',cnt) + ret;
      }
      else {
         a += '0'; cnt += '0';
         string concat(1,cnt);
         concat += a;
         ret = concat + ret;
      }
   }

   return ret;
}

int main() {
   string num_a, num_b;
   char op;

   while (cin >> num_a >> op >> num_b) {
      unsigned long long n_a = get_decimal(num_a);
      unsigned long long n_b = get_decimal(num_b);
      unsigned long long res;

      switch (op) {
         case '+':
            res = n_a + n_b;
            break;

         case '-':
            res = n_a - n_b;
            break;

         case '*':
            res = n_a * n_b;
            break;

         case '/':
            res = n_a / n_b;
            break;
      }
      cout << num_a << " " << op << " " << num_b << " = " << rle(res) << endl;
   }

   return 0;
}
