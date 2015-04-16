//david 2014

#include <iostream>
#include <algorithm>

using namespace std;

bool my_comp(char a, char b){
  char A=tolower(a);
  char B=tolower(b);
  return (A==B ? a<b: A<B);
}

int main (){
  unsigned n_cases;
  string line;
  
  cin >> n_cases;  
  for(unsigned i=0; i<n_cases; i++){
    cin >> line;
    
    sort(line.begin(), line.end(), my_comp);    
    do{
      cout << line << endl;
    }while(next_permutation(line.begin(), line.end(), my_comp));
  }
  return 0;
}

