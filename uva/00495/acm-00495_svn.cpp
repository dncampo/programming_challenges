/**
 * Title: Fibonacci Freeze
 * URL: http://acm.uva.es/problemset/v4/495.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se calculan los números de Fibonacci hasta el Fib(1000) y se los almacena en un arreglo.
	(se debe definir un número grande en un arreglo y definirle la suma, dado que los tipos de datos 
	incorporados no pueden almacenar tal valor).
	Por último, para imprimir la salida correspondiente se busca en el arreglo el número de
	Fibonacci que se require en entrada.
**/

#include <cstdio>

#define MAX_FIB 5001 //cant. total de fib. a calc.
#define MAX_DIG 1045 //cant. díg. del fib más grande

using namespace std;

void init(void);
void suma(int); 
bool mayor(int a[MAX_DIG], int b[MAX_DIG]);
bool mayorIgual(int a[MAX_DIG], int b[MAX_DIG]);


int fib[MAX_FIB][MAX_DIG];

void print(int pos){
	int a = 0;
	while (fib[pos][a] == -1)a++;
	printf("The Fibonacci number for %d is ",pos);
	for(; a < MAX_DIG; a++)
		printf("%d",fib[pos][a]);
	printf("\n");
}

int main(){
	for(int i =0; i < MAX_FIB; i++)
		for(int j =0; j < MAX_DIG; j++)
			fib[i][j]= -1;
	
	init(); //let's get calc those fibs
	int num;

	while(1){		
		if(scanf("%d",&num) == EOF) return 0;
		print(num);
	}
	return 0;
}

void init(){
	fib[0][MAX_DIG-1] = 0;
	fib[1][MAX_DIG-1] = 1;
	fib[2][MAX_DIG-1] = 1;
	for(int cont = 2; cont < MAX_FIB - 1; cont++)
		suma(cont);	
}

void suma(int index){
	const int *a= fib[index-1];
	const int *b= fib[index];
	int *r = fib[index+1];
	int c=0;
	int i=MAX_DIG-1;

	for(;a[i] != -1 || b[i] != -1; i--){
		c += a[i]>=0 ? a[i]: 0;
		c += b[i]>=0 ? b[i]: 0;
		r[i] = c%10;
		c /=10;
	}
	if(c > 0) {
		r[i]=c;
	}	
}



//EOF
