#include <iostream>
#include <random>

using namespace std;

int minn = 0;
int maxx = 1;
int total = 5;

random_device rd;     // only used once to initialise (seed) engine
mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
uniform_int_distribution<int> uni(minn,maxx); // guaranteed unbiased


int main () {
    for (int i=0; i<total; ++i) {
        long long int random_integer = uni(rng);
        cout << random_integer << " ";
    }
    cout << endl;
    return 0;
}
