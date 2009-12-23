#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>


using namespace std;

void init_map (map<string, unsigned> &m) {
   m["zero"] = 0; m["one"] = 1; m["two"] = 2; m["three"] = 3; m["four"] = 4; m["five"] = 5;
   m["six"] = 6; m["seven"] = 7; m["eight"] = 8; m["nine"] = 9; m["ten"] = 10; m["eleven"] = 11;
   m["twelve"] = 12; m["thirteen"] = 13; m["fourteen"] = 14; m["fifteen"] = 15; m["sixteen"] = 16;
   m["seventeen"] = 17; m["eighteen"] = 18; m["nineteen"] = 19; m["twenty"] = 20; m["thirty"] = 30;
   m["forty"] = 40; m["fifty"] = 50; m["sixty"] = 60; m["seventy"] = 70; m["eighty"] = 80;
   m["ninety"] = 90; m["hundred"] = 100; m["thousand"] = 1000; m["million"] = 1000000;
}

int main() {

   map<string, unsigned> m;
   init_map (m);

   string line;
   //while (getline(cin, line)) {
   getline(cin,line);
   {
      stringstream ss(line);

      string tmp;
      bool negative = false;
      int val = 0;
      vector<int> to_sum, final_sum;
      while (ss >> tmp) {
         if ("negative" == tmp) {
            negative = true;
         }
         else {
            if ("millon" == tmp) {
               if (to_sum.size() > 0) {
                  int n = 0;
                  for (unsigned i = 0; i < to_sum.size(); i++)
                     n += to_sum[i];
                  final_sum.push_back(n * 1000000);
cout << "M" << final_sum.back() << endl;
               }
               to_sum.clear();
            }
            else if ("thousand" == tmp) {
            if (to_sum.size() > 0) {
                  int n = 0;
                  for (unsigned i = 0; i < to_sum.size(); i++)
                     n += to_sum[i];
                  final_sum.push_back(n * 1000);
cout << "K" << final_sum.back() << endl;
               }
               to_sum.clear();
            }

            else if ("hundred" == tmp) {
               if (to_sum.size() > 0) {
                  int n = 0;
                  for (unsigned i = 0; i < to_sum.size(); i++)
                     n += to_sum[i];
                  final_sum.push_back(n * 100);
cout << "100: " << final_sum.back() << endl;
               }
               to_sum.clear();
            }
            else {
cout << "added to_sum" << endl;
               to_sum.push_back(m[tmp]);
            }

         }
         to_sum.push_back(val);

      }
      unsigned s = 0;
      for (unsigned i = 0; i < to_sum.size(); i++)
         s += final_sum[i];

      if (negative) cout << "-";
      cout << s << endl;
//         cout << tmp << "---" << endl;
   }

   return 0;
}
