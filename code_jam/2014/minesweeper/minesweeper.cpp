#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main () {
	unsigned n_cases;
	double R, C, M;
	
	cin >> n_cases;
	
	for (unsigned t=0; t<n_cases; t++) {

		cin >> R >> C >> M;
		
		cout << "Case #" << t+1 << ":" << endl;

		if (M==0) {
			vector<char> cols(C, '.');
			vector<vector<char> > sq(R, cols);
			sq[0][0] = 'c';
			//print out
			for (unsigned i=0; i<R; i++){
				for (unsigned j=0; j<C; j++){
					cout << sq[i][j];
				}	
				cout << endl;
			}
			continue;
		}

		
		if (C == 1 || R == 1) {
			if (M + 1 <= C*R) {
				//ok
				vector<char> sq(C*R, '*');
				sq[0] = 'c';
				for(unsigned i = 1; i < C*R-M; i++ ) {
					sq[i] = '.';
				}
				for(unsigned i = 0; i < C*R; i++ ) {
					cout << sq[i];
					if (C==1) {
						cout << endl;
					}
				}
				if (R==1) cout << endl;
			}
			else {
				//imp
				cout << "Impossible" << endl;
			}
			
		}
		else {
			vector<char> cols(C, '*');
			vector<vector<char> > sq(R, cols);
			sq[0][0] = 'c';
			if (C*R-M == 1) {
				sq[0][0] = 'c';
				//print out
				for (unsigned i=0; i<R; i++){
					for (unsigned j=0; j<C; j++){
						cout << sq[i][j];
					}	
					cout << endl;
				}
			}
			else if (M + 4 <= C*R) { //ok

				unsigned last_row = 0;
				unsigned last_col = 0;
				
				int dots = (C*R) - M - 1;

				if (dots > 0) {
					dots--;
					sq[0][1] = '.';
				}
				if (dots > 0) {
					dots--;
					sq[1][0] = '.';
				}			
				if (dots > 0) {
					dots--;
					sq[1][1] = '.';
				}
			last_row=0;
			last_col=2;

						
 				while (dots > 0) {					
					if (last_col == C) {
						last_col = 0;
						last_row += 1;
					}
		
					while (sq[last_row][last_col] != '*') {//if it's occupied

						last_col += 1;
						if (last_col == C) {
							last_col = 0;
							last_row += 1;
						}
					}
					sq[last_row][last_col] = '.';
					
					dots--;
				}

				//print out
				for (unsigned i=0; i<R; i++){
					for (unsigned j=0; j<C; j++){
						cout << sq[i][j];
					}	
					cout << endl;
				}

			}
			else{
				cout << "Impossible" << endl;
				//imp
			}
			
		}

	}
	return 0;
}
