#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 12
#define MAX_CHARS 21	//One more than the actual max, to make room for the terminus.

void multicat(char word[], char words[][MAX_CHARS], int size);											//Concatenates multiple strings.
int judge(int * used, char original [][MAX_CHARS], char current [][MAX_CHARS], int size, int index);	//Judges the value of each combination.
int isPretty(int size, char words[][MAX_CHARS]);														//Determines if the combination is pretty.

int main(){
	int n, i, used[MAX_WORDS];																			//used[] flags in-progress indexes with pseudo-boolean.
	scanf("%d", &n);
	char words[n][MAX_CHARS], savedwords[n][MAX_CHARS];													//One array maintains the savedwords state, the other cycles.
	//Read input and initialize used array.
	for(i=0;i<n;i++) {
		scanf("%s", words[i]);
		strcpy(savedwords[i],words[i]);
		used[i] = 1;
	}
	//Perform brute-force recursion.
	judge(used,savedwords,words,n,0);
	return 0;
}

void multicat(char word[], char words[][MAX_CHARS], int size){	//Combines an input 2D array into a 'sentence.'
	int i;
	for(i=0;i<size;i++) {
		strcat(word,words[i]);
		strcat(word," ");	
	}
	if(size>0)  strcat(word,words[size]);	//Eliminates the dangling space with a special case.
}

int judge(int * used, char savedwords [][MAX_CHARS], char words [][MAX_CHARS], int size, int index){
	int i;
	if(size==index){																				//Base case
		if(isPretty(size,words)==0) return 0;														//Begins close-out procedure on the pretty case.
		return 1;
	}
	for(i=0;i<size;i++){
		if(used[i]==1){
			used[i]=0;																				//Marks the index as in-progress.
			strcpy(words[index],savedwords[i]);														//Copies from the original values.
			if(judge(used, savedwords, words, size, index+1)==0) return 0;							//Continues close-out procedure for a successful call.
			used[i] = 1;																			//Closes the index's status.
		}
	}
	return 1;
}

int isPretty(int size, char words[][MAX_CHARS]){	//Checks the combination and grades it.
	int i;
	char pretty[MAX_CHARS*(MAX_WORDS+1)] = "";
	for(i=0;i<size-1;i++) {
		if(words[i][strlen(words[i])-1]!=words[i+1][0]) {	//Checks for failure, not success.
			return 1;
		}
	}
	multicat(pretty,words,size-1);
	printf("%s", pretty);
	fflush(stdout);
	return 0;
}

