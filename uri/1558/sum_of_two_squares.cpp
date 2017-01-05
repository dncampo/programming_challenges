/*
Title: Sum of two squares
Tags: adhoc, basic, math, brute force
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1558
Resources of interest:
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Solution remarks: none.
*/

#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

#define N 10001
int ps[N]={0};

double r;

int main() {
    for (int i=0; i<=sqrt(N); i++) {
        ps[i*i] = 1;
    }

    int n;
    while (scanf("%d", &n)!=EOF) {
        bool flag = true;
        for (int i=0; flag && i<=n>>1; i++) {
            if(ps[i] && ps[n-i]) {
                printf("YES\n");
                flag=false;
                break;
            }
        }
        if (flag)
            printf("NO\n");
    }
    return 0;
}
