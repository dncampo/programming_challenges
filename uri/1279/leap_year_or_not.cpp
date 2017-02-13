/*
Title: Leap Year or Not Leap Year and …
Tags: number theory, adhoc, basic math
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1279
Resources of interest:
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Solution remarks: none.
*/

#include <iostream>

using namespace std;

bool is_leap (int a) {
    return a%400==0 || (a%4==0 && a%100);
}

int main() {
    int a;
    
    while (cin >> a) {
        bool flag = true;
        

        if (is_leap(a)) {
            cout << "This is leap year." << endl;
            flag = false;
        }

        if (a%15==0) {
            cout << "This is huluculu festival year." << endl;
            flag = false;
        }

        if (a%55 == 0 && is_leap(a)) {
            cout << "This is bulukulu festival year." << endl;
            flag = false;
        }
        
        if (flag)
            cout << "This is an ordinary year." << endl;
        
        cout << endl;
    }
    return 0;
}
