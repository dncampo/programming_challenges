/** 
 * Title: Super long sums
 * URL: http://online-judge.uva.es/p/v100/10013.html
 * Resources of interest: 
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   + Se utiliza una suma manual sin declarar un tipo de datos.
**/



#include <cstdio>


int main () {
   int cases, size; 
   scanf("%d", &cases);
	   
   for(int x = 0; x < cases; x++){
      scanf("%d", &size);
      size++;
   	short num[size], num2[size], res[size];
   	num[0] = num2[0] = 0;
   	
   	for(int i = 1; i < size; i++){
      	scanf("%d%d", &num[i], &num2[i]);
   	}

      int carry = 0;
   	for(int i = size-1 ; i >= 0; i--){
   	   res[i] = num[i] + num2[i] + carry;
   	   carry = res[i] / 10;
   	   res[i] -= carry * 10;
   	}

   	int i = 0, j = 0;
   	while(res[i] == 0) i++;

   	if(x > 0) printf("\n");
      char temp[size];
      
   	for(; i < size; i++){
   	   temp[j++] = res[i]+ '0';
   	}
   	
   	temp[j] = '\0';
   	printf("%s\n", temp);

   }
   return 0;
}


