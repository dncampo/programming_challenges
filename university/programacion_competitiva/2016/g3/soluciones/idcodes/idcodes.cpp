#include <iostream>
#include <stack>

using namespace std;

int main () {
   int nc;
   cin >> nc;
   while (nc--) {
	  string l;
	  cin >> l;
	  
	  stack<char> s1, s2;
	  for (int i=0; i<l.size(); i++) {
		  char c=l[i];
		  
		  switch (c){
			  case '(':
			  break;
			  
			  case ')':
			  break;
			  
			  case '^':
			  break;			 
			  
			  case '*':
			  case '/':
			  break;
			  
			  case '+':
			  case '-':
			  break;
			 
			  
		  }
		  if ('(') continue;
		  
		  if ()
		  
	  }
	  
	  
   
   }
   return 0;
}
