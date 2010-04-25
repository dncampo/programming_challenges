#include <iostream>
#include <string>
#include <sstream>

#define SZ(x) (x).size()

using namespace std;

class HowEasy {

   public:
   
      bool valid_word(string &w) {
         string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";      
         unsigned long long pos = w.find_first_of('.');
        
         if (pos != SZ(w) - 1 && pos != string::npos) return false;

         if (pos == SZ(w) - 1) w = w.substr(0,SZ(w) - 1);

         if (0 == SZ(w)) return false;

         //ok
         pos = w.find_first_not_of(alphabet);
         if (string::npos == pos) return true;
         
         return false;
   }
   
   
   int pointVal (string s) {

      unsigned avg = 0;
      unsigned sizes = 0, words = 0;
      istringstream is(s);    
     
      while (is) {
         string tmp;         
         is >> tmp;
         
         if (valid_word(tmp)) {
            words++;
            sizes += SZ(tmp);
         }
      }

      if (words == 0) words++;
      
      avg = sizes / words;
         
      if (avg <= 3) return 250;         
      else if (avg <= 5) return 500;      
      else return 1000;
   }
};



int main () {
   HowEasy h;
   string s("aa.....aaaaaaxxxxax");
   cout << h.pointVal(s);
}

