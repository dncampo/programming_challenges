#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include <sstream>

using namespace std;

vector<int> cost;  // vector de costos
vector<int> parent; // vector de padres

// largest increasing sequence 
int lis(const vector<int>& input){
   cost  .assign(input.size(),  1);
   parent.assign(input.size(), -1);
   
   for(unsigned i = 0; i < input.size(); i++){
      for(unsigned j = i+1; j < input.size(); j++){
         if(input[j] > input[i] && (1 + cost[i]) > cost[j]){
            cost[j] = 1 + cost[i];
            parent[j] = i;
         }               
      }
   }
   
   int index = 0;
   
   for(unsigned i = 1; i < cost.size(); i++){
      if(cost[i] > cost[index]){
         index = i;
      }
   }
   
   return index;
}

//imprimir la solucion
void print_lis(int index, const vector<int>& input){
   cout << "Max hits: " << cost[index] << endl;
   
   stack<int> s;

   s.push(input[index]);

   while(parent[index] != -1){
      s.push(input[parent[index]]);
      index = parent[index];
   }

   while(!s.empty()){
      cout << s.top() << endl;
      s.pop();
   }
}

int main(){
   int ncases, value;
   string line;
  
   cin >> ncases;
   cin.ignore();
   
   getline(cin, line);
   
   for(int k=0; k<ncases; k++){
      getline(cin, line);
      vector<int> input;

      while("" != line) {
         stringstream sin(line);         
         sin >> value;
         input.push_back(value);
         getline(cin, line);
      }

      print_lis(lis(input), input);
      
      if((k+1) < ncases){
         cout << endl;
      }
   }
      
   return 0;
}

/*
http://www.algorithmist.com/index.php/Longest_Increasing_Subsequence
#include <vector>
using namespace std;
 
// Finds longest strictly increasing subsequence. O(n log k) algorithm. 
vector<int> find_lis(vector<int> &a)
{
	vector<int> b, p(a.size());
	int u, v;
 
	if (a.size() < 1) return b;
 
	b.push_back(0);
 
	for (size_t i = 1; i < a.size(); i++) {
		if (a[b.back()] < a[i]) {
			p[i] = b.back();
			b.push_back(i);
			continue;
		}
 
		for (u = 0, v = b.size()-1; u < v;) {
			int c = (u + v) / 2;
			if (a[b[c]] < a[i]) u=c+1; else v=c;
		}
 
		if (a[i] < a[b[u]]) {
			if (u > 0) p[i] = b[u-1];
			b[u] = i;
		}	
	}
 
	for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
	return b;
}
 
// Example of usage: 
#include <cstdio>
int main()
{
	int a[] = { 1, 9, 3, 8, 11, 4, 5, 6, 4, 19, 7, 1, 7 };
	vector<int> seq(a, a+sizeof(a)/sizeof(a[0]));
	vector<int> lis = find_lis(seq);
 
	for (size_t i = 0; i < lis.size(); i++)
		printf("%d ", seq[lis[i]]);
        printf("\n");    
 
	return 0;
}
*/
