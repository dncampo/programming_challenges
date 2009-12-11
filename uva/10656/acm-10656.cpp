/** 
 * Title: Maximum Sum II
 * URL: http://uva.onlinejudge.org/external/106/10656.html
 * Resources of interest:
 * Solver group: David - Yeyo
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Considerar el caso en el que la suma máxima es cero.
   + Respetar rigurosamente el formato, sin espacios de más; sino no se obtiene Accepted.
	
**/


#include <cstdio>

using namespace std;

int main(){
	int nums;
	
	while(1){
		scanf("%d",&nums);
		
		bool first = true, print = false;
		
		if (nums == 0)	return 0;
		
		for (int a = 0; a < nums; a++){
			int tmp;
			scanf("%d",&tmp);
			
			if (tmp != 0){
				if(first) {
					print = true;
					printf("%d",tmp);
					first = false;
				}
				else printf(" %d",tmp);
			}
		}
		if (!print)	printf("0");
		printf("\n");
	}
	return 0;
}

