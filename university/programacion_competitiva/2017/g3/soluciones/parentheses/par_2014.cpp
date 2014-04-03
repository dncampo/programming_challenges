#include <iostream>
#include <stack>

using namespace std;

int main(){
	unsigned n_cases;
	cin >> n_cases;
	cin.ignore(); // el endl

	for (unsigned i = 0; i < n_cases; i++) {
		string line;
		getline (cin, line);
    
    stack<char> s;
    char tmp;
    unsigned j=0;
    for (; j<line.size(); j++) {
      tmp = line[j];
      if (tmp == '(' || tmp =='[') {
	s.push(tmp);
      }
      else{
	if (s.empty()) {
	  break;	  
	}
	else { 
	  
	  if ((tmp == ')' && '(' == s.top()) || (tmp == ']' && s.top()== '[')) {
	    s.pop();
	  }
	  else{
	    break;
	  }
	}
      }
    }
    if ((j == line.size()) && s.empty()){
      cout << "Yes" << endl;      
    }
    else {
      cout << "No" << endl;
    }
    
  }
  
}