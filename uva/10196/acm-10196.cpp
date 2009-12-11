/**
 * Title: Check The Check
 * URL: http://icpcres.ecs.baylor.edu/onlinejudge/external/101/10196.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Para todas los casilleros se verifica si hay una pieza y si está haciendo jaque al rey oponente.
	En caso de que esté vacío se sigue con el siguiente. Hay una función para cada tipo de pieza que 
	verifica si hace jaque; excepto para la reina, ya que como sus movimientos son la combinación de 
	los movimientos del alfil y torre se aprovechan los de estos.
	+ Otra solución válida sería la del chequeo inverso. Es decir, verificar al rey contra las piezas
	oponentes que puedan atacar.
**/

#include <iostream>

#define WHITE_IN_CHECK "white king is in check."
#define BLACK_IN_CHECK "black king is in check."
#define NO_CHECK "no king is in check."
#define HEIGHT WIDTH
#define WIDTH 8

using namespace std;
typedef unsigned short ushort;

void print_board(void);
string solve(void);
bool pawn(ushort,ushort,char);
bool rook(ushort,ushort,char);
bool bishop(ushort,ushort,char);
bool knight(ushort, ushort, char);

char chboard[HEIGHT][WIDTH];

int main (int argc, char** argv){

char tmp,dots=0;
ushort games=0;

  while(1){
	 dots = 0;
	 for(ushort a = 0; a < HEIGHT; a++){
		for(ushort b = 0; b < WIDTH; b++) {
		  cin >> tmp;
		  chboard[a][b] = tmp;
		  dots += '.' == tmp ? 1 : 0;
		}
	 }
	 if(dots < HEIGHT*WIDTH) cout << "Game #" << ++games << ": " << solve() << endl;
	 else return 0;
  }
  return 0;
}

string solve(void){
  for(ushort a = 0; a < HEIGHT; a++){
	 for(ushort b = 0; b < WIDTH; b++){
		switch(chboard[a][b]){
		  case 'P': if(true == pawn(a,b,'P')) { return BLACK_IN_CHECK; } break;
		  case 'p': if(true == pawn(a,b,'p')) { return WHITE_IN_CHECK; } break;
		  case 'R': if(true == rook(a,b,'R')) { return BLACK_IN_CHECK; } break;
		  case 'r': if(true == rook(a,b,'r')) { return WHITE_IN_CHECK; } break;
		  case 'B': if(true == bishop(a,b,'B')) {return BLACK_IN_CHECK; } break;
		  case 'b': if(true == bishop(a,b,'b')) {return WHITE_IN_CHECK; } break;
		  case 'N': if(true == knight(a,b,'N')) { return BLACK_IN_CHECK; } break;
		  case 'n': if(true == knight(a,b,'n')) { return WHITE_IN_CHECK; } break;
		  
		  //queen movements it's like a rook+bishop movement, so I'll use those functions...
		  case 'Q': if(true == rook(a,b,'Q')) {return BLACK_IN_CHECK; };
						if(true == bishop(a,b,'Q')) {return BLACK_IN_CHECK; } break;
		  case 'q': if(true == rook(a,b,'q')) {return WHITE_IN_CHECK; };
						if(true == bishop(a,b,'q')) {return WHITE_IN_CHECK; } break;
		};
	 }
  }
  return NO_CHECK;
}

bool pawn(ushort y, ushort x, char pawn) {
  bool check = false;
  char king = 90 < pawn ? 'K' : 'k'; //black or white attack?

  if('p' == pawn) {//black attack
	 if(y < HEIGHT-1){
		if(x > 0) check = check || (king == chboard[y+1][x-1] ? true : false);
		if((!check) && x < WIDTH-1) check = check || (king == chboard[y+1][x+1] ? true : false);
	 }
  }
  else { //white attack
	 if(y > 0){
		if(x > 0) check = check || (king == chboard[y-1][x-1] ? true : false);
		if((!check) && x < WIDTH-1) check = check || (king == chboard[y-1][x+1] ? true : false);
	 }
  }
  return check;
}

bool knight(ushort y, ushort x, char knight){
  char king = 90 < knight ? 'K' : 'k'; //black or white attack?

  if((x-2 >= 0) && (y-1 >= 0))
	 if(king == chboard[y-1][x-2]) return true;

  if((x-1 >= 0) && (y-2 >= 0))
	 if(king == chboard[y-2][x-1]) return true;

  if((x+1 >= 0) && (y-2 >= 0))
	 if(king == chboard[y-2][x+1]) return true;

  if((x+2 >= 0) && (y-1 >= 0))
	 if(king == chboard[y-1][x+2]) return true;

  if((x+2 >= 0) && (y+1 >= 0))
	 if(king == chboard[y+1][x+2]) return true;

  if((x+1 >= 0) && (y+2 >= 0))
	 if(king == chboard[y+2][x+1]) return true;

  if((x-1 >= 0) && (y+2 >= 0))
	 if(king == chboard[y+2][x-1]) return true;

  if((x-2 >= 0) && (y+1 >= 0))
	 if(king == chboard[y+1][x-2]) return true;

  return false;
}

bool bishop(ushort y, ushort x, char bishop){
  char king = 90 < bishop ? 'K' : 'k'; //black or white attack?
  ushort delta=0;

  while((WIDTH  > ++delta + x) && (0  <= y - delta)){ //check out to the right+up
	 if(king == chboard[y - delta][x + delta]) return true;
	 if('.' != chboard[y - delta][x + delta]) break; //another piece it's blocking the check
  }

  delta=0;
  while((0  <= x - ++delta) && (0  <= y - delta)){ //to left+up
	 if(king == chboard[y - delta][x - delta]) return true;
	 if('.' != chboard[y - delta][x - delta]) break; //another piece it's blocking the check
  }

  delta=0;
  while((WIDTH  > ++delta + x) && (HEIGHT  > delta + y)){ //to right+down
	 if(king == chboard[y + delta][x + delta]) return true;
	 if('.' != chboard[y + delta][x + delta]) break; //another piece it's blocking the check
  }

  delta=0;
  while((0  <= x - ++delta) && (HEIGHT  > delta + y)){ //to left+down
	 if(king == chboard[y + delta][x - delta]) return true;
	 if('.' != chboard[y + delta][x - delta]) break; //another piece it's blocking the check
  }
  return false;
}

bool rook(ushort y, ushort x, char rook){
  char king = 90 < rook ? 'K' : 'k'; //black or white attack?
  ushort delta=0;

  while(WIDTH  > ++delta + x){ //check out to the right
	 if(king == chboard[y][x + delta]) return true;
	 if('.' != chboard[y][x + delta]) break; //another piece it's blocking the check
  }

  delta=0;
  while(0  <= x - ++delta){ //to left
	 if(king == chboard[y][x - delta]) return true;
	 if('.' != chboard[y][x - delta]) break; //another piece it's blocking the check
  }

  delta=0;
  while(HEIGHT  > ++delta + y){ //to down
	 if(king == chboard[y + delta][x]) return true;
	 if('.' != chboard[y + delta][x]) break; //another piece it's blocking the check
  }

  delta=0;
  while(0  <= y - ++delta){ //to up
	 if(king == chboard[y - delta][x]) return true;
	 if('.' != chboard[y - delta][x]) break; //another piece it's blocking the check
  }
  return false;
}

void print_board(void){
  for(ushort a = 0; a < HEIGHT; a++){
		for(ushort b = 0; b < WIDTH; b++)
		  cout << chboard[a][b];		
		cout << endl;
	 }
  cout << endl;
}

//EOF
