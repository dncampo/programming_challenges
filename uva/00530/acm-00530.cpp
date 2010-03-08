/**
 * Title: Binomial Showdown 
 * URL: http://uva.onlinejudge.org/external/5/530.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
    + Se utiliza el triangulo de pascal y la técnica de memorización para calcular la combinacion(n, r). 
    + Como detalle particular de este problema es que se lee como string por que el problema no 
    dice nada respecto a los valores de entrada, solo que la salida no excede el valor máximo de un entero. 
    Puede ser tranquilamente una combinación de:
    - C(102312313215465465465651561561531321321321231,0) cuyo resultado es un número entero (= 1). 
    - C(10231231321546546546565156156153132132132123,10231231321546546546565156156153132132132123) = 1.     
    - etc
**/

#include<limits>
#include <sstream>
#include <cstdio>
#include <iostream>
using namespace std;
 
#define MAX 800
unsigned triangle[MAX][MAX];

unsigned recurrence(int n, int r){
   if(n-1 >= MAX){
     if(n == r || r == 0) 
         return 1;
     else if(n == r+1 || r == 1) 
         return n;
      else
         return recurrence(n-1, r) + recurrence(n-1, r-1);
   } 

   if(n == r || r == 0) {
      triangle[n-r][r] = 1;
   } else if(n == r+1 || r == 1) {
      triangle[n-r][r]= n;
   }else if(triangle[n-r][r] != 0)
      return triangle[n-r][r];
    else 
      triangle[n-r][r] =  recurrence(n-1, r) + recurrence(n-1, r-1);
   
   return triangle[n-r][r];
}


void read(int & n, int& r){
   string sn, sr;
   cin >> sn >> sr;
   
   if(sn.size() <= 10){
      long long nn;
      stringstream sin(sn);         
      sin >> nn;
      
      if(nn <= numeric_limits<int>::max())
        n = nn;
      else 
         n = -1; 
   } else {
      n = -1;
   }
   
    if(sn == sr){
      r = n;
   }  else if(sr.size() <= 10){
      long long rr;   
      stringstream sin(sr);         
      sin >> rr;
      
      if(rr <= numeric_limits<int>::max())
        r = rr;
      else 
         r = -1; 
   } else {
      r = -2;// por si se necesita distinguir
   }
}

int main(){
   int n, r;

   read(n, r);
   
   while(n != 0 || r !=0){
      if (n < 0) {
         cout << 1 << endl;
      } else {
         cout << recurrence(n, r) << endl;
      }
         
      read(n,r);
   }
   return 0;
}
