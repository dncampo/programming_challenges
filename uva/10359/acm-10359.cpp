/**
 * Title: Tiling
 * URL: http://uva.onlinejudge.org/external/103/10359.html
 * Resources of interest:
 * Solver group: David, Leo
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se visualiza una fórmula de recurrencia que resuelve el problema:
   a(i) = 2 * a(i-2) + a(i)
   + Se utiliza la herramienta de Bigint para almacenar los resultados.

**/

#include <cstdio>
#include <cstring>
#include <iostream>

#define MAX 80

using namespace std;

class Bigint{
   public:
      int num[MAX+1];
      int offset;

      Bigint() {  
         offset = MAX - 1;
         memset(num, 0, sizeof(num));
      }
 
      Bigint(const char n[]) {
         offset = MAX - strlen(n);
         memset(num, 0, sizeof(int[offset]));
      
         for(int i = offset; i < MAX; i++){
            num[i] = n[i-offset] - '0';
         }
      }

};

/*
 * Imprimir un Bigint
 */
void print(Bigint &b){
   int size = MAX - b.offset + 1, index = 0;
   char num_print[size];

   for(int i = b.offset; i < MAX; i++){
      num_print[index++] = b.num[i] + '0';
   }
   num_print[index] = '\0';
   
   printf("%s",num_print);
}

/*
 *  Operación de adición
 */
void add(const Bigint &a, const Bigint &b, Bigint &r){
   int carry = 0;
   r.offset = min(a.offset, b.offset) - 1;   

   for(int i = MAX-1; i >= r.offset; i--){
      r.num[i] = a.num[i] + b.num[i] + carry;
      carry = r.num[i] / 10;
      r.num[i] = r.num[i] - 10 * carry;
   }
   
   if(r.num[r.offset] == 0 ) {
      r.offset++;
   }
}

/*
 *  Operación de multiplicación
 */
void mul(const Bigint &a, const Bigint &b, Bigint &r){
   if (b.offset < a.offset) {
      mul(b,a,r);
      return;
   }
   
   int carry, carryR, ia, tmp, ds = 0;
   for(int ib = MAX-1; ib >= b.offset; ib--){
      ia = MAX-1;
      carry = carryR = 0;
         
      for( ; ia >= a.offset; ia--){
         tmp = b.num[ib] * a.num[ia] + carry;                                   
         carry = tmp / 10;                                                                   
         r.num[ia - ds] += tmp - 10 * carry + carryR; // tmp % 10 = tmp - 10*carry             
         carryR = r.num[ia - ds] / 10;     
         r.num[ia - ds] = r.num[ia - ds] - 10 * carryR; // r.num[ia - ds] %= 10;               
      }

      r.num[ia - ds] = carry + carryR;
      ds++;
   }

   r.offset = ia - ds;
   while(r.num[r.offset] == 0 && r.offset < MAX - 1){
      r.offset++;
   }
}


Bigint res[251];

int main(){
   res[0] = Bigint ("1");
   res[1] = Bigint ("1");
   res[2] = Bigint ("3");

   Bigint two = Bigint("2");
   
   for (unsigned i = 3; i <= 250; i++) {
   
      // ai = 2 * ai-2 + ai-1
      Bigint n2;
      mul(res[i - 2], two, n2);
      add(res[i - 1], n2, res[i]);
   }
   
   int num;
   while (cin >> num) {      
      print(res[num]);
      cout << '\n';
   }
   
   return 0;
}

