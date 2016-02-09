/**
 * Title: Adding Sevens
 * URL: https://www.spoj.pl/problems/ANARC08B/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se lee la expresión y se la transforma a decimal para realizar la suma. Luego se transforma
   el resultado a la salida en forma codificada.

**/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string,unsigned> decod; //"063", "010",....."107" ==> 0,1,....9
vector<string> codif(10); //0,1,....9 ==> "063", "010",....."107"
unsigned mul[10]; //potencias de 10
unsigned div_3_minus_1[28]; // n / 3 - 1 (n es multiplo de 3)


unsigned val(const string &a) {
   unsigned ret = 0, m = div_3_minus_1[a.size()];
   for (unsigned i = 0; i < a.size(); i += 3, m--) {
      ret += mul[m] * decod[ a.substr(i, 3) ];
   }
   return ret;
}

string convert(unsigned a) {
   string res = "";
   while (a) {
      res = codif[ a % 10 ] + res;
      a /= 10;
   }
   return res;
}


int main() {
   div_3_minus_1[3] = 0; div_3_minus_1[6] = 1; div_3_minus_1[9] = 2; div_3_minus_1[12] = 3;
   div_3_minus_1[15] = 4; div_3_minus_1[18] = 5; div_3_minus_1[21] = 6; div_3_minus_1[24] = 7;
   div_3_minus_1[27] = 8;

   mul[0] = 1; mul[1] = 10; mul[2] = 100; mul[3] = 1000; mul[4] = 10000;
   mul[5] = 100000; mul[6] = 1000000; mul[7] = 10000000; mul[8] = 100000000;
   mul[9] = 1000000000;

   decod["063"] = 0; decod["010"] = 1; decod["093"] = 2;
   decod["079"] = 3; decod["106"] = 4; decod["103"] = 5;
   decod["119"] = 6; decod["011"] = 7; decod["127"] = 8;
   decod["107"] = 9;

   codif[0] = "063"; codif[1] = "010"; codif[2] = "093";
   codif[3] = "079"; codif[4] = "106"; codif[5] = "103";
   codif[6] = "119"; codif[7] = "011"; codif[8] = "127";
   codif[9] = "107";

   string line, a, b;

   while (getline(cin, line)) {
      if ("BYE" == line) return 0;

      unsigned cut_a = line.find_first_of('+');
      a = line.substr(0, cut_a);
      unsigned cut_b = line.size() - 1;
      b = line.substr(cut_a + 1, cut_b - cut_a - 1);

      unsigned sum = val(a) + val(b);
      cout << line << convert(sum) << endl;
   }

   return 0;
}

