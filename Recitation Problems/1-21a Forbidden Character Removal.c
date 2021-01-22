#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 101


int main(){
	//A function which removes forbidden characters from an input string.
	//Forbidden characters are separated by a space bar.
	char input[MAX_LENGTH], output[MAX_LENGTH];
	printf("Input string: ");
	scanf("%s", input);
	int total_forbidden, i = 0, j, flag, tally = 0;
	printf("Input number of forbidden characters: ");
	scanf("%d", &total_forbidden);
	char forbidden[total_forbidden];
	printf("Input forbidden characters separated by spaces: ");
    getchar();
	for(i=0;i<total_forbidden;i++){
		forbidden[i] = getchar();
		if(i!=total_forbidden-1) getchar(); //Removes space
	}
	for(i=0; i<MAX_LENGTH;i++){
		flag = 0;
		for(j=0; j<2*total_forbidden-1; j++){
			if(input[i]==forbidden[j]){
				flag = 1;
			}
		}
		if(flag==0){
			output[tally] = input[i];
			tally++;
		}
	}
	output[tally] = "/0";
	printf("%s", output);		
	return 0;
}
