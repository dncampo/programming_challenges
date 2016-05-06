//https://uva.onlinejudge.org/external/4/484.html

#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main(){
    int n;
    map<int, unsigned> oc;
    vector<int> ap;
    while (cin >> n) {
        if (oc[n]==0) {
            ap.push_back(n);
        }
        oc[n]++;
    }
    
    for (unsigned i=0; i<ap.size(); i++) {
        cout << ap[i] << " " << oc[ap[i]] << endl;
    }
    return 0;
}


