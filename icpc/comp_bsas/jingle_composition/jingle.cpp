#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	map <char, unsigned> val;
	val['W'] = 64;
	val['H'] = 32;
	val['Q'] = 16;
	val['E'] = 8;
	val['S'] = 4;
	val['T'] = 2;
	val['X'] = 1;

	string line;
	while (getline(cin, line)){
		if (line[0] == '*') return 0;

		unsigned res = 0, i = 0;
		while (i < line.size()){
			if (line[i] == '/'){
				i++;
				continue;
			}
			unsigned sum = 0;				
			while(line[i] != '/'){

				sum += val[line[i]];
				i++;
			}
			if (sum == 64)	res++;
		}
		cout << res << endl;
	}
	return 0;
}


