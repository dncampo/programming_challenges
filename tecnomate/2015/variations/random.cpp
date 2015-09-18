#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>

using namespace std;

int main ()
{
  unsigned iSecret;

  /* initialize random seed: */
  srand (time(NULL));


  int i = 301;
  do {
   string s="";  
   for (int j=0; j<rand()%16 + 1; j++){
     	iSecret = rand() % 26 + ((rand()%2) ? 65: 97);
      s =  s + (char)iSecret;
   }
	   cout << s << endl;
  } while (i--);

  return 0;
}

	

