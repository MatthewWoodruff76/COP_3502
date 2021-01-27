#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN_SIZE  2
#define MAX_ROOKS 100000
#define MAX_SPOTS 1000000000

typedef struct arrow arrow;

struct arrow {
    int ** pieces;
    int level;
    int size;
    int capacity;
};

void Arrow_New(arrow *);
void Arrow_Delete(arrow *);
void Arrow_Grow(arrow *);
void Arrow_AddPiece(arrow *, int, int, int);
int Target_Check(int r, int c, int target_size[2]);

int main(){
	int i, j, k, n = 0, target_size[2] = {0, 0}, r, c, R, C, current_row = 0, current_column = 0, ** bag;
	while(n==0){
	printf("Desired number of rooks: ");
	scanf("%d", &n);
	if(n>MAX_ROOKS||n<1) printf("\nEnter a value from 1 to %d.", MAX_ROOKS);
	}

	
	bag = malloc(n*sizeof(int*));							//Allocates memory equal to an array of int pointers.
	for(i = 0; i<n;i++) bag[i] = malloc(10*sizeof(int));	//Allocates memory for each row
	
	struct arrow rows[n];		//These grow linearly with n, so using resizeable arrays would probably be less efficient.
	struct arrow columns[n];
	
	printf("Rook %d is at: ", 1);
	scanf("%d %d", &r, &c);
	
	if(Target_Check(r, c, target_size)==1) return 1;

	bag[0][0] = r;
	bag[0][1] = c;
	Arrow_New(&rows[current_row]); //adds a new row
	Arrow_AddPiece(&rows[current_row],0,c,r);
	Arrow_New(&columns[current_column]); //adds a new column
	Arrow_AddPiece(&columns[current_column],0,r,c);
	
	for(i = 1; i <n; i++){					//Reads input
		printf("Rook %d is at: ", i+1);
		scanf("%d %d", &r, &c);
		if(Target_Check(r, c, target_size)==1) return 1;
		bag[i][0] = r;
		bag[i][1] = c;
		R =-1, C =-1;
		for(j=0;j<=current_row;j++){
			if(rows[j].level==r){
				Arrow_AddPiece(&rows[j],i,c,r);
				R=j;
			}
		}
		for(j=0;j<=current_column;j++){
			if(columns[j].level==c){
				Arrow_AddPiece(&columns[j],i,r,c); //row and column switched for polymorphism
				C=j;
			}
		}
		if(R==-1){
			current_row++;
			Arrow_New(&rows[current_row]); //adds a new row
			Arrow_AddPiece(&rows[current_row],i,c,r);
		}
		if(C==-1){
			current_column++;
		 	Arrow_New(&columns[current_column]); //adds a new column
		 	Arrow_AddPiece(&columns[current_column],i,r,c);
		}
	}
	
	for(i=0; i < n; i++){	//Handle duplicate locations
		for(j=n-1; j>i;j--){
			if(bag[i][0]==bag[j][0]){
				if(bag[i][1]==bag[j][1]){
					printf("\nThe input has duplicate rooks at (%d,%d).", bag[i][0],bag[i][1]);
					return 1;
				}
			}
		}
	}
	
	for(i=0; i<n; i++){			 						//Cycles through each rook in the order they were entered.
	
		for(j=2; j<10; j++) {							//Initilizes threat count sections of bag
			bag[i][j]   = MAX_SPOTS+1;							//bag = {r, c, ID UP, Val UP, ID RIGHT, Val RIGHT, ID Down, Val DOWN, ID LEFT, Val Left} 	
		}

		for(j=0; j<=current_row; j++){					//Cycles through each row that was entered
			if(rows[j].level==bag[i][0]){				//Locks into the corrct row
				for(k=0;k<rows[j].size;k++){			//Cycles through rooks in the row to compare
					if(rows[j].pieces[k][0]!=i){		//Removes autocorrelation 
						if((rows[j].pieces[k][1]-bag[i][1])>0){				//If the piece is to the right, does x.  If left, does y.
							if((rows[j].pieces[k][1]-bag[i][1])<bag[i][5]){
								bag[i][5] = (rows[j].pieces[k][1]-bag[i][1]);	//Copies the absolute distance between the two into the bag.
								bag[i][4] = rows[j].pieces[k][0];				//Copies the ID of the hit.
							}
						} else {
							if((rows[j].pieces[k][1]-bag[i][1])>-bag[i][9]){		//Handles leftward rooks
								bag[i][9] = 0-(rows[j].pieces[k][1]-bag[i][1]);	//Copies the absolute distance between the two into the bag.
								bag[i][8] = rows[j].pieces[k][0];				//Copies the ID of the hit.
							}
						}
					}
				}
				j=current_row; //Breaks the loop.
			}
		}
		for(j=0; j<=current_column; j++){					//Cycles through each column that was entered
			if(columns[j].level==bag[i][1]){				//Locks into the corrct column
				for(k=0;k<columns[j].size;k++){			//Cycles through rooks in the column to compare
					if(columns[j].pieces[k][0]!=i){		//Removes autocorrelation 
						if((columns[j].pieces[k][1]-bag[i][0])>0){				//If the piece is to the right, does x.  If left, does y.
							if((columns[j].pieces[k][1]-bag[i][0])<bag[i][3]){
								bag[i][3] = (columns[j].pieces[k][1]-bag[i][0]);	//Copies the absolute distance between the two into the bag.
								bag[i][2] = columns[j].pieces[k][0];				//Copies the ID of the hit.
							}
						} else {
							if((columns[j].pieces[k][1]-bag[i][0])>-bag[i][7]){		//Handles leftward rooks
								bag[i][7] = 0-(columns[j].pieces[k][1]-bag[i][0]);	//Copies the absolute distance between the two into the bag.
								bag[i][6] = columns[j].pieces[k][0];				//Copies the ID of the hit.
							}
						}
					}
				}
				j=current_column; //Breaks the loop.
			}
		}
	}
	
	for(i=0;i<n;i++){
		k=0;
		for(j=1;j<=4;j++){
			if(bag[i][2*j]!=MAX_SPOTS+1) k++;
		}
		printf("\n%d ", k);
		for(j=1;j<=4;j++){
			if(bag[i][2*j]!=MAX_SPOTS+1) printf("%d ", bag[i][2*j]+1);
		}
	}
	
	for(i=0;i<n;i++) free(bag[i]);
	free(bag);
	for(i=current_row; i>0; i--) Arrow_Delete(&rows[i]);						//Handles garbage.
	for(i=current_column; i>0; i--) Arrow_Delete(&columns[i]);						//Handles garbage.
	return 0;
}

