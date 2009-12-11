/** 
 * Title: Happy Numbers
 * URL: http://uva.onlinejudge.org/external/9/944.html
 * Resources of interest:
 * Solver group: Leo
 * Contact e-mail: bortoli.leonardo at gmail dot com
 * Description of solution:
   	Se crea un array con los numeros del 1 al 99999. Se recorre el array seteando cada posicion
   	con las iteraciones para los happy numbers y -1 para los unhappy numbers.
   	En cada iteracion de las respectivas secuencias (s0, s1, s2, ...), se marca el
   	numero en cuestion en el array, ya sea happy o unhappy, para evitar procesarlo mas de una vez.
**/

#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int numbers[100000];

int sq_sum(int n){
	int s = 0, p;
	
	while(n > 0){
		p = n % 10;
		s += p * p;
		n /= 10;
	}
	
	return s;
}

bool contains(vector<int> v, int n){
	for(unsigned i=0; i<v.size(); i++)
		if(n == v[i])
			return true;
	
	return false;
}

int main(){
	memset(numbers, 0, sizeof(numbers));
	numbers[1] = 1;
	
	for(int i=2; i<100000; i++){
		if(numbers[i] == 0){ // aun no se proceso el numero
			vector<int> seq;

			int s = sq_sum(i);
		
			while(!contains(seq, s) && s != 1){
				seq.push_back(s);
				s = sq_sum(s);
			}
			seq.push_back(s); // insertar la ultima iteracion
			
			int seq_size = seq.size();
			
			if(s == 1){ // happy
				numbers[i] = seq_size + 1;

				for(int j=0; j<seq_size; j++){
					numbers[ seq[j] ] = seq_size - j;
				}
			}
			else{ // unhappy
				numbers[i] = -1;

				for(int j=0; j<seq_size; j++){
					numbers[ seq[j] ] = -1;
				}				
			}
		}
	}

	int l, h;
	int more = scanf("%d%d", &l, &h);
	
	while(more != EOF){
		for(int i=l; i<=h; i++){
			if(numbers[i] > 0)
				printf("%d %d\n", i, numbers[i]);
		}
		if((more = scanf("%d%d", &l, &h)) != EOF)
			cout << endl;
	}

	return 0;
}
