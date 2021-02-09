//A program for guessing a number within the range 1 to n using a reflection-based binary search algorithm and user input

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOUND 1000000000
#define MAX_N 1000000
#define PRECISION .00001	//Accounts for system rounding issues

int ceiling(double);		//No need for a floor function as integer division performs that role

int main(){
	
	int tally = 0, guess, n, lower_bound = 1, upper_bound, half_delta, index;
	char user_response[15], word2[10], word3[10];											//Set to 15 to accomodate the longest valid response
	while(1){
		scanf("%d", &n);
		if(n<=MAX_N&&n>0) break;									//Breaks from the loop for correct 'n' values
	}

	upper_bound = n;												//While n itself is usable as the upper_bound, it has no conjugate
	guess = n;
	
	while(1){														//Indeterminate loop
		
		half_delta = ceiling(0.5*(upper_bound-lower_bound));
		
		//Guess
		printf("%d\n", guess);
		fflush(stdout);

		scanf("%s", &user_response);
		if(strcmp(user_response,"No.")==0&&tally>0) {				//The first entry is a special case
			scanf("%s", &word2);
			strcat(user_response, " ");								//Replaces the whitespace that scanf removes
			strcat(user_response, word2);							//Combines the strings
			if(strcmp(word2, "No")==0){
				scanf("%s", &word3);
				strcat(user_response, " ");
				strcat(user_response, word3);
			}
		}

		//Check input and adjust accordingly
		if(strcmp(user_response, "No. Warmer.")==0){
			if(guess <= lower_bound){
				upper_bound -= half_delta;
				guess = 2*lower_bound-guess+half_delta;
			}
			else {
				lower_bound += half_delta;
				guess = 2*upper_bound-guess-half_delta;
			}
		}
		if(strcmp(user_response,"No. Colder.")==0){
			if(guess >= upper_bound) {
				upper_bound -= half_delta;
				guess = 2*upper_bound-guess-half_delta;
			}
			else {
				lower_bound += half_delta;
				guess = 2*lower_bound-guess+half_delta;
			}
		}
		if(strcmp(user_response,"No.")==0) guess = 1;				//Runs the second search
		if(strcmp(user_response,"No. No change.")==0) {
			guess = lower_bound + half_delta;
			printf("%d\n", guess);									//This guess is correct, so the program exits
			fflush(stdout);
			break;
		}
		if(guess>BOUND||guess<-BOUND) return 1;
		tally++;
	}
	return 0;
}

int ceiling(double value){
	int answer = value;
	if(value - answer > PRECISION) answer++;
	return answer;
}
