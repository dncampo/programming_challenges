//http://www.spoj.com/problems/FACTCG2/


#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

struct Factor{
   int value;
   short degree;
};

vector<vector<Factor> > list;

void pfactors(int limit){
   char p[limit+1];
   memset(p, 1, sizeof(p));
   
   list.resize(limit+1);
   
   for(int i=2; i <= (limit+1)/2; i++){
      if(p[i]){
         Factor f = {i, 0};
         for(int j=2; i*j <= limit; j++){
            list[i*j].push_back(f);
            p[i*j] = 0;
         }
      }
   }
   
   for(int i=2; i <= limit; i++){
      if(p[i] == 0){
         for(unsigned j=0; j < list[i].size(); j++){
            int num, div = i / list[i][j].value;
            do{
               num = div;
               div = num / list[i][j].value;
               list[i][j].degree++;
            } while(div * list[i][j].value == num);
         }
      } else{
         Factor f = {i, 1};
         list[i].push_back(f);      
      }
   }
}

int main(){
   pfactors(9000000);
      
   for(unsigned i=2; i < list.size(); i++){
      cout << i << ": ";
      for(unsigned j=0; j < list[i].size(); j++){
         cout << list[i][j].value << "(" << list[i][j].degree << ") "; 
      }
      cout << endl;
   }
   return 0;
}
