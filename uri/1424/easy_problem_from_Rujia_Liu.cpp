/*
Title: Easy Problem from Rujia Liu?
Tags: adhoc, basic
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1424
Resources of interest:
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Solution remarks: Just store the index of occurrence of each number as they appear.
*/

#include<cstdio>
#include<vector>

using namespace std;

int main () {
    unsigned n, m, t, k, v;
    while (~scanf("%u%u", &n, &m) ) {
        vector<vector<unsigned> > vv(1000001, vector<unsigned>());
        
        for (int i=0; i<n; i++) {
            scanf("%u", &t);
            vv[t].push_back(i+1);
        }
        for (int j=0; j<m; j++) {            
            scanf("%u%u", &k, &v);
            if (k > vv[v].size()) {
                printf ("0\n");
            }
            else {
                printf ("%u\n", vv[v][k-1]);
            }
        }
    }
    return 0;
    
}
