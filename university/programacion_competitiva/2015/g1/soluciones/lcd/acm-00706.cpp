/**
 * Title: LCD Display
 * URL: http://icpcres.ecs.baylor.edu/onlinejudge/external/7/706.html
 * Resources of interest:
 * Solver group: David-Leo-Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
    + Tener en cuenta que todos los números son un caso particular \
	 del número 8.
	 + Se usaron punteros a funciones para facilitar la implementación.
**/


#include <iostream>
#include <string>

#define MAX 103
using namespace std;

void init(char[][MAX],int,int,string,int);
void print(char[][MAX],int,int);
void zero(char[][MAX],int index,int s);
void one(char[][MAX],int index,int s);
void two(char[][MAX],int index,int s);
void three(char[][MAX],int index,int s);
void four(char[][MAX],int index,int s);
void five(char[][MAX],int index,int s);
void six(char[][MAX],int index,int s);
void seven(char[][MAX],int index,int s);
void eight(char[][MAX],int index,int s);
void nine(char[][MAX],int index,int s);

void (*func[])(char[][MAX],int,int)={&zero,&one,&two, &three,&four,&five,&six,&seven,&eight,&nine};

int main (int argc, char** argv){
	int s;
	string n;
	
	while(1){
		cin >> s >> n;
		if((0==s) && ("0"==n))	return 0;
	
		const int rows=2*s + 3;
		const int cols=(s + 2)*n.size() + n.size() - 1;
		char nums[rows][MAX];		
		init(nums,rows,cols,n,s+2);
		print(nums,rows,cols);	
	}	
	return 0;
}

void init(char nums[][MAX],int rows, int cols, string num, int width ){
	for(int i=0; i< rows; i++)
		for(int j=0; j< cols; j++)
			nums[i][j] = ' ';	

	for(size_t i=0; i<num.size(); i++){
		int n = (int)(num.at(i)-'0');
		(*func[n])(nums,(width+1)*i,width-2); //Llamada a la funcion que dibuja el character 'i'
	}
}

void print(char nums[][MAX], int rows, int cols){
	for(int i=0; i< rows; i++) {
		for(int j=0; j< cols; j++)
			cout << nums[i][j];
		cout << endl;
	}
	cout << endl;		
}

void zero(char n[][MAX],int index,int s){
	for(int j=1,i= index; i < s+index; j++,i++){
		n[0][1+i] = '-';
		n[2*s + 3 - 1][1+i] = '-';		
		n[j][index] = '|';
		n[j][index + s + 2 - 1] = '|';

		n[j + s + 1][index] = '|';
		n[j + s + 1][index+ s + 2 - 1] = '|';		
	}	
}

void one(char n[][MAX],int index,int s){
	for(int j=1,i= index; i < s+index; j++,i++){
		n[j][index + s + 2 - 1] = '|';
		n[j + s + 1][index+ s + 2 - 1] = '|';		
	}
}

void two(char n[][MAX],int index,int s){
	for(int j=1,i= index; i < s+index; j++,i++){
		n[0][1+i] = '-';
		n[2*s + 3 - 1][1+i] = '-';		
		n[j][index + s + 2 - 1] = '|';
		n[s+1][1+i] = '-';
		n[j + s + 1][index] = '|';
	}	
}
void three(char n[][MAX], int index,int s){
	for(int j=1,i= index; i < s+index; j++,i++){
		n[0][1+i] = '-';
		n[2*s + 3 - 1][1+i] = '-';		
		n[j][index + s + 2 - 1] = '|';
		n[s+1][1+i] = '-';
		n[j + s + 1][index+ s + 2 - 1] = '|';		
	}	
}

void four(char n[][MAX],int index,int s){
	for(int j=1,i= index; i < s+index; j++,i++){
		n[j][index] = '|';
		n[j][index + s + 2 - 1] = '|';
		n[s+1][1+i] = '-';
		n[j + s + 1][index+ s + 2 - 1] = '|';		
	}	
}

void five(char n[][MAX],int index,int s){
	for(int j=1,i= index; i < s+index; j++,i++){
		n[0][1+i] = '-';
		n[2*s + 3 - 1][1+i] = '-';		
		n[j][index] = '|';
		n[s+1][1+i] = '-';
		n[j + s + 1][index+ s + 2 - 1] = '|';		
	}	
}

void six(char n[][MAX],int index,int s){
	for(int j=1,i= index; i < s+index; j++,i++){
		n[0][1+i] = '-';
		n[2*s + 3 - 1][1+i] = '-';		
		n[j][index] = '|';
		n[s+1][1+i] = '-';
		n[j + s + 1][index] = '|';
		n[j + s + 1][index+ s + 2 - 1] = '|';		
	}	
}

void seven(char n[][MAX],int index,int s){
	for(int j=1,i= index; i < s+index; j++,i++){
		n[0][1+i] = '-';
		n[j][index + s + 2 - 1] = '|';
		n[j + s + 1][index+ s + 2 - 1] = '|';		
	}	
}

void eight(char n[][MAX],int index,int s){
	for(int j=1,i= index; i < s+index; j++,i++){
		n[0][1+i] = '-';
		n[2*s + 3 - 1][1+i] = '-';		
		n[j][index] = '|';
		n[j][index + s + 2 - 1] = '|';
		n[s+1][1+i] = '-';
		n[j + s + 1][index] = '|';
		n[j + s + 1][index+ s + 2 - 1] = '|';		
	}	
}

void nine(char n[][MAX],int index,int s){
	for(int j=1,i= index; i < s+index; j++,i++){
		n[0][1+i] = '-';
		n[2*s + 3 - 1][1+i] = '-';		
		n[j][index] = '|';
		n[j][index + s + 2 - 1] = '|';
		n[s+1][1+i] = '-';
		n[j + s + 1][index+ s + 2 - 1] = '|';		
	}	
}

//EOF

