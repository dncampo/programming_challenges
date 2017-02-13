/**
 * Title: Evaluate the polynomial
 * URL: http://www.spoj.pl/problems/POLEVAL/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
	+ Se almacenan en arreglos los coeficientes y los puntos a evaluar.
	+ Una forma sencilla de no desperdiciar demasiado tiempo computando las potencias de un punto dado,
	es empezar a evaluar el número dado desde la potencia más baja, y evaluar el término correspondiente
	a dicha potencia y acumularlo en el resultado parcial. Luego ir multiplicando esta potencia por el
	número a evaluar y obtenemos la siguiente pontencia sucesiva, calculando el nuevo término. Así hasta
	llegar a la potencia más alta y finalizar la evaluación total del polinomio.
	+ Ejemplo: Para calcular: x^2 - 2x - 1, en el punto x = 2 se realiza lo siguiente:
	caso inicial --> pow = 1, sum = 0, entonces sum = 0 - 1 = -1 (-1 es el termino independiente)
	primera iter --> pow = pow_anterior * 2 = 2, entonces sum = sum_anterior - 2*pow = -5
	segunda iter --> pow = pow_anterior * 2 = 4, entonces sum = sum_anterior + 4 = -1

**/

#include <iostream>

using namespace std;

int main(){
	unsigned degree;
	int cases = 0;
	while(cin >> degree){
		cases++;
		int coefficients[degree+1];
		for(int i = degree; i >= 0; i--){
			cin >> coefficients[i];
		}
		
		int cant_points;
		cin >> cant_points;		
		int points_to_eval[cant_points];
		
		for(int j = 0; j < cant_points; j++)
			cin >> points_to_eval[j];
		
		cout << "Case " << cases << ":" << endl;
		for (int k = 0; k < cant_points; k++){
			long long sum;
			int point = points_to_eval[k];
			long long pow = 1;
			sum = coefficients[0];
			for(int l = 1; l <= degree; l++){
				pow *= point;
				sum += pow * coefficients[l];
			}
			cout << sum << endl;
		}
	}
	return 0;
}
