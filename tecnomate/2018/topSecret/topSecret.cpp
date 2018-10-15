#include <iostream>
#include <vector>

using namespace std;

int mapDecoding(string message) {
    vector<int> dp (message.size()+1, 0);
    dp[message.size()] = 1;
    int limit = 1000000007;
    int last = 0;
    
    for (int i = message.size()-1; i>=0; --i) {
        int simpleDigit = message[i] - '0';
        
        if (0 == simpleDigit) {
            dp[i] = 0;
            continue;
        }
        int total = dp[i+1];
        if (i < message.size()-1) {
            int complexDigit = 10 * simpleDigit + last;
            if (complexDigit <= 26) total += dp[i+2];
        }
        dp[i] = total % limit;
        last = simpleDigit;
    }
    return dp[0];
}

int main () {
    string s;
    int tcase = 1;
    while (cin >> s) {
        cout << "Case N:" << tcase++ << endl;
        cout << mapDecoding(s) << endl;
        cout << endl;
    }
    return 0;
}
