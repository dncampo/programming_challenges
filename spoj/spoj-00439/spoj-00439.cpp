/**
 * Title: Not So Fast Multiplication
 * URL: https://www.spoj.pl/problems/TMUL/
 * Resources of interest:
 * Solver group: David-Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
	+  Se realizan los siguientes pasos: 
    + Se cargan todos los casos de prueba;
    + Se los convierte a base BASE;
 	 + Cada par (a(i); b(i)) se los deja de la forma a(i) >= b(i), es decir, 
      si a(i) es menor que b(i), se intercambia a(i) por b(i).
	 + Se calculan solo los casos de prueba que no están repetidos y luego se los imprime.
**/

#include <cmath>
#include <iostream>
using namespace std;

#define CASES 1000

#define MAXDIGMUL 2226  // MAXDIG *2
#define MAXDIG 1113	//10000/9
#define BASE 1000000000  // 10^9 
#define DIGXPOS 9

unsigned num_a[CASES][MAXDIG];  // primer columna de numeros largos
unsigned offset_a[CASES];
unsigned num_b[CASES][MAXDIG]; // segunda columna de numeros largos
unsigned offset_b[CASES];
unsigned res[CASES][MAXDIGMUL]; // resultado de multiplicar num_a[i] * num_b[i]
unsigned offset_res[CASES];
unsigned cases; // cantidad de casos de prueba.

/* 
 * Multiplica dos numeros largos
 */
void tmul(short index) {
	unsigned delta = 1, pos, carry = 0;

	offset_res[index] = offset_a[index] + offset_b[index];

	for (unsigned a = MAXDIG - 1; a >= offset_a[index];  a--, delta++) {
		pos = MAXDIGMUL - delta;
		carry = 0;

		for (unsigned b = MAXDIG - 1; b >= offset_b[index];  b--, pos--) {
			unsigned long long tmp = carry + (unsigned long long) num_b[index][b] * (unsigned long long) num_a[index][a];

			carry = tmp / BASE;
			res[index][pos] += tmp % BASE;

			if (res[index][pos] > BASE - 1) {
				carry += res[index][pos] / BASE;
				res[index][pos] = res[index][pos] % BASE;
			}
		}
		res[index][pos] = carry;
	}
	res[index][pos] = carry;

	while (res[index][offset_res[index]] == 0 && offset_res[index] < MAXDIGMUL-1)
		offset_res[index]++;
}

/*
 * convierte el entero largo tmp a su equivalente en base BASE.
 */
void convert( unsigned tmp[10000], unsigned index, unsigned size, bool a){
	int i;
	int pos = MAXDIG;

	for(i = size; i >= DIGXPOS - 1; i -= DIGXPOS){
		int num = 0, j;
		for(j = i-DIGXPOS+1; j < i; j++){
			num += tmp[j];
			num *= 10;
		}
		num += tmp[j];

		if(a){
			num_a[index][--pos] = num;
		}else{
			num_b[index][--pos] = num;
		}
	}

	if(i >= 0){
		int num = 0, j;
		for(j = 0; j < i; j++){
			num += tmp[j];
			num *= 10;
		}
		num += tmp[j];

		if(a){
			num_a[index][--pos] = num;
		}else{
			num_b[index][--pos] = num;
		}
	}
	if(a){
		offset_a[index] = pos;
	}else{
		offset_b[index] = pos;
	}
}

/* 
 * Comparar num_a[index] con num_b[index].
 * Retorna 1 si num_a[index] > num_b[index], 
 * -1 si num_a[index] < num_b[index] y 0 si son iguales.
 */
int compare(int index){
	unsigned *a = num_a[index], *b = num_b[index];
	
	if(offset_a[index] > offset_b[index]) 
		return -1;
	else if(offset_b[index] > offset_a[index])
		return 1;
		
	for(int i = offset_a[index]; i < MAXDIG; i++){
		if(a[i]> b[i])
			return 1;
		else 	if(a[i] < b[i]) 
		return -1;
	}
	
	return 0;
}

/*
 * Compara a con b y retorna 1 si son iguales, 0 en caso contrario.
 */
int equals(unsigned *a, unsigned *b, unsigned offset_a, unsigned offset_b){
	if(offset_a != offset_b) 
		return 0;
		
	for(int i = offset_a; i < MAXDIG; i++){
		if(a[i] !=  b[i])
			return 0;
	}

	return 1;
}

/*
 * Intercambia los numeros largos que se encuentran en la posicion i 
 * de los vectores num_a y num_b.
 */
void swap(unsigned i){
	unsigned tmp[MAXDIG], sizetmp;
	
	for(unsigned n = offset_a[i]; n < MAXDIG; n++ )
		tmp[n] = num_a[i][n];
	
	for(unsigned n = offset_b[i]; n < MAXDIG; n++ )
		num_a[i][n] = num_b[i][n];
	
	for(unsigned n = offset_a[i]; n < MAXDIG; n++ )
		num_b[i][n] = tmp[n];
	
	sizetmp = offset_a[i];
	offset_a[i] = offset_b[i];
	offset_b[i] = sizetmp;
}

/*
 * Retorna un indice mayor o igual que cero si 
 * ya se realizo una multiplicacion equivalente
 * antes que el indice i, -1 en caso contrario.
 */
int solved(unsigned i ) {
	unsigned *a = num_a[i], *b = num_b[i];
	unsigned offseta = offset_a[i], offsetb = offset_b[i];

	for(unsigned index = 0; index < i; index ++){
		if(equals(num_a[index], a, offset_a[index], offseta)){
			if(equals(num_b[index], b, offset_b[index], offsetb)){
				return index;
			}
		}
	}

	return -1;
}

/*
 * Imprime un numero largo.
 */
void print (int i){
	for(unsigned j = offset_res[i]; j < MAXDIGMUL; j++){
		if(j != offset_res[i]){
			if (res[i][j] < 10)
				printf("00000000");
			else if (res[i][j] < 100)
				printf("0000000");
			else if (res[i][j] < 1000)
				printf("000000");
			else if (res[i][j] < 10000)
				printf("00000");
			else if (res[i][j] < 100000)
				printf("0000");
			else if (res[i][j] < 1000000)
				printf("000");
			else if (res[i][j] < 10000000)
				printf("00");
			else if (res[i][j] < 100000000)
				printf("0");
		}
		printf("%u", res[i][j]);
	}
	printf("\n");
}

int main (){	
	int index, c;
	unsigned tmp[10000];

	scanf("%d\n", &cases);

	for (unsigned n = 0; n < cases; n++){
		for(index = 0; (c = getchar()) != ' '; index++){	
			tmp[index] = c - 48;
		}	

      convert(tmp, n, index - 1, true);

		for(index = 0; (c = getchar()) != '\n'; index++){	
			tmp[index] = c - 48;
		}	

      convert(tmp, n, index - 1, false);
	}
	
	for(unsigned i =0; i < cases; i++){
		if(compare(i) > 0)
			swap(i);
	}

 	for(unsigned i = 0; i < cases; i++) { 		
 		int r = solved(i);
		
		if(r >= 0){ // ya se calculó.. imprimir
			print(r);
		} else { 		// resolver e imprimir.
 			tmul(i);
 			print(i);
		}
 	}
}

