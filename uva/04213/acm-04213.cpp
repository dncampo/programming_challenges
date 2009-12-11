/**
 * Title: DNA subsequences
 * URL: http://acm.uva.es/archive/nuevoportal/data/problem.php?p=4213
 * Resources of interest:
 * Solver group: Yeyo-Leo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   Se utiliza programacion dinamica para resolver el problema.
   La solucion que se implementa se base en lcs pero con algunas 
   modificaciones para permitir que las subsecuencias comunes sean
   segmentos de por lo menos k elementos.
**/

#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

int solve(char *a, char *b, int k){
	vector<vector<int> > m, c;
	unsigned asize = strlen(a), bsize= strlen(b);

	m.resize(asize+1);
	c.resize(asize+1);
	
	for(unsigned i = 0; i < m.size(); i++){
		m[i].assign(bsize+1, 0);
		c[i].assign(bsize+1, 0);
	}

	for(unsigned i = 1; i <= asize; i++){
		for(unsigned j = 1; j <= bsize; j++){
			c[i][j] = (a[i-1] == b[j-1]) ? (c[i-1][j-1] + 1) : 0;

			m[i][j] = max(m[i][j-1], m[i-1][j]);

			for(int dk = k; dk <= c[i][j]; dk++){
				m[i][j] = max(m[i][j], m[i-dk][j-dk]+dk);
			} 			
		}
	}

	return m[asize][bsize];
}

int main(){
	int k;
	char a[1001], b[1001];
	
	scanf("%d", &k);
	
	while(k != 0){
		scanf("%s%s", a, b);
		printf("%d\n", solve(a, b, k));
		scanf("%d", &k);
	}

	return 0;
}
