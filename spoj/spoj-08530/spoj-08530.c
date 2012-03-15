#include <stdio.h>
#include <string.h>
#include <math.h>

#define PSIZE 32


unsigned powers[PSIZE];

void init_powers () {
   
   unsigned pow = 0;
   register unsigned c;
   powers[0] = pow;
   for (c = 1; c < PSIZE; c++) {
      powers[c] = ((powers[c-1] + 1) << 1) - 1;
   }

}

int main () {
   
//   init_powers ();
   
   char input[32];
   
   while(scanf("%s",input)!=EOF && input[0] != '0'){
      unsigned sum = 0;

      unsigned size = strlen(input);
      unsigned mov = size - 1;
      register unsigned c;
      for (c = 1; c <= size; c++, mov--) {
	sum += (pow(2.0, (double)(c)) -  1) * (input[mov] - '0');
      }
      
      printf ("%u\n", sum);
   }
   
   return 0;
}

