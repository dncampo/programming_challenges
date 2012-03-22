/**
 * Title: How many Fibs?
 * URL: http://icpcres.ecs.baylor.edu/onlinejudge/external/101/10183.html
 * Resources of interest:
 * Solver group: Yeyo-David-Leo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   + Se calculan los números de Fibonacci mientras sean <= 10^100 y se los almacena en un arreglo.
	(se debe definir un número grande en un arreglo y definirle la suma, dado que los tipos de datos 
	incorporados no pueden almacenar tal valor).
	Por último, para imprimir la salida correspondiente se busca en el arreglo todos los número de
	Fibonacci que esten en el rango dado en la entrada.
**/

#include <iostream>

#define MAX_FIB 484 //cant. total de fib. a calc.
#define MAX_DIG 102 //cant. díg. del fib más grande

using namespace std;

void init(void);
void suma(int); 
int contar(int [], int []);
bool mayor(int a[MAX_DIG], int b[MAX_DIG]);
bool mayorIgual(int a[MAX_DIG], int b[MAX_DIG]);
void getArreglo(string , int [MAX_DIG] );

int fib[MAX_FIB][MAX_DIG];

int main(){
	for(int i =0; i < MAX_FIB; i++)
		for(int j =0; j < MAX_DIG; j++)
			fib[i][j]= -1;
	
	init(); //let's get calc those fibs

	string sx, sy;
	int a[MAX_DIG], b[MAX_DIG];
	do{
		cin >> sx >> sy;
		if(!(sx == "0" && sy == "0")) {			
			getArreglo(sx, a);
			getArreglo(sy, b);
			cout << contar(a, b) << endl;
		}
	} while(sx != "0" || sy != "0");
	return 0;
}

void init(){
	fib[1][MAX_DIG-1] = 1;
	fib[2][MAX_DIG-1] = 2;
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

int contar(int x[MAX_DIG], int y[MAX_DIG]){
	int cont = 0;

	for(int i = 1; i< MAX_FIB; i++){
		if(mayor(fib[i],y)) return cont;
		if(mayorIgual(fib[i], x)) cont++;
	}
	return cont;
}

bool mayor(int a[MAX_DIG], int b[MAX_DIG]){
	int i = 0;
	while(a[i] == b[i] && i < MAX_DIG) i++;
	return MAX_DIG != i && a[i] > b[i];
}

bool mayorIgual(int a[MAX_DIG], int b[MAX_DIG]){
	int i = 0;
	while(a[i] == b[i] && i < MAX_DIG) i++;	
	return i == MAX_DIG || a[i] >= b[i];
}

void getArreglo(string s, int res[MAX_DIG]){
	string::reverse_iterator i = s.rbegin();
	for(int index= MAX_DIG-1; index >=0 ; index--){
		if(i == s.rend())
			res[index] = -1;
		else {
			res[index] = (int)((*i)-'0');
			i++;
		}
	}
}

//EOF
