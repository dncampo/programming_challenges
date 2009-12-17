#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main () {
   unsigned n_people;
   cin >> n_people;
   cin.ignore ();

   map <string, int> people;
   vector<string> ordered(n_people);
   string name;
   for (unsigned i = 0; i < n_people; i++) {
      cin >> name;
      ordered[i] = name;
   }

   string giver, receiver;
   unsigned give, n, each;
   for (unsigned i = 0; i < n_people; i++) {
      cin >> giver;
      cin >> give >> n;

      if (0 != n) {
         people[giver] = people[giver] - give + (give % n);
         each = give / n;

         for (unsigned j = 0; j < n; j++) {
            cin >> receiver;
            people[receiver] = people[receiver] + each;
         }
      }
      else {
         people[giver] = people[giver] + give;
      }
   }

   for (unsigned i = 0; i < n_people; i++) {
      string tmp = ordered[i];
      cout << tmp << " " << people[ tmp ] << endl;
   }
   return 0;
}