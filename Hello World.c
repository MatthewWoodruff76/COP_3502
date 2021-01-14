#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * changeTunes(char in[]){
	int size = strlen(in);
	char out[] = { in[0], in[size-1], '\0'};
	printf("%s\n", out);
	printf("%s\n", in);
	return out;
}

void main(){
	char greeting[] = "Hello";
	printf("%s\n", greeting);
	printf("%s", changeTunes(greeting));
	

}


