#include <iostream>

using namespace std;

#define Rep(i,n) for (int i(0),_n(n); i<_n; ++i)

int matrix_mult(int* A, int* B, int* ret) {
    Rep(i,2) {
        Rep(j,2) {
            Rep(k,2) {
                ret[i*2+k] = (ret[i*2+k] + A[i*2+j] * B[j*2+k]) % 1000;
            }
        }
    }
    return ret;
}

int fast_exponentiation(int* A, int n, int* A1) {
    if (n == 1) {
        Rep(i,4) {
            A1[i] = A[i];
        }
        return A1;
    }
    else if (n % 2 == 0) {
        int A_tmp[] = {0,0,0,0};
        fast_exponentiation(A, n/2, A_tmp);
        matrix_mult(A_tmp, A_tmp, A1);
        return A1;
    }
    else {
        int A_tmp[] = {0,0,0,0};
        fast_exponentiation(A, n - 1, A_tmp);
        matrix_mult(A, A_tmp, A1);
        return A1;
    }
}

int solve(int n) {
    int A[] = {3, 5, 1, 3};
    int ret[] = {0,0,0,0};
    fast_exponentiation(A, n, ret);
    return (2 * ret[0] + 999) % 1000;
}


int main()
{
    int T;
    scanf("%d", &T);
    Rep(t, T) {
        int n;
        scanf("%d", &n);
        int ret = solve(n);
        
        printf("Case #%d: %03d\n", t+1, ret);
    }
}

