/*
Title: Life, the Universe, and Everything
Tags: adhoc, trivial
URL: https://www.spoj.pl/problems/TEST/
Resources of interest:
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Solution's notes:
    + Testing problem whose only purpose is to echo the input until it reachs the number 42
*/

#include <iostream>

using namespace std;

int main(){
	short num;
	do{
		cin >> num;
		if(num != 42) cout << num << endl;
	} while(42 != num);
	return 0;
}
