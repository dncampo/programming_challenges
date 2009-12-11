/**
 * Title: Modular Fibonacci
 * URL: http://uva.onlinejudge.org/external/102/10229.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   Para implementar la solucion se utiliza la siguiente propiedad:
        Fn = Fn
   Fn-1+Fn = Fn+1
   que es mismo que A^n = (Fn; Fn+1) donde A = (0,1;1,1)  
   para acelerar las operaciones se utiliza la tecnica de 
   divide y venceras para el calculo de A^n.
**/

#include <iostream>
using namespace std;

int square[] ={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};
struct Matrix{
   unsigned long long a, b, c, d;
};

unsigned long long fib(int n){
   unsigned long long j = 1, fib = 1, tmp;
      
   for(int k = 3; k <= n; k++){
      tmp = fib;
      fib = j+fib;
      j = tmp;
   }
   return fib;
}

Matrix fibonacci(int n, int mod){
   if(n == 1){
      Matrix m = {0,1,1,1};
      return m;
   } 
   
   Matrix x = fibonacci(n/2, mod);
   Matrix r={(x.a*x.a+x.b*x.c)%mod, (x.a*x.b+x.b*x.d)%mod, (x.a*x.c+x.d*x.c)%mod, (x.b*x.c+x.d*x.d)%mod};

   if(n & 1){
      unsigned long long tmp = r.a;
      r.a = r.b;
      r.b = (r.b+tmp)%mod;

      tmp = r.c;
      
      r.c = r.d;
      r.d = (r.d+tmp)%mod;
   }   
   return r;
   
}

int main(){
   int n, m;

   while(cin >> n >> m){
      if(n == 0 || m == 0) 
         cout << 0 << endl;
      else if(n == 1) 
         cout << 1 << endl;
      else
         cout << fibonacci(n-1, square[m]).d << endl;
   }
   
   return 0;


}
