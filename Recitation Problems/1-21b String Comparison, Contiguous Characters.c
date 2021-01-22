#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10001

int main(){
	//A function to determine the longest length identical string between two strings
	char string1[MAX], string2[MAX];
	int i, j, k, win = 0, contest;
	
	printf("Input string 1: ");
	scanf("%s", string1);
	printf("Input string 2: ");
	scanf("%s", string2);
	
	if(strlen(string1)<strlen(string2)){
		char swap[MAX];
		strcpy(swap,string1);
		strcpy(string1,string2);
		strcpy(string2,swap);
	}
	
	for(i=0;i<strlen(string1);i++){
		for(j=0; j<strlen(string1)-i;j++){
			contest = 0;
			for(k=0;k<=j;k++){
				if(string2[k]==string1[i+k]) contest++;
			}
			if(contest>win) win = contest;
		}
	}
	printf("The longest string of contiguous characters was %d", win);
	return 0;
}
