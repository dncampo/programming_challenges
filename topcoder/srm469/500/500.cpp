#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>

using namespace std;

bool first_solution = false;

class TheMoviesLevelTwoDivTwo {
public:


vector<int> data;

   vector<int> backtracking(vector<int> l, vector<int> s){
	   if(is_solution(l,s)){
		   return data;
	   }else{
			if(first_solution) return data;
			
		   vector<int> candidates;

		   get_candidates(candidates, s.size());
		
		   for(unsigned i = 0; i < candidates.size(); i++){
			   data.push_back(candidates[i]);
			   backtracking(l,s);
			   data.pop_back();
		   }
	   }
	   return data;
   }

   bool is_solution(vector<int> l, vector<int> s){
//   cout << "s.size()-data.size()" << s.size() << "-" << data.size() << endl;
      int actual = 74;
	   if (data.size() == s.size()) {

         for (unsigned i = 0; i < data.size(); i++) {
            actual += s[data[i]] - l[i];
         }
         if (actual >= 0) first_solution = true;
	   }
	   else { return false; }
	   return actual >= 0;
   }

   void get_candidates(vector<int> &candidates, int tam){
      vector<bool> in_perm(tam, false);
      for (unsigned i = 0; i < data.size(); i++) {
         in_perm [data[i] ] = true;
      }
      
      for (int i = 0; i < tam; i++) {
         if (in_perm[i] == false) {
            candidates.push_back(i);
         }
      }
	
   }


   vector<int> find (vector <int> length, vector <int> scary) {
      for (int i = 0; i < scary.size(); i++) {
         scary[i] = 47 - scary[i];
      }

      return backtracking(length, scary);
   }

};

int main () {

   TheMoviesLevelTwoDivTwo x;

   vector<int> l(2);
   l[0]=100, l[1]=50;
   vector<int> s(2); s[0] =1; s[1]=1;

   vector<int> r = x.find (l, s);

   for (unsigned i = 0; i < r.size(); i++) {
      cout << r[i] << " ";
   }
   cout << endl;

   return 0;
}

