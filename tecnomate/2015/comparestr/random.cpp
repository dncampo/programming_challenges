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


	int i = 3001;
  do {
   string s="";  
   for (int j=0; j<50; j++){
     	iSecret = rand() % 10 + 48;
      s =  s + (char)iSecret;
   }
	   cout << s << endl;
  } while (i--);

  return 0;
}

	

