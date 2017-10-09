#include <iostream>
#include <vector>

using namespace std;

unsigned long long reversePairs(vector<long long int>& nums) {
    int n = nums.size();
    unsigned long long count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] > nums[i] * 2LL)
                count++;
        }
    }
    return count;
}

int main () {
    vector<long long int> v;
    long long int n;
    
    while (cin >> n) {
        v.push_back(n);
    }
    cout << reversePairs(v) << endl;
    return 0;
}
