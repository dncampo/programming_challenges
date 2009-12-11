/** 
 * Title: Perfection
 * URL: http://online-judge.uva.es/p/v3/382.html
 * Resources of interest:
 * Solver group: Leo
 * Contact e-mail: bortoli.leonardo at gmail dot com
 * Description of solution:
    Primero se inicializa un vector con las sumatorias de los divisores
    de cada numero. Luego para imprimir se hace la verificacion correspondiente,
    o sea, si es perfecto, deficiente o abundante. Se utiliza tambien formato
    de salida estandar, ya que el enunciado asi lo requiere.
**/

#include<iostream>
#define SIZE 60001

using namespace std;

int num[SIZE] = {0};

int main(){
   for(int i=2; i<SIZE/2; i++){
      for(int j=2; i*j<SIZE; j++){
         num[i*j] += i;
      }
      num[i]++;
   }
   
   cout << "PERFECTION OUTPUT" << endl;
   
   int n;
   cin >> n;
   
   while(n != 0){
      cout.width(5);
      cout.setf(ios::right);
      cout << n;
      cout << "  ";
      
      if(n == num[n])
         cout << "PERFECT" << endl;
      else if(n > num[n])
         cout << "DEFICIENT" << endl;
      else
         cout << "ABUNDANT" << endl;
      
      cin >> n;
   }
   
   cout << "END OF OUTPUT" << endl;
   
   return 0;
}
