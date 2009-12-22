/**
 * Title: Strategic Defense Initiative
 * URL: http://uva.onlinejudge.org/external/4/497.html
 * Resources of interest:
 * Solver group: David - Yeyo
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se crea un vector<unsigned> para la entrada y se lo ordena en una copia. Luego se busca la
   mayor subsecuencia común (LCS) entre las el vector original (entrada) y su ordenación.

**/


#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int lcs(const vector<unsigned>& A, const vector<unsigned>& B, vector<vector<int> >& pm) {
   for (int i = A.size(); i >= 0; i--)
      for (int j = B.size(); j >= 0; j--) {

         if (i == (int)A.size() || j == (int)B.size()) pm[i][j] = 0;
         else if (A[i] == B[j]) pm[i][j] = 1 + pm[i+1][j+1];
         else pm[i][j] = max(pm[i][j+1], pm[i+1][j]);

      }
   return pm[0][0];
}

void print_lcs(const vector<unsigned>& A, const vector<unsigned>& B, const vector<vector<int> >& pm){
   int i = 0, j = 0, m = A.size(), n = B.size();
   while (i < m && j < n){
      if (A[i] == B[j]){
         cout << A[i] << endl;
         i++; j++;
      }
   else if (pm[i+1][j] >= pm[i][j+1]) i++;
   else j++;
   }
}


int main(){

   unsigned n_cases;
   cin >> n_cases; cin.ignore();
   string line;
   getline(cin, line);

   //entrada
   for (unsigned i = 0; i < n_cases; i++) {
      vector <unsigned> nums;
      while (getline(cin, line) && "" != line) {
         unsigned n;
         stringstream ss;
         ss << line;
         ss >> n;
         nums.push_back(n);
      }

      // se ordena una copia de la entrada para hacer la LCS con la entrada original
      vector <unsigned> nums_sorted = nums;
      sort(nums_sorted.begin(), nums_sorted.end());

      //matriz para armar la LCS
      vector<vector<int> > prefix_matrix(nums.size() + 1);
      for(unsigned k = 0; k < nums.size() + 1; k++){
         vector<int> vy(nums.size() + 1,0);
         prefix_matrix[k] = vy;
      }

      //resultado
      cout << "Max hits: " << lcs(nums, nums_sorted, prefix_matrix) << endl; //Se busca la LCS
      print_lcs(nums, nums_sorted, prefix_matrix);
      if (i < n_cases - 1) cout << endl;
   }

   return 0;
}
