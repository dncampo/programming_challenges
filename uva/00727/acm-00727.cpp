//David 2014
#include <iostream>
#include <stack>

using namespace std;

int main () {
  unsigned n_cases;
  string line;
  cin >> n_cases;
  cin.ignore();
  getline(cin, line); //first blank


  for (unsigned i=0; i<n_cases; i++){
    stack<string> s;
    unsigned op=0;
    if (i > 0) cout << endl;
    while (1) {
      getline(cin, line);

      if ("" == line) {
	//to finish the case, print and pop all operators
	while (!s.empty()){
	  cout << s.top();
	  s.pop();
	}
	cout << endl;
	break;
      }
      if (")" == line) {
	op = 1;
	continue;
      }
      else if ("+" != line && "-" != line && "/" != line && "*" != line) { //a number or parentheses
	if (")" == line) {
	  cout << s.top(); //pop and print the opertator
	  s.pop();
	}
	else if ("(" != line) { //a number=operand
	  cout << line;
	  if(op == 0) {	  	    
	    op++;
	  }
	  else if (op >= 1) {
	    if (!s.empty() && s.top() != "*" && s.top() != "/") {
	      cout << s.top();
	      s.pop();
	    }
	  }
	}
      }
      else { //push the operator into the stack
	s.push(line);	
      }
    }
  }
  
}