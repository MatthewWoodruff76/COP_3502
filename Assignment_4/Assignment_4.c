#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct person person;

struct person{	//Each person contains the data to a single entry.
	char name [21];
	long long int val, bills, tokens;
};

struct person newPerson();	//Creates a new person and scans in information.

void QuickSort(struct person people[], int n);	//The actual sorting algorithm.

int main(){
	
	int i, n = 0; 
	long long int EX_RATE_TOK, EX_RATE_BIL;	//The token rate has no upper limit and must be stored as a long long int.

	scanf("%d", &n); //Reads in number of entries.
	
	struct person people[n];	//Creates an array of structs for storing the information.
	
	for(i=0;i<n;i++) people[i] = newPerson(); //Creates a new person for each element and scans in their information
	
	scanf("%d %d", &EX_RATE_BIL, &EX_RATE_TOK);	//Reads in exchange rates to convert to arbitrary units
	
	for(i=0;i<n;i++) people[i].val = people[i].tokens*EX_RATE_TOK+people[i].bills*EX_RATE_BIL;	//Converts the mixed values to a single, arbitrary unit scale.
	
	QuickSort(people, n);	//Performs the sort
	
	for(i=0;i<n;i++) printf("%s\n", people[i].name);	//Prints final answer
	
	return 0;
}

struct person newPerson(){
	struct person person;
	scanf("%s", person.name);
	scanf("%lli", &person.tokens);
	scanf("%lli", &person.bills);
	return person;
}

void QuickSort(struct person people[], int n){
	
	if(n<2) return;
	
	int i, front = 0, back = 0;	//Initializes variables to track the size of array to each side of the foci.
	struct person temp, foci = people[0]; //The foci is a struct rather than a value, as it must store an entire person.
	
	for(i=1;i<n;i++){	//Loops through every proceeding element
	
		if(people[front+1].val>foci.val) front++;	//Includes qualifying elements in the first array
		else {	//Moves disqualified elements into the back array
			temp = people[front+1];
			people[front+1] = people[n-back-1];
			people[n-back-1] = temp;
			back++;
		}	
	}
	
	people[0] = people[front];	//Swaps using the foci as a temporary struct
	people[front] = foci;
	
	QuickSort(people,front);		//Sorts the first array
	QuickSort(people+front+1,back);	//Sorts the second array
}


