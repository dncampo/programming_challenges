/*
Title: Compare Substring
Tags: strings, lcs
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1237
Resources of interest:
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Solution remarks: Just apply a longest common subsequence between two strings
*/

#include<iostream>
#include<string>

using namespace std;

int max(int a, int b)
{   return (a > b)? a : b; }

/* Returns length of longest common substring of X[0..m-1] and Y[0..n-1] */
int lcs(const string& X, const string &Y) {
    unsigned m = X.size();
    unsigned n = Y.size();

    int matrix[m+1][n+1];
    int result = 0;  // To store length of the longest common substring

    /* Following steps build matrix[m+1][n+1] in bottom up fashion. */
    for (int i=0; i<=m; i++) {
        for (int j=0; j<=n; j++) {
            if (i == 0 || j == 0)
                matrix[i][j] = 0;

            else if (X[i-1] == Y[j-1]) {
                matrix[i][j] = matrix[i-1][j-1] + 1;
                result = max(result, matrix[i][j]);
            }
            else matrix[i][j] = 0;
        }
    }
    return result;
}

int main () {
  string a, b;

  while (getline(cin, a) && getline(cin, b)) {
    cout << lcs(a,b) << '\n';
  }

  return 0;
}
