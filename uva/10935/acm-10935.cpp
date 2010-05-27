/**
 * Title: Throwing cards away I 
 * URL: http://online-judge.uva.es/p/v109/10935.html
 * Resources of interest:
 * Solver group: Yeyo, David, Leo
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
    + Se simula con una cola el proceso descripto en el enunciado.
**/

#include <cstdio>
#include <queue>

void calc (unsigned n) {
	std::queue<unsigned> q;

	for (unsigned i = 1; i <= n; i++) {
		q.push(i);
	}
	
	while (q.size() > 2) {
	   printf("%u, ", q.front());
		q.pop();		
		q.push(q.front());
		q.pop();
	}
	if (2 == q.size()) { //to avoid trailing spaces
   	printf("%u", q.front());
		q.pop();
		q.push(q.front());
		q.pop();
	}
	printf("\nRemaining card: %u\n", q.front());
}

int main () {

	unsigned n;
   while ( (~scanf("%u",&n)) && (n != 0) ) {
      if (1 == n)
   	   printf("Discarded cards:");
      else
   	   printf("Discarded cards: ");
		calc (n);
	}
	return 0;
}

