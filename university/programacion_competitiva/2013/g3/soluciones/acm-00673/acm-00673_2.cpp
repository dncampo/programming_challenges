/**
 * Title:  Parentheses Balance
 * URL: http://uva.onlinejudge.org/external/6/673.html
 * Resources of interest:
 * Solver group: Leo
 * Contact e-mail: leonardobortoli at yahoo dot com dot ar
**/

#include<iostream>
#include<string.h>
#include<stack>

using namespace std;

int main(){
	int n;
	char stri[129];

	cin >> n;
	cin.ignore();

	for(int i=0; i<n; i++){
		gets(stri);
		size_t size = strlen(stri);
		stack<char> stk;
		
		for(size_t j=0; j<size; j++){
			if(stri[j] == ')' && !stk.empty() && stk.top() == '(')
				stk.pop();
			else if(stri[j] == ']' && !stk.empty() && stk.top() == '[')
				stk.pop();
			else stk.push(stri[j]);
		}
		if(stk.empty())
			cout << "Yes" << endl;					
		else
			cout << "No" << endl;
	}
	return 0;
}
