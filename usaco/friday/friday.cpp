/*
ID: dncampo1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


//primer indice para los an~os, segundo indice para los dias
// days_13[1][0] contiene la cantidad de veces que cae Lunes 13 en el 1900
unsigned days_13[400][7];

unsigned days_by_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


int main(){

	unsigned days;
	unsigned last_day = 0; //Jan, monday 1 1900
	
	ofstream fout ("friday.out");
	ifstream fin ("friday.in");
   unsigned n;
   
	fin >> n;
   
	for(unsigned y = 1900; y < 1900 + n; y++){
		for(unsigned m = 1; m <= 12; m++){

			days = days_by_month[m];
			
			if(2 == m){ //febrero
				if(y % 4 == 0)	{
					if(y % 100 == 0)
						if(y % 400 == 0)
							days = 29;
						else 
							days = 28;
					else
						days = 29;
					}
			}	
			
			days_13[y - 1900][ (13 + last_day) % 7]++;
			last_day = (days + last_day) % 7;
			
		}
	}

	unsigned c[7] = { 0 };
	for(unsigned i = 0; i < n; i++){
		for(unsigned j = 0; j < 7; j++)
			c[j] += days_13[i][j];
	}
	
	fout << c[6] << " " << c[0] << " " << c[1] << " " << c[2] << " " << c[3] << " " << c[4] << " " << c[5] << endl;

	return 0;
}

