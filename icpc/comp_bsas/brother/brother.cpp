#include <iostream>
#include <vector>

using namespace std;

unsigned surround (vector<vector<unsigned> > *original, unsigned i, unsigned j, \
	unsigned R, unsigned C, unsigned heirs){
	
	int ret = (*original)[i][j], me = (*original)[i][j];
	int enemy = me - 1;
	if (enemy < 0) enemy = heirs - 1;
	
	if(i > 0){ //up
		if ((unsigned)enemy == (*original)[i - 1][j] ){
			return enemy;
		}
	}

	if(i < R - 1){ //down
		if ((unsigned)enemy == (*original)[i + 1][j] ){
			return enemy;
		}
	}	

	if(j > 0){ //left
		if ((unsigned)enemy == (*original)[i][j - 1] ){
			return enemy;
		}
	}
	
	if(j < C - 1){ //right
		if ((unsigned)enemy == (*original)[i][j + 1] ){
			return enemy;
		}
	}		

	return ret;
}

void print(vector<vector<unsigned> > *b, unsigned R, unsigned C){
		for (unsigned i = 0; i < R; i++) {
			for (unsigned j = 0; j < C; j++) {
				if (j < C - 1)
				  cout << (*b)[i][j] << " ";
				else
				  cout << (*b)[i][j];
			}
			cout << endl;
		}	
}

int main(){
	unsigned N, R, C, K;
	
	while (cin >> N >> R >> C >> K){
		if (0 == N + R + C + K) return 0;
		
		vector<vector<unsigned> > original(R);
		vector<vector<unsigned> > battle(R);

		for (unsigned i = 0; i < R; i++) {
			original[i] = vector<unsigned>(C);
			battle[i] = vector<unsigned>(C);
		}


		
		for (unsigned i = 0; i < R; i++) 
			for (unsigned j = 0; j < C; j++) 
				cin >> battle[i][j];
		
		
		vector<vector<unsigned> > *o, *b;
		o = &original;
		b = &battle;

		for (unsigned k = 0; k < K; k++){

			vector<vector<unsigned> > *temp;
			temp = o;
			o = b;
			b = temp;

			for (unsigned i = 0; i < R; i++) {
				for (unsigned j = 0; j < C; j++) {
					(*b)[i][j] = surround(o, i, j, R , C, N);				
				}
			}
		}
		
		print(b, R, C);
	}

	return 0;
}

