/**
 * Title: Soundex
 * URL: http://online-judge.uva.es/p/v102/10260.html
 * Resources of interest:
 * Solver group: Yeyo-David
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   + Se mantiene una variable que almacena el último valor para no imprimirlo nuevamente si llegase a
	ser el próximo carácter del mismo grupo que éste último.
**/

#include <iostream>
using namespace std;

int main(){
	string line;

	while(getline(cin,line)){
		unsigned last_value=0, value=0;
		bool flag = true;
		for(unsigned index = 0; index < line.size(); index++){
			char c = line.at(index);

			if( ('B' == c || 'F' == c || 'P' == c || 'V' == c ))
				value = 1;
			else if( ('C' == c || 'G' == c || 'J' == c || 'K' == c  || 'Q' == c  || 'S' == c  || 'X' == c  || 'Z' == c ))
				value = 2;
			else if( ('D' == c || 'T' == c))
				value = 3;
			else if( ('L' == c))
				value = 4;
			else if( ('M' == c || 'N' == c))
				value = 5;
			else if( ('R' == c))
				value = 6;
			else{
				value = last_value = 0;
				flag = true;
				continue;
			}
			
			if(last_value !=value) 
				flag= true;
			else flag = false;
			if(flag)
				cout << value;
			flag = !(last_value ==value);
			last_value = value;
		}
		cout << endl;
	}
	return 0;
}

//EOF
