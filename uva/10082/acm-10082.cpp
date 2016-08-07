/*
Title: WERTYU
Tags: adhoc
URL: 
Resources of interest:
Solver: David N. Campo, Sergio Del Castillo
Contact e-mail: dncampo at gmail dot com
Solution's notes:
    + Arrays to store valid input/output chars are filled properly
*/

#include <iostream>

using namespace std;

int main(){

	char in[] = {' ', 13, \
   '1','2','3','4','5','6','7','8','9','0','-','=', \
	 'W','E','R','T','Y','U','I','O','P', '[' , ']','\\', \
	 'S','D','F' ,'G','H','J','K','L',';','\'', \
	 'X','C','V','B','N','M',',','.','/'};

	char out[]= {' ', 13, \
    '`','1','2','3','4','5','6','7','8','9','0','-', \
    'Q','W','E','R','T','Y','U','I','O','P','[',']', \
	 'A','S','D','F','G','H','J','K','L',';', \
	 'Z','X','C','V','B','N','M',',','.'};

	string line;

	while(getline( cin,line )){
		for(unsigned index = 0; index < line.size(); index++){
			unsigned i=0;
			while(in[i] !=line.at(index))	i++;
			cout << out[i];
		}
		cout << endl;
	}
	return 0;
}
