/**
 * Title:  Digit Primes
 * URL: http://uva.onlinejudge.org/external/105/10533.html
 * Resources of interest:
 * Solver group: Leo
 * Contact e-mail: leonardobortoli at yahoo dot com dot ar
 * Description of solution:
	1) Se inicializa un array de 1000000 de elementos con la criba de eratostenes
	2) Luego se marcan todos los digit primes en ese array
	3) En otro array, se van guardando las apariciones de dichos numeros (en forma acumulada).
		De esta forma, solo se debe acceder al array con los limites del intervalo de entrada (i, j; i<=j),
		y restar dichos numeros para obtener la cantidad de digit primes en ese intervalo.
		Ej: para una entrada: i, j; el resultado de dicha operacion seria:
				how_many[j] - how_many[i]		
**/

#include <stdio.h>
#include <cstring>

#define SIZE 1000000

using namespace std;

char numbers[SIZE];
int how_many[SIZE];

bool is_digit_prime(int );
int solve(int, int);

int main(){
	// inicializar arreglos
	memset(numbers, 1, sizeof(char[SIZE]));
	how_many[1] = 0;
	
	// setear numeros primos
	for(int i=2; i<1001; i++)
		for(int j=2*i; j<SIZE; j+=i)
			numbers[j] = 0;
	
	// setear cantidad de digit primes en how_many
	for(int i=2; i<SIZE; i++){
		if(numbers[i] && is_digit_prime(i)){
			how_many[i] = how_many[i-1] + 1;
			numbers[i] += 2; // para marcar que i es un digit prime y no tener que calcularlo de nuevo
		}
		else
			how_many[i] = how_many[i-1];
	}

	// empezar a leer los datos e imprimir la salida
	int n, t1, t2;
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		scanf("%d%d", &t1, &t2);
		printf("%d\n", solve(t1, t2));
	}			

	return 0;
}

bool is_digit_prime(int n){
	int sum=0;
	for(; n > 0; n/=10)
		sum += n % 10;
	if(numbers[sum]) // si sum es primo
		return true;
	return false;
}

int solve(int t1, int t2){
	if(numbers[t1] == 3) // si t1 es digit prime
		return how_many[t2] - how_many[t1] + 1;
	else
		return how_many[t2] - how_many[t1];
}