void Arrow_New(arrow * arrow) {
	int i;
	(*arrow).size = 0;
	(*arrow).capacity = MIN_SIZE;
	(*arrow).pieces = malloc(MIN_SIZE*sizeof(int*));
	for(i = 0; i<MIN_SIZE;i++) (*arrow).pieces[i] = malloc(2*sizeof(int));
}
void Arrow_Delete(arrow * arrow) {
	int i;
	for(i=(*arrow).capacity-1;i>=0;i--){
		free((*arrow).pieces[i]);
	}
    free((*arrow).pieces);
}
void Arrow_Grow(arrow * arrow) {
	int i, newCapacity = 2*((*arrow).capacity), ** temp;
	temp = malloc(newCapacity*sizeof(int*));
	for(i = 0; i<newCapacity;i++) temp[i] = malloc(2*sizeof(int));
	
	for(i=0; i<(*arrow).capacity;i++) {
		temp[i][0] = (*arrow).pieces[i][0];
		temp[i][1] = (*arrow).pieces[i][1];
	}
	(*arrow).pieces = malloc(newCapacity*sizeof(int*));
	for(i = 0; i<newCapacity;i++) (*arrow).pieces[i] = malloc(2*sizeof(int));
	for(i = 0; i < (*arrow).capacity; i++){
		(*arrow).pieces[i][0]=temp[i][0];
		(*arrow).pieces[i][1]=temp[i][1];
	}
    (*arrow).capacity = newCapacity;
    free(temp);
}
void Arrow_AddPiece(arrow * arrow, int ID, int index, int level){
	if ((*arrow).size == (*arrow).capacity) Arrow_Grow(arrow);
    (*arrow).pieces[(*arrow).size][0] = ID;							//ID of the rook
    (*arrow).pieces[(*arrow).size][1] = index;						//Location along the arrow
    (*arrow).level = level;											//Location of the arrow
    (*arrow).size++;
}
int Target_Check(int r, int c, int target_size[2]){
	if(r<1||c<1) {
		printf("\nThe requested position (%d, %d) is not allowable.", r, c);
		return 1;
	}
	if(r>target_size[0]) target_size[0] = r;
	if(c>target_size[1]) target_size[1] = c;
	if(target_size[0]*target_size[1]>MAX_SPOTS) {
		printf("\nThe requested board size of (%d x %d) exceeds the accepted range.", target_size[0], target_size[1]);
		return 1;
	}
	return 0;
}
