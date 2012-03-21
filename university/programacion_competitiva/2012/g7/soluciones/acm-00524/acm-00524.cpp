/**
 * Title: Prime Ring Problem 
 * URL: http://acm.uva.es/p/v5/524.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
    + Utilizo la técnica de backtracking para resolver el problema. 
    + En resumen primero calculo todas las posibilidades y 
    + luego voy respondiendo de acuerdo a la entrada.
    + Hay soluciones solo para numeros pares (excepto el 1), 
    + asi que guardo en 6 matrices las soluciones de los n = 6,8,10,12,14 y 16 
    + para evitar calcularlos mas de una vez, y a las soluciones de n = 1,2,4 las 
    + imprimo directamente. Al tamaño de las matrices las obtuve despues 
    + de realizar una salida con el programa.
    + Por otro lado para acelerar el calculo de todas las posibilidades
    + ulilizo un arreglo de enteros que representa en cada ubicacion del 
    + un valor verdadero si el numero es primo, en caso contrario falso.
    + la cantidad de elementos del arreglo es 31 (16+15 ,que es el peor caso).
    + 
**/
#include <iostream>#include <string.h>

using namespace std;

#define MAX 17
#define MAXCANDIDATES 17
#define FALSE 0
#define TRUE 1 

char solution16[81024+1][40];
char solution14[2880+1][34];
char solution12[1024+1][28];
char solution10[96+1][22];
char solution8[4+1][17];
char solution6[2+1][13];


unsigned int i2 = 0,i4 = 0,i6=0,i8 = 0,i10 = 0,i12 = 0,i14 = 0,i16 = 0;

const int PRIMOS[] = {
	FALSE,	TRUE, 	TRUE,		TRUE, 	FALSE, 	TRUE, 	FALSE, 	TRUE, 	FALSE,
	FALSE, 	FALSE, 	TRUE,		FALSE, 	TRUE, 	FALSE, 	FALSE, 	FALSE, 	TRUE, 
	FALSE, 	TRUE, 	FALSE,	FALSE, 	FALSE, 	TRUE, 	FALSE, 	FALSE, 	FALSE, 
	FALSE, 	FALSE, 	TRUE, 	FALSE, 	TRUE, 	FALSE, 	FALSE, 	FALSE, FALSE}; 


void construct_candidates(unsigned short a[], int k, int n, int c[], int *ncandidates){
	int in_perm[MAX];

	memset(in_perm, FALSE, sizeof(int [MAX]));
	for (int i=0; i<k; i++) in_perm[ a[i] ] = TRUE;

	*ncandidates = 0;

	if(k==1){
		*ncandidates = 1;
		c[0] = 1;		
	} 
	else{
		for (int i=2; i<=n; i++){		
			if (in_perm[i] == FALSE && (k == 1 || (PRIMOS[a[k-1]+i] == TRUE))){
					if(k== n && PRIMOS[a[1] + i] == FALSE)
						continue;
			c[ *ncandidates] = i;
			(*ncandidates)++;
			}
		}	
	}	
}
void process_solution(unsigned short a[], int k, int input){
	switch(k){
	case 6:
	   sprintf(solution6[i6++], "%i %i %i %i %i %i", a[1], a[2], a[3], a[4], a[5], a[6]);	
	   break;
	case 8:
	   sprintf(solution8[i8++], "%i %i %i %i %i %i %i %i", a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]);
	   break;
	case 10:
	   sprintf(solution10[i10++], "%i %i %i %i %i %i %i %i %i %i", a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9], a[10]);
	   break;	
	case 12:
	   sprintf(solution12[i12++], "%i %i %i %i %i %i %i %i %i %i %i %i", a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9], a[10], a[11], a[12]);
	   break;		
	case 14:
	   sprintf(solution14[i14++], "%i %i %i %i %i %i %i %i %i %i %i %i %i %i", a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9], a[10], a[11], a[12], a[13],a[14]);
	   break;		
	case 16:
	   sprintf(solution16[i16++], "%i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i", a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9], a[10], a[11], a[12], a[13],a[14], a[15],a[16]);
	   break;		
	}
}

bool is_a_solution(unsigned short a[], int k, int n){	
	return  (k == n) && a[1] == 1;
}

void backtrack(unsigned short a[], int k, int input) {
	int c[MAXCANDIDATES]; 	/* candidates for next position */
	int ncandidates; 			/* next position candidate count */
	int i; 						/* counter */

	if (is_a_solution(a,k,input))
		process_solution(a,k,input);
	else {

		k = k+1;

		construct_candidates(a,k,input,c,&ncandidates);

		for (i=0; i<ncandidates; i++) {
			a[k] = c[i];
			backtrack(a,k,input);
		}
	}
}
void solve(int n){
	unsigned short a[MAXCANDIDATES]; /* solution vector */
	for(int i = 0; i < MAXCANDIDATES; i++)
		a[i] = i;
	backtrack(a,0,n);
}

int main(){
	int n, count=0;
	bool cont= true;
	
	// calcular todas las posibilidades!
	for(int i = 2; i <= 16; i++)
		solve(i); 
		
	// obtener e imprimir todos los resultados!
	cin >> n;
	
	while(cont){
		printf("Case %d:\n", (++count));
		switch(n){
			case 1:
				puts("1"); 
				break;
			case 2:
				puts("1 2");
				break;
			case 4:
				puts("1 2 3 4");
				puts("1 4 3 2");
				break;
			case 6:
				for(int i = 0; i < i6; i++)
					puts(solution6[i]);
				break;
			case 8:
				for(int i = 0; i < i8; i++)
					puts(solution8[i]);
				break;
			case 10:
				for(int i = 0; i < i10; i++)
					puts(solution10[i]);
				break;	
			case 12:
				for(int i = 0; i < i12; i++)
					puts(solution12[i]);
				break;		
			case 14:
				for(int i = 0; i < i14; i++)
					puts(solution14[i]);
				break;		
			case 16:
				for(int i = 0; i < i16; i++)
					puts(solution16[i]);
				break;		
		}
		
		if(cin >> n)		
			printf( "\n");
		else 
			cont = false;
	}
	
	return 0;
}
