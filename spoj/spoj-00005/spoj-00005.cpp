/**
 * Title: The Next Palindrome
 * URL: http://www.spoj.pl/problems/PALIN/
 * Resources of interest:
 * Solver group: David-Yeyo
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se recibe el número (de hasta 1.000.000 de dígitos) y se lo almacena en un string para manipularlo.
   + Primero se verifica si tiene una cantidad par o impar de cifras, ya que son los dos casos a tratar.
	Si la cantidad de dígitos es par, se divide el número en dos partes iguales y se verifica si la primera
	parte (recorrida en reversa) es estrictamente mayor que la segunda parte. Si es así se imprime la primera
	parte y se le concatena su espejado. Sino se trata de incrementar en 1 la primera parte (cuidando los 
	acarreos) y se espeja.
	+ Para el caso en que el número tenga cantidad impar de dígitos se hace algo parecido. Se divide el número
	en tres partes disjuntas: primera parte, el medio (un sólo dígito) y segunda parte. Primera y segunda parte 
	tienen la misma cantidad de cifras. Si el reverso de primera parte es estrictamente mayor que la segunda 
	parte se	imprime el número espejado en la primera parte. Es decir: primera parte + medio + reverso de primera
	parte. Sino, se trata de incrementar el dígito del medio (cuidando el acarreo) y se imprime el número espejado
	en la primera parte (con el medio incrementado).
	+ Cabe aclarar que se verifica si todos los dígitos son 9's, para considerar fácilmente este caso y no 
	complicarse con los acarreos.
	+ Hay que tener especial cuidado con números como: 99, 999, 898 (debido a los acarreos).
	+ Con los número de una cifra se imprime el siguiente, salvo con el 9 que se imprime 11.
	+ Debido a que se trata a la entrada como un gran string, se pierde eficiencia pero se gana en 
	sencillez. Una forma más eficiente hubiera sido almacenar el número en un arreglo estático de char.
**/


#include <iostream>
#include <string>

using namespace std;

void next_pal(void);

string num; //the mega-huge-number :)

int main(void){
	unsigned cases;
	cin >> cases;
 	for(unsigned i = 0; i < cases; i++){
		cin >> num;
		next_pal();
	}	
	return 0;
}

void next_pal(void){
	if(1 == num.size()) {
		if('9' == num.at(0)) cout << "11" << endl;
		else cout << (num.at(0) - '0' + 1) << endl;
		return;
	}
	bool even_size = (0 == num.size() % 2);
	const size_t half_size = num.size() / 2;
	int rev_first_part = half_size - 1;
	int second_part = half_size;	
	if(!even_size) //change a little, if size is even or odd.
		second_part++;	
	int middle = half_size;
	
	bool all_9 = true;
	bool rev_first_part_bigger = true;
	
	//see if reverse(first_part) it's bigger than second_part
	//and keep tracking if all digits are 9's
	for(; rev_first_part >= 0; rev_first_part-- , second_part++) {
		if( ('9' != num.at(rev_first_part)) || ('9' != num.at(second_part)) ) all_9 = false;
		char fp = num.at(rev_first_part);
		char sp = num.at(second_part);
		if((fp - '0') < (sp - '0')) 
			rev_first_part_bigger = false;					
		else if ((fp - '0') > (sp - '0')) break;	
	}
	//check the characters of the edges.
	if(num.at(0) == num.at(num.size()-1)) rev_first_part_bigger = false;

	//all 9's ?
	//e.g.: 99, 999, etc.
	if(all_9 && (even_size || ('9'==num.at(middle)) )){
		//if num == 9999 ==> next_pal == 10001
		//if num ==  999 ==> next_pal ==  1001
		cout << "1";
		for(size_t a=0; a < num.size() - 1; a++)
			cout << "0";
		cout << "1" << endl;
		return;
	}

	//e.g.: 3880, 38880, 1220, 12920, etc.
	else if(rev_first_part_bigger) {
		//next palin => first_part + reverse(first_part) or
		//next palin => first_part + middle + reverse(first_part)
		for(size_t a = 0; a < half_size; a++)
			cout << num.at(a);
		if(!even_size) cout << num.at(middle); //;)
		for(int b = half_size - 1; b >=0; b--)
			cout << num.at(b);
	cout << endl;
	return;
	}
	
	//e.g.: 3890, 38890, 1255, 12955, etc.
	else { 
		//first part (in reverse) it isn't bigger than second part. So I have to add one to middle
		//or first part, depends if the size is odd or even.
		bool flag = true;
		int a = half_size-1;
		if(!even_size){			
			if('9' != num.at(middle)) num[middle] += 1, flag = false;
			else num[middle] = '0';
			a = middle - 1;
		}
		while('9' == num.at(a) && flag)
			num[a--] = '0';
		if(flag) num[a] += 1;	
	
		// print the palindrome number for this last case
		for(size_t a = 0; a < half_size; a++)
			cout << num.at(a);
		if(!even_size) cout << num.at(middle);
		for(int b = half_size - 1; b >=0; b--)
			cout << num.at(b);
		cout << endl;
		return;
	}
}

//EOF
