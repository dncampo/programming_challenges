#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

int main ()
{
  int iSecret, iGuess;

  /* initialize random seed: */
  srand (time(NULL));

  /* generate secret number between 1 and 10: */
  iSecret = rand() % 2147483648 + 3;

	int i = 3000;
  do {
  	iSecret = rand() % 2147483648 + 3;
	cout << iSecret << endl;
  } while (i--);

  return 0;
}

	

