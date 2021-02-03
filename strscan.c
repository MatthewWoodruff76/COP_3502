//A specialized version of scanf for reading multiple words (terminated by a new line) into a single string.

#include <stdio.h>
#include <stdlib.h>

char * strscan();

int main(){
	printf("%s", strscan());
	return 0;
}

char * strscan(){
		int index = 0;
		char * input;
		input = calloc(10,sizeof(char));
		//Scan in response;
		while((input[index] = getchar())!='\n'){
			index++;
		} input[index] = '\0';								//Ends the input as a single string
		return input;
}
