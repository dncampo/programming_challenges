/**
 * Title: Problem E: Graphical Editor
 * URL: http://icpcres.ecs.baylor.edu/onlinejudge/external/102/10267.html
 * Resources of interest: http://en.wikipedia.org/wiki/Flood_fill
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se crea una función para cada comando. El más complejo es el F (comando fill). Para resolverlo
	se utiliza un algoritmo (implementación recursiva en este caso) llamado Flood Fill que se encarga de
	colorear una región encerrada entre pixels.
**/

#include <iostream>
#include <vector>

using namespace std;

void new_table(unsigned short,unsigned short);
void clear(void);
void colorize(unsigned short,unsigned short,char);
void save(string);
void v_line(unsigned short,unsigned short,unsigned short,char);
void h_line(unsigned short,unsigned short,unsigned short,char);
void draw(unsigned short,unsigned short,unsigned short,unsigned short,char);
void fill(unsigned short,unsigned short,char);
void fill_rec(unsigned short, unsigned short, char, char);
void swap(unsigned short &, unsigned short &);

vector <vector<char> > table;
unsigned short M,N;

int main(void){
	char command;
	cin >> command;
	unsigned short x1,x2,y1,y2;
	char color;
	string name;

	while('X' != command){
		switch(command){	
			case 'I':
				cin >> x1 >> y1;
				new_table(x1,y1);
				break;
		
			case 'C': clear(); break;

			case 'L':
				cin >> x1 >> y1 >> color;
				colorize(x1,y1,color);
				break;

			case 'V':
				cin >> x1 >> y1 >> y2 >> color;
				v_line(x1,y1,y2,color);
				break;

			case 'H':
				cin >> x1 >> x2 >> y1 >> color;
				h_line(x1,x2,y1,color);
				break;

			case 'K':
				cin >> x1 >> y1 >> x2 >> y2 >> color;
				draw(x1,y1,x2,y2,color);
				break;

			case 'F':
				cin >> x1 >> y1 >> color;
				fill(x1,y1,color);
				break;

			case 'S':
				cin >> name;
				save(name);
				break;

			case 'X': return 0;

			default: break;
		}
	cin >> command;
	}
	return 0;
}

void new_table(unsigned short x, unsigned short y){
	N = x;
	M = y;
	clear();
}

void clear(){
	table = vector<vector<char> >(M);
	for(unsigned short c=0; c<M ; c++)
		table[c] = vector<char>(N,'O');
}

void colorize(unsigned short x, unsigned short y, char color){
	table[y-1][x-1] = color; 
}

void save(string name){
	cout << name << endl;
	for(unsigned short m=0 ; m < M; m++) {
		for(unsigned short n=0 ; n < N; n++)
			cout << table[m][n];
	cout << endl;
	}
}

void v_line(unsigned short x, unsigned short y1, unsigned short y2, char color){
	if(y1 > y2) swap(y1,y2);
	for (unsigned short n = y1; n <= y2; n++)
		table[n-1][x-1] = color;
}

void h_line(unsigned short x1, unsigned short x2, unsigned short y, char color){
	if(x1 > x2) swap(x1,x2);
	for (unsigned short m = x1; m <= x2; m++)
		table[y-1][m-1] = color;
}

void draw(unsigned short x1, unsigned short y1, unsigned short x2, unsigned short y2, char color){
	if(x1 > x2) swap(x1,x2);
	if(y1 > y2) swap(y1,y2);
	for (unsigned short m = x1; m <= x2; m++)
		for (unsigned short n = y1; n <= y2; n++)
			table[n-1][m-1] = color;
}

void fill(unsigned short x, unsigned short y, char color){
	fill_rec(x-1, y-1, color,table[y-1][x-1]);
}

void fill_rec(unsigned short x, unsigned short y, char new_color, char old_color){
	if(table[y][x] != old_color) return;
	if(table[y][x] == new_color) return;

	table[y][x] = new_color;

	if((x-1) >= 0) fill_rec(x-1,y,new_color,old_color);
	if((x+1) < N) fill_rec(x+1,y,new_color,old_color);
	if((y-1) >= 0) fill_rec(x,y-1,new_color,old_color);
	if((y+1) < M) fill_rec(x,y+1,new_color,old_color);
	return;
}

void swap(unsigned short &a, unsigned short &b){
	unsigned short tmp = b;
	b = a;
	a = tmp;
}

//EOF
