#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100001

void printHandles(char handles[][MAX_LENGTH], int total_handles){
	int index;
	printf("\n");
	for(index = 0; index<total_handles; index++) printf("%s\n", handles[index]);
}

int main(){
	
	//Reads in the desired number of entries
	
	int total_names, name, index;
	printf("How many handles will be generated?\nInteger value: ");
	scanf("%d", &total_names);
	
	//Rejects invalid numberical entries
	
	if(total_names<=0||total_names>=MAX_LENGTH) {
		printf("\nGet lost.");
		return 1;
	}
	
	//Initializes character elements
	
	char names[total_names][MAX_LENGTH], handles[total_names][MAX_LENGTH], echo;
	for(name = 0; name<total_names; name++){ 
		for(index = 0; index<MAX_LENGTH; index++){
			names[name][index] = '\0';
		}
	}
	
	//Reads input
	
	printf("Enter names below.\n");
	getchar();
	for(name = 0; name<total_names; name++){
		index = 0;
		while((names[name][index] = getchar())!='\n'){
			index++;
		}
	}
	
	//Processes handles
	
	for(name = 0; name<total_names; name++){
		int index = 1, glove = 1;
		handles[name][0] = names[name][0];
		while(((echo = names[name][index])!='\0')&&(echo!='\n')){
			if(names[name][index]==' ') glove++;	//Accepts end letter
			handles[name][glove] = echo;			//Tentatively stores new letter
			if(names[name][index-1]==' ') glove++;	//Accepts start letter
			index++;
		}
	}
	
	//Prints results
	
	printHandles(handles,total_names);
	printf("\n\nPress any key to exit...");
	getchar(); //Pauses to display answer.
	return 0;
}


