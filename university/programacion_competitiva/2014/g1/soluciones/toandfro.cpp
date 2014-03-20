#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
  int cols, rows;
  string line;
  
  cin >> cols;
  cin >> line;
  
  rows = line.size() / cols;  

  vector<vector<char> > mat(rows);
  unsigned counter = 0;
  for (unsigned i=0; i< rows; i++) {
    for (unsigned j=0; j <cols; j++){
	mat[i].push_back(line[counter++]);
    }
    if (i%2!=0){
      reverse(mat[i].begin(), mat[i].end());
    }
    
  }
cout << rows << endl;  
  for (unsigned i=0; i< rows; i++) {
    for (unsigned j=0; j <cols; j++){
	cout << mat[i][j];
    }
    cout << endl;
    
  }
    
  return 0;
}
