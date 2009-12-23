/**
 * Title: What Goes Up
 * URL: http://uva.onlinejudge.org/external/4/481.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se utiliza el LIS (Longest Increasing Subsequence, O(N log k)) de una lista de enteros.

**/


#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<cstdio>

using namespace std;

vector<int> LIS(const vector<int> &input){
    vector<int> parent(input.size(),-1), res;
    map<int,int> m;
    map<int,int>::iterator k;

    for (unsigned i = 0; i < input.size();i++){
        if (m.insert(make_pair(input[i], i)).second){  // si pudo insertar
           k = m.find(input[i]);

           if(k==m.begin()){
               parent[i]=-1;
           } else {
               parent[i]=(--k)->second;
               k++;
           }

           if(++k != m.end()){
              m.erase(k);
           }
         }
    }

    k = m.end();
    k--;
    int j = k->second;

    while (j != -1){
       res.push_back(input[j]);
       j = parent[j];
    }
    reverse (res.begin(),res.end());
    return res;
}


int main() {
   int n;
   vector <int> nums;
   while (~scanf("%d",&n)){
      nums.push_back(n);
   }

   vector<int> sol = LIS(nums);

   printf("%d\n-\n",(int)sol.size());
   for (vector<int>::const_iterator it = sol.begin(); it != sol.end(); it++)
      printf("%d\n", *it);

   return 0;
}
