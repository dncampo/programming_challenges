#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>

using namespace std;

class TheMoviesLevelOneDivTwo {
public:
   int find (int n,int m, vector <int> row, vector <int> seat) {
      vector< vector<bool> > t (n);
      
      for (int i = 0; i < n ; i++) {
         t[i] = vector<bool> (m, true);
      }

      for (unsigned i = 0; i < row.size(); i++) {
         t[row[i] - 1][seat[i] - 1] = false;
      }

      unsigned count = 0;
      for (int i = 0; i < n; i++) {
         for (int j = 1; j < m; j++) {
            if (t[i][j - 1] && t[i][j]) count++;         
         }
      }
   return count;
   }

};

int main () {

   TheMoviesLevelOneDivTwo x;
   cout << x.find() << endl;

   return 0;
}

