/**
 * Title: KTV
 * URL: http://uva.onlinejudge.org/external/112/11218.html
 * Resources of interest:
 * Solver group: Yeyo-David
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   Se utiliza la tecnica de backtracking para resolver el problema.
   Para cada entrada se itera se calcula e imprime la solución.
   El problema es trivial, se agrega si se puede una tripleta de cantantes hasta
   que se completa las tres tripletas. Luego se verifica si el score que obtienen esas
   tres tripletas es maxima, sino se guarda esa tripleta como la mejor.
   Para facilitar la implementación se utiliza un arreglo de booleanos(used) que
   nos indica si un cantante ya canto ya que una persona puede cantar solo una vez.
**/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct triple{
   int a, b, c, s;
};

bool used[10];
vector<int> data;
vector<triple> in;
int score = -1;


bool is_solution(){
	return data.size() == 3;
}

void process_solution(){
   int tmp = 0;
   
   for(unsigned i = 0; i < data.size(); i++){
      tmp += in[data[i]].s;
   }
   
   if(tmp > score){
      score = tmp;
   }
}

void get_candidates(int index, vector<int> &candidates){
	for(unsigned i = index; i < in.size(); i++){
	   if(!used[in[i].a] && ! used[in[i].b] && !used[in[i].c]){
	      candidates.push_back(i);
	   }
	}
}

void add(int index){
   data.push_back(index);
   used[in[index].a] = true;
   used[in[index].b] = true;
   used[in[index].c] = true;      
}

void del(int index){
   data.pop_back();
   used[in[index].a] = false;
   used[in[index].b] = false;
   used[in[index].c] = false;      
}

void backtracking(int index){
	if(is_solution()){
		process_solution();
	}else {
		vector<int> candidates;

		get_candidates(index, candidates);
		
		for(unsigned i = 0; i < candidates.size(); i++){
		   add(candidates[i]);
			backtracking(candidates[i]);
			del(candidates[i]);
		}
	}
}


int main(){
   int n, count = 1;
   
	cin >> n;
	
	while (n != 0){
	   for(int i = 0; i < n; i++){
         triple t;
         cin >> t.a >> t.b >> t.c >> t.s;
         in.push_back(t);	      
	   }
     
	   backtracking(0);
	   
	   cout << "Case " << count++ << ": " << score << endl;
	   cin >> n;
	   
	   in.clear();
	   data.clear();
      score = -1;
      memset(used, 0, sizeof(used));
	}  
	return 0;
}


