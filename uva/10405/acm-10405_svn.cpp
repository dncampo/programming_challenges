/**
 * Title: Longest Common Subsequence
 * URL: http://online-judge.uva.es/p/v104/10405.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
 Se utiliza la funición de programación dinamica conocida:
 f[i][j]:
   0 si i == 0 || j == 0
   f[i][j] = f[i-1][j-1] +1  (x[i] = x[j])
   max(f[i-1][j], f[i][j-1])
**/


#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int > > c;

int lcs(string x, string y){
   c.resize(x.size() + 1);

   for(int i = 0; i <= x.size(); i++){
      c[i].assign(y.size()+1, 0);
   }
	
   for(int i = 1; i < c.size(); i++){
      for(int j = 1; j < c[i].size(); j++){
         if(x[i-1] == y[j-1]){
            c[i][j] = c[i-1][j-1] + 1;
         } else {
            c[i][j] = max(c[i][j-1], c[i-1][j]);
         }
      }
   }

   return c[x.size()][y.size()];
}


int main(){
   string x, y;	

   while(getline(cin, x)){
      if(!getline(cin, y)) return 0;
      cout << lcs(x, y) << endl;
   }
   
   return 0;
}

