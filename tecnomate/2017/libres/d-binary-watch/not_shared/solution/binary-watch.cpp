#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

vector<string> readBinaryWatch(int num) {
    vector<string> rs;
    for (int h = 0; h < 12; h++)
    for (int m = 0; m < 60; m++)
        if (bitset<10>(h << 6 | m).count() == num)
            rs.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
    return rs;
}

int main() {
    int n;
    cin >> n;
    vector<string> res = readBinaryWatch(n);
    cout << res.size() <<endl;
    return 0;
}
