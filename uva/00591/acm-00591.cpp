/**
 * Title: Box of Bricks
 * URL: http://online-judge.uva.es/p/v5/591.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se crea una lista que contiene cada una de las alturas de las pilas de ladrillos. Se van sumando
	estas alturas para sacar luego una altura promedio. Luego se recorre la lista de alturas y para cada
	altura que esté por debajo del promedio se va acumulando dicha diferencia.
**/

#include <iostream>
#include <list>
#include <string>

using namespace std;

int main (int argc, char** argv){
	unsigned short set=0;
	while(1){
		set++;
		unsigned short num_stacks;
		cin >> num_stacks;
		
		if ((0 == num_stacks)) return 0;	
		
		list<unsigned short> bricks;	

		unsigned short sum_height = 0; //sum of bricks's height
		for(unsigned short i = 0; i < num_stacks; i++){
			unsigned short a_Brick;
			cin >> a_Brick;
			sum_height += a_Brick;
			bricks.push_back(a_Brick);
		}
		
		const unsigned short correct_height = sum_height / bricks.size();
		unsigned short movements=0;
		list<unsigned short>::iterator begin = bricks.begin();
		list<unsigned short>::iterator end = bricks.end();
		
		while(begin != end){
			unsigned short a = *begin; 
			if(a < correct_height)
				movements += correct_height - a; //this brick has not enought height
			begin++;
		}	
		cout << "Set #" << set << endl;
		cout << "The minimum number of moves is " << movements << "." << endl << endl;
	}		
	return 0;
}

//EOF
