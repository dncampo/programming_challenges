/** 
 * Title: Quirksome Squares
 * URL: http://online-judge.uva.es/p/v2/256.html
 * Resources of interest:
 * Solver group: Leo
 * Contact e-mail: bortoli.leonardo at gmail dot com
 * Description of solution:
    Voy preguntando por cada numero hasta el maximo (de 8 digitos), si el
    cuadrado de la suma entre los numeros formados por las dos mitades
    de los digitos, es igual al numero en cuestion y luego, se agrega
    al vector correspondiente (por la cantidad de digitos original).
    Por ultimo se imprimen los elementos de los vectores correspondientes
    al numero leido en la entrada.
**/

#include<iostream>
#include<vector>

#define SIZE 100000000

using namespace std;

vector<int> two, four, six, eight;

void print(vector<int>& v, int n){
   for(unsigned i=0; i<v.size(); i++){
      int c, tmp = v[i];
      if(tmp == 0) c = 1;
      else c = 0;
      
      for(; tmp > 0; c++, tmp /= 10) ;
      for(int j=0; j<n-c; j++)
         putchar('0');
      cout << v[i] << endl;
   }
}

int main(){
   int d, m;
   // 2 digitos
   for(int i=0; i<100; i++){
      d = i / 10;
      m = i - 10*d;
      
      if((d+m)*(d+m) == i)
         two.push_back(i);
   }
   // 4 digitos
   for(int i=0; i<10000; i++){
      d = i / 100;
      m = i - 100*d;
      
      if((d+m)*(d+m) == i)
         four.push_back(i);
   }
   // 6 digitos
   for(int i=0; i<1000000; i++){
      d = i / 1000;
      m = i - 1000*d;
      
      if((d+m)*(d+m) == i)
         six.push_back(i);
   }
   // 8 digitos
   for(int i=0; i<SIZE; i++){
      d = i / 10000;
      m = i - 10000*d;
      
      if((d+m)*(d+m) == i)
         eight.push_back(i);
   }
   
   int n;
   while(cin >> n){
      switch(n){
         case 2:
            print(two, n);
            break;
         case 4:
            print(four, n);
            break;
         case 6:
            print(six, n);
            break;
         case 8:
            print(eight, n);   
      }
   }
   
   return 0;
}
