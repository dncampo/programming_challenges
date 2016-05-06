#include <iostream>
#include <map>

using namespace std;

int main () {
    int m,n, s;
    cin >> m >> n;
    map<string, int> mp;
    
    string p;
    for (int i=0; i<m; i++) {
        cin >> p >> s;
        mp[p] = s; 
    }
    s=0;
    while (cin >> p) {
        if ("." == p) {
            cout << s << endl;
            s=0;
        }
        s += mp[p];
    }
    

    return 0;
} 
