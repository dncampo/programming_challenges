#include <stdio.h>
#include <string.h>

int main(){
	unsigned cnt_words, a, b, c, bsize, csize, b_len, c_len;
	int ret1, ret2, i, j;
	long long cnt = 0;
		
	scanf("%u",&cnt_words);
	char words[cnt_words][11];
	
	for(a = 0; a < cnt_words; a++) scanf("%s",words[a]);
	
	for(b = 0; b < cnt_words - 1; b++){
		bsize = strlen(words[b]);
		for(c = b + 1; c < cnt_words; c++){
			csize = strlen(words[c]);
			
			char *b_str = words[b];
			char *c_str = words[c];
						
			if(csize > bsize) {
				char *tmp = b_str;
				b_str = c_str;
				c_str = tmp;
			}
			

/* Inicio función dislike */
			ret1 = 0, ret2 = 0, i,j;
			b_len = strlen(b_str) , c_len = strlen(c_str);
	
			/* ver si b < c */
			for(i = 0, j = 0; j < (int)c_len; i++, j++){
				if ( (b_str[i] > c_str[j])) break;		
				else if((b_str[i] < c_str[j])){
					ret1 = 1;
					break;
				}
			}

			/* ver si b_reversed < c_reversed */
			for(i = (int)b_len - 1, j = (int)c_len - 1;	j >= 0; i--, j--){
				if ( (b_str[i] > c_str[j])) break;		
				else if((b_str[i] < c_str[j])){
					ret2 = 1;
					break;
				}
			}
	
			if ( ((0 == ret1) && (0 != ret2)) || ( (0 != ret1) && (0 == ret2)) )	cnt++;
		/*	else return 0;*/
/*Fin función dislike*/



			
/*				if(dislike(words[b] ,words[c])) cnt++;
			}
			else {
				if(dislike(words[c], words[b])) cnt++;
			}
*/
		}	
	}
	printf("%lld\n",cnt);
	return 0;
}

