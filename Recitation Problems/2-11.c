#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 0;

void perm(int * used, char * original, char * current, int len, int pos){
	int i;
	if(len==pos){	//Base case
		printf("%d. ", ++count);
		for(i=0;i<len;i++){
			printf("%c", current[i]);
		}
		printf("\n");
		return;
	}
	for(i=0;i<len;i++){
		if(used[i]==1){
			used[i]=0;
			current[pos] = original[i];
			perm(used, original, current, len, pos+1);
			used[i] = 1;
			current[pos] = '\0';
		}
	}
}


int main(){
	int i, n = 7;
	int used[n];
	for(i=0;i<n;i++) used[i] = 1;
	char original[n], current[n];
	original[0] = 'a';
	original[1] = 'b';
	original[2] = 'c';
	original[3] = 'd';
	original[4] = 'e';
	original[5] = 'f';
	for(i=0;i<n;i++) current[i] = original[i];
	perm(used, original, current, n-1, 0);
	return 0;
}
