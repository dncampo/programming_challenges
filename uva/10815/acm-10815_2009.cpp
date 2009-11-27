#include <iostream>
#include <string>
#include <set>
#include <cctype>

using namespace std;

int main () {
	char ch;
	string line;
	set<string> dic;
	
	while (cin >> line) {

		unsigned i = 0;
		string word;
		while (i < line.size()) {

			ch = word[i];
				cout << ch;
			while (i < line.size() && isalpha(ch)) {
				word.push_back(tolower(ch));
				i++;
				ch = word[i];
			}
			dic.insert(word);
			
		}
	}
	
	for (set<string>::iterator it = dic.begin(); it != dic.end(); it++)
	cout << *it << endl;

	return 0;
}
