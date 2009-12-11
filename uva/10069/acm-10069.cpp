/**
 * Title:Distinct Subsequences
 * URL: http://online-judge.uva.es/contest/data/0013/problemset/p4.html 
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
 	Se utiliza programacion dinamica para resolver el problema.
 	La funcion recursiva que se utiliza es la siguientes
 	s(i,j) es  1 si i = 0 && j > 0 ; 
 				  0 si i = 0 || j < i ||  s(i-1, j-1)  == 0; 
 				  max(1, s(i-1, j-1)+s(i, j-1)) si xi == zj (y s(i-1, j-1) > 0)
 				  s(i, j-1) si xi != zj 
	se utiliza bigint  ya que el tipo de datos primitivo no permite representar
	un numero como 10 ^100.
**/
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <cstdlib>

#define BASE 1000000000 // Base del número
#define SIZE 12	// Cant. de cifras del numero, en base BASE

using namespace std;

class BigInt{
	public:
		long long num[SIZE];
		int offset;
		
		BigInt(long long n = 0);
		BigInt operator+(BigInt &b);
		bool operator<(const BigInt &b);
		BigInt& operator=(const BigInt &b);
		void print();
};

vector<vector<BigInt> > m;

BigInt max(BigInt a, BigInt b){
	return (a < b)? b : a;
}

BigInt solve(char *x, char *z){
	m.resize(strlen(z)+1);
	m[0].assign(strlen(x)+1, BigInt(1));
	
	for(unsigned i = 1; i <= strlen(z); i++){
		m[i].assign(strlen(x)+1, BigInt(0));
	}
	
	for(unsigned i = 1; i < m.size(); i++){
		for(unsigned j = i; j < m[i].size(); j++){	
			if(x[j-1] == z[i-1]){
				if(BigInt(0) < m[i-1][j-1] ){
					BigInt b = m[i-1][j-1]+m[i][j-1];
					m[i][j] = max(BigInt(1), b);
				}
			} else {
				m[i][j] = m[i][j-1];
			}
		}
	}
	
	return m[strlen(z)][strlen(x)];
}

int main(){
	char x[10001], z[10001];
	int cases;
		
	scanf("%d", &cases);
	
	for(int i = 0; i < cases; i++){
		scanf("%s%s", x, z);
		solve(x, z).print();		
	}
	
	return 0;
}

BigInt::BigInt(long long n){
	int i = SIZE-1;

	if(n == 0)
		num[i--] = 0;

	while(n > 0){
		num[i--] = n % BASE;
		n /= BASE;
	}
	offset = ++i;
}


BigInt BigInt::operator+(BigInt &b){
	if(this->offset < b.offset){
		return (b + *this);
	}

	BigInt res;
	long long c = 0;
	int i = SIZE-1;

	for(; i >= this->offset; i--){
		res.num[i] = (c + this->num[i] + b.num[i]) % BASE;
		c = (c + this->num[i] + b.num[i]) / BASE;
	}
	for(; i >= b.offset; i--){
		res.num[i] = (c + b.num[i]) % BASE;
		c = (c + b.num[i]) / BASE;
	}		
	if(c > 0){
		res.num[i] = c;
		res.offset = i;
	} else 
		res.offset = b.offset;

	return res;
}

bool BigInt::operator<(const BigInt &b){
	// preguntar por los offset.
	if(this->offset != b.offset)
		return this->offset > b.offset;

	// comparar cuando tiene el mismo offset
	int ds = offset;

	while (ds < SIZE && this->num[ds] == b.num[ds]) ds++;

	if(ds == SIZE) return false; // son iguales

	return this->num[ds] < b.num[ds];
}

BigInt& BigInt::operator=(const BigInt &b){
	this->offset = b.offset;

	memcpy(this->num, b.num, sizeof(b.num));

	return *this;
}

void BigInt::print(){
	int i = offset;
	int c;
	long long temp;

	printf("%llu", num[i++]);

	while(i < SIZE){
		c = 0;
		temp = num[i];
		while(temp > 0){
			c++;
			temp /= 10;
		}
		for(int j=0; j<9-c; j++)
			printf("0");
		if(num[i] != 0)
			printf("%llu",num[i]);
		i++;
	}
	printf("\n");
}

