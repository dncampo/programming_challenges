#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

int main () {
  
  unsigned n_cases, tree_count;
  string line;
  cin >> n_cases;
  cin.ignore();
  getline(cin, line);
  
  for (unsigned i=0; i<n_cases; i++){
    if (i>0) cout << endl;
    map<string, unsigned> trees;
    tree_count=0;
    while(1){
      getline(cin, line);
      if (""== line){
	break;
      }
      
      trees[line]++;
      tree_count++;
    }
    
    for(map<string,unsigned>::iterator it=trees.begin();it != trees.end(); it++) { 
      cout << it->first << " " << fixed << setprecision(4) << (it->second*100.0) / tree_count << endl;
    }

  }
  return 0;
}