//Maximum 1D sum
//https://www.youtube.com/watch?v=ohHWQf1HDfU

#include <iostream>
#include <vector>

using namespace std;

int max1d(const vector<int> &v) {
    int sum=0, ret=0;
    for (int i=0; i<v.size(); ++i) {
        if (sum + v[i] > 0) {
            sum += v[i];
        }
        else {
            sum = 0;
        }
        ret = max(sum, ret);
    }
    return ret;
}

int main () {
    int n;
    
    while(cin >> n) {
        if (!n) return 0;
        vector<int> dd(n);
        for (int i=0; i<n; ++i) {
            cin >> dd[i];
        }
        int r=max1d(dd);
        if (r>0) {
            cout << "The maximum winning streak is " << r << "." << endl;
        }
        else {
            cout << "Losing streak." << endl;
        }
    }
    return 0;
}
