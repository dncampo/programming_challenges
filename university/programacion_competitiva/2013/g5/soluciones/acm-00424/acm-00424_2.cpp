/**
 * Title: Integer Inquiry
 * URL: http://icpcres.ecs.baylor.edu/onlinejudge/external/4/424.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution: 
   primero se leen todos los numeros 
   luego se hace una suma binaria:
      a + b + c + d = (a+b)+ (c+d) = X + Y = Z
      luego se imprime la solucion.
      
   Para el tratamiento de los numeros largos se utliza la clase BigInt.
   
 **/
#include <vector> 
#include <iostream> 
#include <cstdlib>
#include <cstring>
#include <cstdio>

#define BASE 1000000000000000000 // Base del número
#define DIGITS 18	// Cant. de digitos para cada cifra
#define SIZE 6	//0Cant. de cifras del numero, en base BASE

using namespace std;

typedef long long data_type;

class BigInt{
	public:
		data_type num[SIZE];
		int offset;

		BigInt();
		BigInt(const BigInt & ); //constructor por copia!!
		BigInt(char *, const int );
		
		BigInt operator+(BigInt& );
		BigInt &operator=(const BigInt& );

		void print();
		void zero_justify();
};

int main(){
	char num[102];
   vector<BigInt> list;

   scanf("%s", num);

	while(strcmp(num, "0") != 0){
		list.push_back(BigInt(num,strlen(num)));      
	   scanf("%s", num);
	}

   while(list.size() > 1){		
      for(int i = list.size()-1; i >0 ; i -=2){
         BigInt a = list[i-1];
         BigInt b = list[i];            
         list[i-1] = a + b;
         list.erase(list.begin()+i);
      }
   }
   
   list[0].print();
   printf("\n");

	return 0;
}

BigInt::BigInt(){
	num[SIZE-1] = 0;
	offset = SIZE-1;
}

BigInt::BigInt(char* n, int size){
	int it = size; //itera sobre el char*	
	int end = 0;
	char temp = '\0';
	int i = SIZE - 1; //itera sobre el num

	if(strcmp(n,"0") == 0) {
		num[i] = 0;
	} else {
		while(it > end + DIGITS) {
			it -= DIGITS;
			num[i--] = atol(&n[it]);
			
			if(it+DIGITS != size)
				n[it+DIGITS] = temp;
				
			temp = n[it];
			n[it] = '\0';
		}
		
		num[i] = atol(&n[end]);
		n[strlen(n)] = temp;
	}
	
	offset = i;
}

BigInt::BigInt(const BigInt &b){
	this->offset = b.offset;
	
	memcpy(this->num, b.num, sizeof(b.num));
}


BigInt& BigInt::operator=(const BigInt &b){
	this->offset = b.offset;
	
	memcpy(this->num, b.num, sizeof(b.num));
	
	return *this;
}


BigInt BigInt::operator+(BigInt &b){ 
	if(this->offset < b.offset){
		return (b + *this);
	}

	BigInt res;
	data_type c = 0, t;
	int i = SIZE-1;
	
	for(; i >= offset; i--){
		t =  c + num[i] + b.num[i];
		c = t / BASE;
		res.num[i] = t - c * BASE;
	}
			
	for(; i >= b.offset; i--){
		t = c + b.num[i];
		c = t / BASE;
		res.num[i] = t - c * BASE;
	}		
	if(c > 0){
		res.num[i] = c;
		res.offset = i;
	} else 
		res.offset = b.offset;

	return res;
}

void BigInt::zero_justify(){
	for(; num[offset] == 0 && offset < SIZE-1; offset++) ;
}

void BigInt::print(){
	int i = offset;
	int c;
	data_type temp;
	
   printf("%lld", num[i++]);
				
	while(i < SIZE){
		c = 0;
		temp = num[i];
		while(temp > 0){
			c++;
			temp /= 10;
		}
		for(int j=0; j<DIGITS-c; j++)
			printf("0");
		if(num[i] != 0)
			printf("%lld", num[i]);
		i++;
	}
}

