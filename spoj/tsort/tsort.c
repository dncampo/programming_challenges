#include <stdio.h>

int data[1000001];

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
		 for(i = 0; i <= 1000000;i++){
			 string s;
               for(j = 0; j < data[i]; j++){
						s += i;
						s += ((char)13);
                       //printf("%d\n", i);
               }
			cout << s;
       }
       return 0;
}
