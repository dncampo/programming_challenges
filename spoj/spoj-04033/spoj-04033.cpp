#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

bool consistent(char* x, char *y) {
   for (unsigned i = 0; i < strlen(y); i++) {
      if (x[i] != y[i]) return true;
   }
   return false;
}


bool solve (map<unsigned, vector<char*> > &guide) {
   for (map<unsigned, vector<char*> >::reverse_iterator it1 = guide.rbegin(); it1 != guide.rend(); it1++) {
      map<unsigned, vector<char*> >::reverse_iterator it2 = it1;
      it2++;
      if (it2 == guide.rend()) break;
      for (; it2 != guide.rend(); it2++) {
         for (unsigned x = 0; x < it1->second.size(); x++) {
            for (unsigned y = 0; y < it2->second.size(); y++) {
               if (! consistent(it1->second.at(x), it2->second.at(y)) )
                  return false;
            }
         }
      }
   }
   return true;
}


int main() {
   unsigned n_cases, n_tels;

   scanf("%u", &n_cases);

   for (unsigned i = 0; i < n_cases; i++) {
      map<unsigned, vector<char*> > guide;

      scanf("%u", &n_tels);
      for (unsigned j = 0; j <= n_tels; j++) {

         char tel[20];
         fgets( tel, 21, stdin );
         tel[strlen(tel) - 1] = '\0';
         if (strlen(tel) == 0) continue;
         guide[strlen(tel)].push_back(tel);
         fflush(stdin);
      }
      if (solve(guide))
         printf("YES\n");
      else
         printf("NO\n");

      fflush(stdin);
   }
   return 0;
}
