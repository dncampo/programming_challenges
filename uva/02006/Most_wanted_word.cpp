#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <cctype>
#include <cstdio>


using namespace std;

int main () {
	
	char c;
	do {
		int isa, pos = 0;
		map <string, unsigned> count;
		map <string, unsigned> position;
		do{
			string word;
			do {
				if (-1 == scanf ("%c", &c)) return 0;
				isa = isalpha(c);
				
				if (0 != isa)
					word.push_back(tolower(c));
					
			} while (0 != isa && ' ' != c);
			
			if (count.find (word) == count.end()) {
				count[word] = 1;
				position[word] = pos++;
			}
			else {
				count[word]++;
				position[word] = pos++;
			}
		} while ('#' != c);

		unsigned max = 0;
		for (map<string, unsigned>::iterator it = count.begin(); it != count.end(); it++)
			if (it->second > max && it->first != "") max = it->second;

		unsigned min_pos = 4000000000;
		string res = "";
		for (map<string, unsigned>::iterator it = count.begin(); it != count.end(); it++) {
			if (it->second == max && position[it->first] < min_pos) {
				min_pos = position[it->first];
				res = it->first;
			}
		}
		
		if (res != "") {
			cout << setw(4);
			cout << count[res] << " " << res << endl;
		}
	} while (1);
	return 0;
}
