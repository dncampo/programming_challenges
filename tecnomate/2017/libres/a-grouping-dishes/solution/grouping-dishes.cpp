#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

/*
Devuelve en el vector tokens los elementos obtenidos del string str, delimitados
por los caracteres de delimiters
*/
void tokenize(const string& str, vector<string>& tokens, const string& delimiters = " ") {
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)  {
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        lastPos = str.find_first_not_of(delimiters, pos);
        pos = str.find_first_of(delimiters, lastPos);
    }
}

vector<vector<string> > groupingDishes(vector<vector<string> > dishes) {
    map<string, set<string> > byIng;
    
    for (vector<string>& v : dishes) {
        string d = v[0];
        for (int i=1; i<v.size(); ++i) {
            byIng[v[i]].insert(d);
        }
    }
    vector<vector<string> > ret;//(byIng.size());
    int c=0;
    for (map<string, set<string> >::iterator it=byIng.begin(); it != byIng.end(); ++it) {
        if (it->second.size() < 2) continue;
        vector<string> vtemp(it->second.size()+1);
        ret.push_back(vtemp);
        ret[c][0] = it->first;
        int d=1;
        for (set<string>::iterator it2=it->second.begin(); it2 != it->second.end(); ++it2, ++d) {
            ret[c][d] = *it2;
        }
        c++;
    }
    return ret;
}

int main() {
    string line;
    vector<vector<string> > data, res;
    
    while(getline(cin, line)) {
        vector<string> v;
        tokenize(line, v, ",");
        data.push_back(v);
    }
    res = groupingDishes(data);
    
    for (int i=0; i<res.size(); ++i) {
        cout << res[i][0];
        for (int j=1; j<res[i].size(); ++j) {
            cout << "," << res[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
