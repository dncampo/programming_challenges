/**
 * Title: Big Chocolate
 * URL: http://online-judge.uva.es/p/v109/10970.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + A través de la fórmula M*N-1, se llega al resultado.

**/

#include <iostream>

int main () {
	unsigned M, N;

	while (std::cin >> M >> N) std::cout << M * N - 1 << std::endl;

	return 0;
}
