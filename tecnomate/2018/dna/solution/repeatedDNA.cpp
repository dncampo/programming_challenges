//DNA sequence generator -> http://www.faculty.ucr.edu/~mmaduro/random.htm

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

string decrypt(int hash_value) {
    string ret = "";
    char d[] = {'A', 'C', 'G', 'T'};
    for (int i=0; i<10; ++i) {
        int val = hash_value % 4;
        hash_value = (int)floor(hash_value / 4);
        ret += d[val]; 
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

vector<string> repeatedDNASequences(string s) {
    map<char,int> val;
    val['A'] = 0, val['C'] = 1, val['G'] = 2, val['T'] = 3;
    
    int hash_value = 0;
    map<int, int> sequences;
    int mult = (int)pow(4, 9);
    for(int i=0; i<s.size(); ++i){
        hash_value *= 4;
        hash_value += val[s[i]];
        
        if (i>=9) {
            sequences[hash_value]++;
            hash_value -= mult * val[s[i-9]];
        }
    }
    vector<string> ret;
    for (map<int,int>::iterator it=sequences.begin(); it != sequences.end(); it++) {
        if(it->second > 1) {
            ret.push_back(decrypt(it->first));
        }
    }
    return ret;
}

int main () {
    string s;
    int tcase = 1;
    while (cin >> s) {
        vector<string> seqs = repeatedDNASequences(s);
        cout << "Case N:" << tcase++ << endl;
        for (int i=0; i<seqs.size(); ++i) {
            cout << seqs[i] << endl;
        }
        cout << endl;
    }
    return 0;
}
