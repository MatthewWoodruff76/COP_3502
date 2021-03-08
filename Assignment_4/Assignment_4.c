#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct person person;

struct person{
	char name [21];
	long long int val, bills, tokens;
};

struct person newPerson();

void QuickSort(struct person people[], int n);

int main(){
	int i, n = 0, EX_RATE_TOK, EX_RATE_BIL;

	scanf("%d", &n); //Reads in number of entries.
	
	struct person people[n];	//Creates an array of structs for storing the information.
	
	for(i=0;i<n;i++){	//Reads in account info
		people[i] = newPerson();
	}
	
	scanf("%d %d", &EX_RATE_BIL, &EX_RATE_TOK);	//Reads in exchange rates to convert to arbitrary units
	
	for(i=0;i<n;i++) people[i].val = people[i].tokens*EX_RATE_TOK+people[i].bills*EX_RATE_BIL;	//Converts each bank account to an arbitrary value.
	
	QuickSort(people, n);
	
	for(i=n-1;i>=0;i--) printf("%s has %lli\n", people[i].name, people[i].val);	//Prints final answer
	
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
	int front = 0, back = 0, i;
	struct person temp, foci = people[0];
	for(i=1;i<n;i++){
		if(people[front+1].val<=foci.val) front++;
		else {
			temp = people[front+1];
			people[front+1] = people[n-back-1];
			people[n-back-1] = temp;
			back++;
		}	
	}
	
	people[0] = people[front];
	people[front] = foci;
	
	QuickSort(people,front);
	QuickSort(people + front + 1, back);
}


