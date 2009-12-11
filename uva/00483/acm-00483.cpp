/**
 * Title: Word Scramble 
 * URL: file:///home/yeyo/Desktop/acm-00483/acm-00483.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   Es un problema trivial. Para cada entrada se va invirtiendo 
   cada palabra e imprimiendo la palabra.
**/


#include <iostream>
#include <algorithm>
using namespace std;


int main(){
   string s;
   
   while(getline(cin, s)){
      string::size_type loc  = 0; 
 
      while((loc = s.find(" ")) != string::npos){
         string tmp =s.substr(0, loc);
         s = s.substr(loc+1, s.size());
         
         reverse(tmp.begin(), tmp.end());
         cout << tmp << " ";
      }
 
      reverse(s.begin(), s.end());
      cout << s << endl;
   }
}
