// COMPILE WITH FLAG: -std=c++0x
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> killProcess(vector <int> pid, vector <int> ppid, int kill) {
    vector <int> l;
    if (kill == 0)
        return l;
    l.push_back(kill);
    for (int i = 0; i < ppid.size(); i++)
        if (ppid[i] == kill) {
            vector<int> tmp = killProcess(pid, ppid, pid[i]);
            l.insert(l.end(), tmp.begin(), tmp.end());
        }
    return l;
}

/*
Devuelve en el vector tokens los elementos obtenidos del string str, delimitados
por los caracteres de delimiters
*/
void tokenize(const string& str, vector<int>& tokens, const string& delimiters = " ") {
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)  {
        string temp = str.substr(lastPos, pos - lastPos);
        tokens.push_back(stoi(temp));
        lastPos = str.find_first_not_of(delimiters, pos);
        pos = str.find_first_of(delimiters, lastPos);
    }
}

int main() {
    vector<int> pid, ppid, res;
    int k;
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    cin >> k; cin.ignore();
    tokenize(s1, pid);
    tokenize(s2, ppid);
    res = killProcess(pid, ppid, k);
    sort(res.begin(), res.end());
    for (int i=0; i<res.size();++i) {
        cout << res[i] << endl;
    }
    return 0;
}
