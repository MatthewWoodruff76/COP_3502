#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Customer Customer;

struct Customer{
	Customer* prev_Customer;
	char S[21];
	long int M;
};

void printMVP(Customer* last_in);
Customer* addCustomer(Customer* last_in);
Customer* delCustomer(Customer* last_in);

int main(){
	int i, t = -1;
	long int M;
	char S[21];
	Customer * last_in;
	last_in = NULL;
	
	while(t!=0){
		scanf("%d", &t);
		
		//Adds a new player to the top of the stack.
		if(t==1) last_in = addCustomer(last_in);
		
		//Removes the top of the stack, skips if empty.
		if(t==2&&last_in!=NULL) last_in = delCustomer(last_in);
		
		//Searches for and prints the MVP.
		if(t==3) printMVP(last_in);
	}
	
	//Kicks out remaining customers.
	while(last_in!=NULL) last_in = delCustomer(last_in);
	
	return 0;
}

Customer* addCustomer(Customer* last_in){
	Customer *newCustomer;
	newCustomer = (Customer*)malloc(sizeof(Customer));
	scanf("%li %s", &newCustomer->M, &newCustomer->S);	
	newCustomer->prev_Customer = last_in;
	return newCustomer;
}
Customer* delCustomer(Customer* last_in){
	Customer* new_last = last_in->prev_Customer;
	free(last_in);
	return new_last;
}

void printMVP(Customer* last_in){
	long int Value = -1;
	char MVP[21];
	
	while(last_in!=NULL){
		if((*last_in).M>Value){
			Value = (*last_in).M;
			strcpy(MVP, (*last_in).S);
		}
		last_in = (*last_in).prev_Customer;
	}
	
	printf("%s\n", MVP);
}
