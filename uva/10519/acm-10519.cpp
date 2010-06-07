/**
 * Title: !! REALLY STRANGE !!
 * URL: http://uva.onlinejudge.org/external/105/10519.html
 * Resources of interest:
 * Solver group: Leo
 * Contact e-mail: bortoli.leonardo at gmail dot com
 * Description of solution:
    + Hay que utilizar Bigint, ya que la entrada puede ser un numero muy grande (hasta 10^100).
    + De los primeros terminos de la sucesion se deduce la formula: a[n] = a[n-1] + 2(n-1) y
    + su forma cerrada es: a[n] = 2 + n(n-1)
**/
#include<iostream>
#include<cstring>

#define MAX 210

using namespace std;

class Bigint{
   public:
      int num[MAX+1];
      int offset;

      Bigint() {  
         offset = MAX - 1;
         memset(num, 0, sizeof(num));
      }

      Bigint(const string& n) {
         offset = MAX - n.size();
         memset(num, 0, sizeof(int[offset]));

         for(int i = offset; i < MAX; i++){
            num[i] = n[i-offset] - '0';
         }
      }
      
      Bigint(long long n){
         memset(num, 0, sizeof(num));

         int i = MAX-1;

         if(n == 0)
            num[i--] = 0;

         while(n > 0){
            num[i--] = n % 10;
            n /= 10;
         }
         offset = ++i;
      }
      
      bool operator==(const Bigint& ) const;

      const Bigint operator+(const Bigint& ) const;
      const Bigint operator-(const Bigint& ) const;
      const Bigint operator*(const Bigint& ) const;

      Bigint& operator=(const Bigint& );
};

bool Bigint::operator==(const Bigint &b) const{
   if(offset != b.offset)
      return false;

   int ds = offset;

   while (ds < MAX && num[ds] == b.num[ds]) ds++;

   return ds == MAX;
}

Bigint& Bigint::operator=(const Bigint &b){
   if(this != &b){
      offset = b.offset;
      memcpy(num, b.num, sizeof(b.num));
   }

   return *this;
}

ostream& operator<<(ostream& out, const Bigint& a){
   int size = MAX - a.offset + 1, index = 0;
   char num_print[size];

   for(int i = a.offset; i < MAX; i++){
      num_print[index++] = a.num[i] + '0';
   }
   num_print[index] = '\0';

   out << num_print;

   return out;
}

istream& operator>>(istream& in, Bigint& a){
   string str;
   in >> str;

   a = Bigint(str);

   return in;
}

const Bigint Bigint::operator+(const Bigint &b) const{
   Bigint r;   

   int carry = 0;
   r.offset = min(offset, b.offset) - 1;   

   for(int i = MAX-1; i >= r.offset; i--){
      r.num[i] = num[i] + b.num[i] + carry;
      carry = r.num[i] / 10;
      r.num[i] = r.num[i] - 10 * carry;
   }

   if(r.num[r.offset] == 0 )
      r.offset++;

   return r;
}

const Bigint Bigint::operator-(const Bigint &b) const{
   Bigint r;

   int i = MAX - 1, temp, borrow = 0;

   for(; i >= offset; i--){
      temp = num[i] - borrow;

      if(i >= b.offset)
         temp -= b.num[i];

      if(num[i] > 0)
         borrow = 0;

      if(temp < 0){
         temp += 10;
         borrow = 1;
      }

      r.num[i] = temp;
   }

   r.offset = offset;

   while (r.num[r.offset] == 0 && r.offset < MAX - 1)
      r.offset++;

   return r;
}

const Bigint Bigint::operator*(const Bigint &b) const{
   if(b.offset < offset)
      return b * (*this);

   Bigint r;

   int carry, carryR, ia, tmp, ds = 0;
   for(int ib = MAX-1; ib >= b.offset; ib--){
      ia = MAX-1;
      carry = carryR = 0;

      for( ; ia >= offset; ia--){
         tmp = b.num[ib] * num[ia] + carry;                                   
         carry = tmp / 10;                                                                   
         r.num[ia - ds] += tmp - 10 * carry + carryR;
         carryR = r.num[ia - ds] / 10;     
         r.num[ia - ds] = r.num[ia - ds] - 10 * carryR;
      }

      r.num[ia - ds] = carry + carryR;
      ds++;
   }

   r.offset = ia - ds;
   while(r.num[r.offset] == 0 && r.offset < MAX - 1)
      r.offset++;

   return r;
}

int main(){
   Bigint n;
   
   while(cin >> n){
      if(n == Bigint(0)){
         cout << "1\n";
      } else{
         cout << (Bigint(2) + n*(n - Bigint(1))) << '\n';
      }
   }
   
   return 0;
}
