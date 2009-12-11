/** 
 * Title: Factorial Frequencies
 * URL: http://online-judge.uva.es/p/v3/324.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se utiliza la herramienta de BigInt para precalcular los valores hasta 366!
	+ Luego para cada entrada se consulta el valor de su factorial y se calculan las veces
	que ocurre cada una de sus cifras.
	
**/


#include <iostream> 
#include <cstring>
#include <iomanip>

#define BASE 10 // Base del número
#define DIGITS 1	// Cant. de digitos para cada cifra
#define SIZE 782	// Cant. de cifras del numero, en base BASE
#define MAX_FAC 366

using namespace std;

typedef long long data_type;

class BigInt{
  public:
    data_type num[SIZE];
    int offset;

    BigInt();
    BigInt(unsigned);

    BigInt operator*(BigInt& );


    void print();
    void zero_justify();
};

BigInt fact[MAX_FAC + 1];

int main(){

  fact[0] = BigInt(1);
  // calcular todos los factoriales
  for (unsigned i = 1; i <= MAX_FAC; i++) 
    fact[i] = BigInt(i) * fact[i - 1];
  
  unsigned n;
  while(cin >> n){
	 if (0 == n) return 0;
    cout << n << "! --" << endl;
    fact[n].print();
  }

  return 0;
}

BigInt::BigInt(){
  num[SIZE-1] = 0;
  offset = SIZE-1;
}

BigInt::BigInt(unsigned n){
  int i = SIZE-1;

  if(n == 0)
	 num[i--] = 0;

  while(n > 0){
    num[i--] = n % BASE;
    n /= BASE;
  }
  offset = ++i;
}

BigInt BigInt::operator*(BigInt &b){
  BigInt res;
  BigInt* pA = this;
  BigInt* pB = &b;

  if(this->offset > b.offset){
    pA = &b;
    pB = this;
  }

  unsigned delta = 1, pos;

  data_type carry = 0;
  res.offset = -SIZE + pA->offset + pB->offset;

  memset(&res.num[res.offset], 0, sizeof(data_type[SIZE - res.offset]));

  for (int i = SIZE - 1; i >= pA->offset;  i--, delta++) {
    pos = SIZE - delta;
    carry = 0;

    for (int j = SIZE - 1; j >= pB->offset;  j--, pos--) {
      res.num[pos] += carry + pB->num[j] * pA->num[i];
      carry = res.num[pos] / BASE;
      res.num[pos] -= carry * BASE;
    }
    res.num[pos] = carry;
  }
  res.num[pos] = carry;

  while (res.num[res.offset] == 0 && res.offset < SIZE-1)
    res.offset++;

  res.zero_justify(); 

  return res;
}

void BigInt::zero_justify(){
  for(; num[offset] == 0 && offset < SIZE-1; offset++) ;
}


void BigInt::print(){
  unsigned cnt[10] = { 0 };
 
  int i = offset;  
  while (i < SIZE) cnt[num[i++]]++;
  
  cout << "   (0)" << setw(5) << cnt[0] \
    << "    (1)" << setw(5) << cnt[1]   \
    << "    (2)" << setw(5) << cnt[2]   \
    << "    (3)" << setw(5) << cnt[3]   \
    << "    (4)" << setw(5) << cnt[4] << endl;
  cout << "   (5)" << setw(5) << cnt[5] \
    << "    (6)" << setw(5) << cnt[6]   \
    << "    (7)" << setw(5) << cnt[7]   \
    << "    (8)" << setw(5) << cnt[8]   \
    << "    (9)" << setw(5) << cnt[9] << endl;
}

