/**
 * Title: Count the Trees
 * URL: http://online-judge.uva.es/p/v100/10007.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   - Primero se resuelven todos los casos posibles (1 <= n <=300) utilizando
   un arreglo de N = 300 elementos y usando la siguiente fórmula:
      sum de 2<= i< 300 (p(j)* p(i-j-1), para todo 0 <= j < i
      y p(0) = 1, p(1)= 1
      
  -Luego a cada elemento de p se lo multiplica por i!, es decir 
   para cada 1 <=i < 300 se hace p(i) = p(i)*i!
   
  - Finalmente para cada entrada j se imprime p(j).  
      
  Aclaraciones: debido a que el número es muy grande, se tiene que utilizar una clase Bigint
  para resolver el problema.
**/

#include<cstdio>
#include<cstring>
#include <iostream>
#define SIZE 301
#define MAX 800
using namespace std;

class Bigint{
   public:
      int num[MAX+1];
      int offset;

      Bigint() {  
         offset = MAX - 1;
         memset(num, 0, sizeof(num));
      }
 
      Bigint(char n[]) {
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

   for(register int i = b.offset; i < MAX; i++){
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

   for(register int i = MAX-1; i >= r.offset; i--){
      r.num[i] = a.num[i] + b.num[i] + carry;
      carry = r.num[i] / 10;
      r.num[i] = r.num[i] - 10 * carry;
   }
   
   if(r.num[r.offset] == 0 ) {
      r.offset++;
   }
}
void copy(const Bigint &a, Bigint &r){
   r.offset = a.offset;
   memcpy(r.num, a.num, sizeof(a.num));
}

void mul(const Bigint &a, const Bigint &b, Bigint &r){
   if (b.offset < a.offset) {
      mul(b,a,r);
      return;
   }
   
   register int carry, carryR, ia, tmp, ds = 0;
   for(register int ib = MAX-1; ib >= b.offset; ib--){
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

Bigint result[SIZE];
Bigint fac[SIZE];

void solve(){
   copy(Bigint((char *)"1"), result[0]);
   copy(Bigint((char *)"1"), result[1]);   
   copy(Bigint((char *)"2"), result[2]);

   for(register int i = 3; i < SIZE; i++){
       for(register int j = 0; j < i; j++){
         Bigint b((char *)"0");
         mul(result[j], result[i-j-1], b);
         add(result[i], b, result[i]);
      }
   }

   copy(Bigint((char *)"1"), fac[0]);
   copy(Bigint((char *)"1"), fac[1]);   
   
   for(int i = 2; i < SIZE; i++){
      char numb[4];
      sprintf(numb, "%d", i);
      Bigint b(numb);
      mul(numb, fac[i-1], fac[i]);
   }

   for(int i = 1; i < SIZE; i++){
      Bigint r;
      mul(fac[i], result[i], r);
      copy(r, result[i]);
   }
}

int main(){
   int value;
   solve();
   
   while(cin >> value && value != 0){
      print(result[value]);
      cout << endl;
   }
 
   return 0;
}

