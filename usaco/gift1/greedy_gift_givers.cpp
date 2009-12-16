/*
ID: dncampo1
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

ofstream fout ("gift1.out");
ifstream fin ("gift1.in");

int main () {
   unsigned n_people;
   fin >> n_people;
   fin.ignore ();

   map <string, int> people;
   vector<string> ordered(n_people);
   string name;
   for (unsigned i = 0; i < n_people; i++) {
      fin >> name;
      ordered[i] = name;
   }

   string giver, receiver;
   unsigned give, n, each;
   for (unsigned i = 0; i < n_people; i++) {
      fin >> giver;
      fin >> give >> n;

      if (0 != n) {
         people[giver] = people[giver] - give + (give % n);
         each = give / n;

         for (unsigned j = 0; j < n; j++) {
            fin >> receiver;
            people[receiver] = people[receiver] + each;
         }
      }
      else {
         people[giver] = people[giver] + give;
      }
   }

   for (unsigned i = 0; i < n_people; i++) {
      string tmp = ordered[i];
      fout << tmp << " " << people[ tmp ] << endl;
   }
   return 0;
}