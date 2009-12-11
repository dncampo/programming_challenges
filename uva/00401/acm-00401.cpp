/**
 * Title: Palindromes
 * URL: http://online-judge.uva.es/p/v4/401.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   Para cada entrada se chequea si es palindrome y/o espejado.
   Se utiliza un map para facilitar la codificacion cuando se
   chequea si son espeajados.
   
**/

#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

bool palindrome(string& line){
   for(unsigned i = 0, j = line.size()-1; i < line.size()/2; i++, j--){
      if(line[i] != line[j]){
         if((line[i] == '0' && line[j] == 'O') || (line[j] == '0' && line[i] == 'O')){
            continue;
         }
         return false;
      }
   }

   return true;
}

bool mirrored(string& line){
   for(unsigned i = 0; i < line.size(); i++){ /* not mirrored */.
      switch(line[i]){
         case 'B': case 'C': case 'D':
         case 'F': case 'G': case 'K':
         case 'N': case 'P': case 'Q':
         case 'R': case '4': case '6':
         case '7': case '9': 
            return false;
      }
   }
   map<char, char> m; /*list of reverses*/
   string rev = line;  
      
   m['A']='A'; m['E']='3';
   m['3']='E'; m['H']='H';
   m['I']='I'; m['J']='L';
   m['L']='J'; m['M']='M';
   m['0']='O'; m['O']='O';
   m['S']='2'; m['2']='S';
   m['T']='T'; m['U']='U';
   m['V']='V'; m['W']='W';
   m['X']='X'; m['Y']='Y';
   m['Z']='5'; m['5']='Z';
   m['1']='1'; m['8']='8'; 

   for(unsigned i = 0; i < rev.size(); i++){
      rev[i] = m[rev[i]];
   }
   
   reverse(rev.begin(),rev.end());
   
   return rev == line;
}

string solve(string& line){
   if(palindrome(line)){
      if(mirrored(line)){
         return " -- is a mirrored palindrome.";
      }else{
         return " -- is a regular palindrome.";
      }
   } else {
      if(mirrored(line)){
         return " -- is a mirrored string.";
      }else{
         return " -- is not a palindrome.";
      }   
   }
}
int main(){
   string line;
   while(cin >> line){
      cout << line << solve(line) << endl << endl;
   }
   
   return 0;
}
