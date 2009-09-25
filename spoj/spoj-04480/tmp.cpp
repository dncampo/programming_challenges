#include <stdio.h>
#include <string.h>


int dislike(char* a, char* b){
	int ret1 = 0, ret2 = 0;
	unsigned i, j, alen = strlen(a) , blen = strlen(b);
	
	//ver si a < b
	for(i = 0, j = 0; j < blen; i++, j++){
		if ( (a[i] > b[j])) break;		
		else if((a[i] < b[j])){
			ret1 = 1;
			break;
		}
	}

	//ver si a_reversed < b_reversed
	for(int i = (int)alen - 1, j = (int)blen - 1;	j >= 0; i--, j--){
		if ( (a[i] > b[j])) break;		
		else if((a[i] < b[j])){
			ret2 = 1;
			break;
		}
	}
	
	if ( ((0 == ret1) && (0 != ret2)) || ( (0 != ret1) && (0 == ret2)) )	return 1;
	else return 0;
}

int main(){
	unsigned cnt_words, a, b, c, bsize, csize;
	char words[100000][11];
	long long cnt = 0;
		
	scanf("%u",&cnt_words);
	for(a = 0; a < cnt_words; a++) scanf("%s",words[a]);
	
	for(b = 0; b < cnt_words - 1; b++){
		bsize = strlen(words[b]);
		for(c = b + 1; c < cnt_words; c++){
			csize = strlen(words[c]);			
			if(csize <= bsize) {
				if(dislike(words[b] ,words[c])) cnt++;
			}
			else {
				if(dislike(words[c], words[b])) cnt++;
			}
		}	
	}
	printf("%lld\n",cnt);
	return 0;
}

