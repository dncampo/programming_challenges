#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(){
	unsigned i, j;
	char c, sentence[500001], n_cases[10];

	scanf("%s\n", n_cases);

	for(i = 0; i < atoi(n_cases); i++){

		scanf("%s\n", sentence);

		for(j = 0; j < strlen(sentence); j++){
			c = sentence[j];
			if( (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u') ) 
				c -= 32;

			printf("%c",c);
		}
		printf("\n");
	}
	return 0;
}

