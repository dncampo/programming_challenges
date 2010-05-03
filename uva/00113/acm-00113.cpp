/**
 * Title: Power of Cryptography
 * URL: http://uva.onlinejudge.org/external/1/113.html
 * Resources of interest:
 * Solver group: Leo
 * Contact e-mail: bortoli.leonardo at gmail dot com
 * Description of solution:
    Se realiza una busqueda binaria de los posibles numeros k, hasta encontrar aquel que cumpla k^n = p
**/

#include<cstring>
#include<iostream>

#define MAX 2000

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
      
      Bigint(unsigned n){
      	int i = MAX - 1;
      	memset(num, 0, sizeof(num));
	
	      if(n == 0)
		      num[i--] = 0;
	
	      while(n > 0){
		      num[i--] = n % 10;
		      n /= 10;
	      }
	      offset = ++i;
      }
      
      bool operator>(const Bigint& ) const;
		bool operator!=(const Bigint& ) const;
};

bool Bigint::operator>(const Bigint &b) const{
   if(offset != b.offset)
      return offset < b.offset;

   int ds = offset;

   while (ds < MAX && num[ds] == b.num[ds]) ds++;

   if(ds == MAX) return false;

   return num[ds] > b.num[ds];
}

bool Bigint::operator!=(const Bigint &b) const{
   if(offset != b.offset){
      return true;
   }

   int ds = offset;

   while (ds < MAX && num[ds] == b.num[ds]) ds++;

   return ds < MAX;
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

void pow(const Bigint &a, const unsigned n, Bigint &r){
   if(n == 0){ // ver el tema 0^0 = indefinido
      r.num[MAX-1] = 1;
      return;
   }
   if(n == 1){
      copy(a, r);
      return;
   }
   
   Bigint tmp;
   if(n & 1){
      pow(a, n-1, tmp);
      mul(a, tmp, r);
   } else{
      pow(a, n >> 1, tmp);
      mul(tmp, tmp, r);
   }
}

int main(){
   unsigned n;
   char p[102];

   while(~scanf("%u\n%s", &n, p)){
      Bigint res(p), tmp;
   
      unsigned a = 1, b = 1000000000;
      unsigned k = (a + b) / 2;
    
      pow(Bigint(k), n, tmp);

      while(tmp != res){
         if(tmp > res){
            b = k - 1;
         } else{
            a = k + 1;
         }
         
         k = (a + b) / 2;
         
         tmp.offset = MAX - 1;
         memset(tmp.num, 0, sizeof(tmp.num));
         
         pow(Bigint(k), n, tmp);
      }
      
      cout << k << endl;
   }

   return 0;
}

