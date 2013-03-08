#include <iostream>
#include <string>
#include <vector>

using namespace std;

int count_keys(string word, vector<string> keys){
   for(int i = 0, j= 0; i < word.size(); i++){
      word[i] = tolower(word[i]);
   }
   
   int count = 0;

   for(int i = 0 ; i < keys.size(); i++){
      int index = 0;
      while((index = word.find(keys[i], index)) != string::npos){
         index += keys[i].size();
         
         if((index-keys[i].size() > 0 && isalpha(word[index-keys[i].size()-1]))
            || (index  < word.size() && isalpha(word[index]))){
            continue;      
         }

         count++;
      }
   }
   return count;
}

int main() {
	int n_key, n_excuse, count = 0;
	
	while (cin >> n_key >> n_excuse) {
		vector<string> key(n_key), excuse(n_excuse);
		vector<int> key_count(n_excuse, 0);

		for (int i = 0; i < n_key; i++){
			cin >> key[i];
	   }
		cin.ignore();		
		for (int i = 0; i < n_excuse; i++){
			getline(cin, excuse[i]);
	   }
		
		for (int i = 0; i < n_excuse; i++){
         key_count[i] = count_keys(excuse[i], key);
		}
		
		int max = key_count[0];
		int index = 0;
		
		for(int i = 1; i < n_excuse; i++){
		   if (max < key_count[i]){
		      max = key_count[i];
		      index = i;
		   }
		}
		
		cout << "Excuse Set #" << ++count << endl;
		
		for (int i = 0; i < n_key; i++){
			if (key_count[i] == max){
				cout << excuse[i] << endl;
		   }
		}
		cout << endl;

	}
}

