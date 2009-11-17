#include <stdio.h>
#include <string>

#define MAX 1000001
#define MAX_9 9000001


unsigned data[MAX];
char out[MAX_9];

int main(){
       int t, value, i, j;
       int max = 0, min = 1000000;
       scanf("%d", &t);

       for(i = 0; i < t; i++){
               scanf("%d", &value);
               data[value]++;
               if(value > max)
                       max = value;

               if(value < min)
                       min = value;

       }
		unsigned last = 0;
		for(i = min; i <= max;i++){

               for(j = 0; j < data[i]; j++){
						s += i;
						s += ((char)13);
                       //printf("%d\n", i);
               }
       }
		 printf ("%s", s.c_str());
       return 0;
}
