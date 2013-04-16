/**
 * Title: Word Index 
 * URL: http://online-judge.uva.es/p/v4/417.html
 * Resources of interest:
 * Solver group: Yeyo - Leo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
  + Para resolver este problema se utiliza una tabla hash en donde
   se va guardando para cada cadena un valor correspondiente a su posicion.
**/

#include <iostream>
#include <map>
using namespace std;

map<string, int> solution;

void solve(){
   int count = 0;
   
   for(char i = 'a'; i <= 'z'; i++){
      string s = "";
      s += i;
      solution[s] = ++count;
   } 
   
   for(char i = 'a'; i <= 'z'; i++){
      for(char j = i+1; j <= 'z'; j++){
         string s = "";
         s += i, s += j;
         
         solution[s] = ++count;
      }
   } 
   for(char i = 'a'; i <= 'z'; i++){
      for(char j = i+1; j <= 'z'; j++){
         for(char k = j+1; k <= 'z'; k++){
            string s = "";
            s += i, s += j, s+= k;
            
            solution[s] = ++count;
         }
      }
   }
   
   for(char i = 'a'; i <= 'z'; i++){
      for(char j = i+1; j <= 'z'; j++){
         for(char k = j+1; k <= 'z'; k++){
            for(char w = k+1; w <= 'z'; w++){
               string s = "";
               s += i, s += j, s+= k, s += w;
               
               solution[s] = ++count;
            }
         }
      }
   }
      
   for(char i = 'a'; i <= 'z'; i++){
      for(char j = i+1; j <= 'z'; j++){
         for(char k = j+1; k <= 'z'; k++){
            for(char w = k+1; w <= 'z'; w++){
               for(char y = w+1; y <= 'z'; y++){            
                  string s = "";
                  s += i, s += j, s+= k, s += w, s += y;
                  
                  solution[s] = ++count;
               }
            }
         }
      }
   }   
}


int main(){
   solve();
   string input;
   
   while(cin >> input){
      cout << solution[input] << endl;
   }

   return 0;
}
