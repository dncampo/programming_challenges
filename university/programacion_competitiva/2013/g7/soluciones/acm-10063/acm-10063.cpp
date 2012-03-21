/**
 * Title: Knuth’s Permutation
 * URL: file:///home/yeyo/Desktop/permutacion/acm-10063.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   Para cada entrada se calculan e imprimen las permutaciones como define
   el enunciado del problema.
   Hay que tener en cuenta en este caso que la salida es estricta, ya 
   que si no se imprime exactamente como indica el enunciado se obtiene un WA.
   
**/
#include <iostream>
#include <string>
using namespace std;

string data;
string in;
int iin;

void backtracking(){
	if(in.size() == data.size()){
		cout << data << endl;
	} else{
      char c = in[iin];

		for(int i = 0; i <= data.size(); i++){
			data.insert(data.begin()+i, c);
			iin++;
			backtracking();
   		data.erase(data.begin()+i);
			iin--;
		}
	}
}

int main(){
   int begin  = 0;
   
	while(cin >> in){
	   if(begin){
  	      cout << endl;
  	   } else  
  	      begin= 1;
  	      
	   iin  = 0;
	   data.clear();

	   backtracking();
	}
	
	return 0;
}

