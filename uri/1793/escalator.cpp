/*
Title: Escalator
Tags: adhoc, basic
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1793
Resources of interest:
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Solution remarks: none.
*/

#include <iostream>

using namespace std;

int main() {
    int N, n1, n2;

    while (cin >> N) {
        if (0==N) break;

        int sum=10;

        cin >> n2;

        for (int i=1; i < N; ++i) {
            n1 = n2;
            cin >> n2;

            if ((n2-n1) > 10) {
                sum += 10;
            }
            else {
                sum += n2-n1;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
