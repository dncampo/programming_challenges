#include <iostream>
#include <string>
#include <set>

using namespace std;

int main () {
	string word, alphabet = "abcdefghijklmnopqrstuvwxyz";
	set<string> dictionary;
	
	while (cin >> word) {
		for (unsigned i = 0; i < word.size(); i++)
			word[i] = tolower(word[i]);

		unsigned long long tmp = string::npos;
		while ( (tmp = word.find_first_not_of (alphabet)) != string::npos) {
				word.erase(tmp, 1); // borrar cualquier cosa que no sea una letra
		}

		if (0 == word.size ()) continue;
		dictionary.insert(word);

	}
	for (set<string>::iterator it = dictionary.begin(); it != dictionary.end(); it++)
		cout << *it << endl;
	return 0;
}
