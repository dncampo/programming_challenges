#include <iostream>

using namespace std;

char* conj[3][6] = { {"o", "amos", "o", "emos", "o", "imos"},
		    {"as", "Ais", "es", "Eis", "es", "Is" },
		    {"a", "an", "e", "en", "e", "en" } };
		    

int main(){
  string a,b,c,d,e, res;
  while(cin >> a >> b >> c >> d >> e){
    
    unsigned index_1, index_2;
      
    if(b[0] == 'f') index_1 = 0;
    else if(b[0] == 's') index_1 = 1;
    else index_1 = 2;
    
    if(d[0] == 's') index_2 = 0;
    else index_2 = 1;

    if(a[a.size() - 3]  == 'e') index_2 += 2;
    else if (a[a.size() - 3] == 'i') index_2 += 4;
    
    a = a.substr(0, a.size()-3);
    a = a + conj[index_1][index_2];
    
    
    if(a == e) cout << "correct" << endl;
    else cout << "incorrect, should be " << a << endl;   
      
  }
  
  return 0;
}
