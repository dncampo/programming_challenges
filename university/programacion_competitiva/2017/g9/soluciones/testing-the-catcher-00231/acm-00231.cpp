/** 
 * Title: Testing the CATCHER 
 * URL: http://acm.uva.es/p/v2/231.html
 * Resources of interest:
 * Solver group: David - Yeyo
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
  Para cada entrada se utiliza un LIS para resolver el problema
**/


#include<iostream>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;

int LIS(const vector<int>& input){
    set<int> s;
    set<int>::iterator k;

    for(unsigned i = 0; i < input.size(); i++){
        if(s.insert(input[i]).second){
           k = s.find(input[i]);
          
           if(++k != s.end()){
              s.erase(k);
           }
        }
    }
    return s.size();
}

int main() {
   int n, cnt = 1;
   
   while (cin >> n) {
      vector <int> v;
      while (-1 != n) {
         v.push_back(n);
         cin >> n;      
      }
      
      if (0 == v.size()) break;
      
      reverse(v.begin(), v.end());
      if (cnt > 1) cout << endl;
      cout << "Test #" << cnt++ << ":" << endl;
      cout << "  maximum possible interceptions: " << LIS(v) << endl;
   }
   
   

   return 0;
}

