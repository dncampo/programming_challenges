/**
 * Title: Stacking Boxes
 * URL:http://rabbit.eng.miami.edu/~acm/uva_problems/v1/103.html 
 * Resources of interest:
 * Solver group: Yeyo-David-Leo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   Se utiliza programacion dinamica para resolver el problema.
   Los pasos que se realizan son:
   - Se lee un caso de prueba
   - Se ordena los lados de las cajas en orden creciente
   - Se ordena en orden creciente las cajas que anidan (en el vector boxes).
   - Se itera por el vector boxes y para cada caja que anida se suma un contador 
     de cajas anidadas (uno para cada caja).
   - se imprime la cantidad maxima de cajas que se puede anidar
   - se construye las cajas que anidan y se imprime
**/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Box{
   vector<int> d;
   int id;

   bool operator<(const Box& b)const {
      for(int i = 0; i < d.size(); i++){
         if(d[i] >= b.d[i]){
            return false;
         }
      }
      return true;
   }
   
   bool operator>(const Box& b)const {
      for(int i = 0; i < d.size(); i++){
         if(d[i] <= b.d[i]){
            return false;
         }
      }
      return true;
   }
};

vector<Box> boxes;

// ordenamiento burbuja
void my_sort(){
   for(int i = 0; i < boxes.size()-1; i++){
      for(int j = i+1; j < boxes.size(); j++){
         if(boxes[i] > boxes[j] ){
            swap(boxes[i], boxes[j]);
         }
      }
   }
}

void solve(void){
   vector<int> c(boxes.size(), 1), p(boxes.size());
   
   // inicializar datos..
   for(int i = 0; i < p.size(); i++){ 
      p[i] = i;
   }
   //calcular el numero de cajas anidadas
   for(int i = c.size()-2; i >= 0; i--){     
      for(int j = i+1; j < c.size(); j++){
         if(boxes[i] < boxes[j]){
            if(c[j]+1 > c[i]){
               c[i] = c[j] + 1;
               p[i] = j;
            }
         }
      }
   }

   // buscar la cantidad maxima de cajas anidadas
   int m = 1, index = 0;
   
   for(int i = 0; i < c.size(); i++){
      if(c[i] > m){
         index = i;
         m = c[i];
      }
   }
   
   // imprimir solucion
   cout << m << endl << boxes[index].id ;
   
   for(int i = 1; i < m; i++){
      cout << " " << boxes[p[index]].id;
      index = p[index];
   }
   cout << endl;
}

int main(){
   int k, n, dim;
   
   while(cin >> k >> n){
      for(int i = 1 ; i <= k; i++){
         Box b;
         b.id = i;

         for(int j = 0; j < n; j++){
            cin >> dim;
            b.d.push_back(dim);
         }

         sort(b.d.begin(), b.d.end());
         boxes.push_back(b);
      }

      my_sort(); 
      solve();
      boxes.clear();
   }
   return 0;
}
