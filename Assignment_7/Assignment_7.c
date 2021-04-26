#include <stdio.h>
#include <stdlib.h>

int **grid, **rows, **cols, r, c; //Global variables

void lineInput(int * line, int size){
	int j, gb;
	scanf("%d", &gb);
	for(j=0;j<gb;j++) scanf("%d", &line[j]);
	for(j=gb;j<size;j++) line[j] = -1; //Adds empty markers
}

void printSolution(){
	int i, j;
	for(i=0;i<r;i++){ //Test prints
		for(j=0;j<c;j++) {
			if(grid[i][j]) printf("B");
			else printf("r");
		}
		printf("\n");
	}
}

int fill(int rr, int cc){
	if(cc==c) {							//Wrap from end of row.
		rr++;
		cc=0;
	}	
	if(rr==r) return 1; 				//Victory
 	grid[rr][cc] = 1; //Try B;
 	if(validate(rr,cc)==1) {
 		if(fill(rr,cc+1)==1) return 1;
	 }
	grid[rr][cc] = 0; //Try R;
 	if(validate(rr,cc)==1) {
 		if(fill(rr,cc+1)==1) return 1;
	 }
	grid[rr][cc] = -1; //Bad tree.
	return 0;
}

int validate(int rr, int cc){
	int i, j, k, sB = 0, pB = 0, iB = 0;

		//Check the row
		k = 0;			//block array index
		for(j=0;j<c;j++){ //Loop through the row
			if(sB == 0) {
				sB = rows[rr][k];
				k++;
				if(j>0) pB = 1; //Marks that the previous location was the termination of a block
				iB = 0; //Turns off the in-block mark
			}
			if(sB==-1&&grid[rr][j]==1) return 0; //Invalid grid with too many entries
			if(pB==1&&grid[rr][j]==1) return 0; //Invalid grid with neighboring blocks (too long)
			if(grid[rr][j]==1) {
				sB--;	//Removes 1 from the current block count.
				iB=1; 	//Forces the in-block mark on.
			}
			if(grid[rr][j]==0&&iB==1) return 0; //Invalid block length (too short)
			pB=0; //Resets the block warning
		}
	
		//Check the column
		k = 0;			//block array index
		sB = 0;
		pB = 0;
		iB = 0;
		for(i=0;i<r;i++){ //Loop through the col
			if(sB == 0) {
				sB = cols[cc][k];
				k++;
				if(i>0) pB = 1; //Marks that the previous location was the termination of a block
				iB = 0; //Turns off the in-block mark
			}
			if(sB==-1&&grid[i][cc]==1) return 0; //Invalid grid with too many entries
			if(pB==1&&grid[i][cc]==1) return 0; //Invalid grid with neighboring blocks (too long)
			if(grid[i][cc]==1) {
				sB--;	//Removes 1 from the current block count.
				iB=1; 	//Forces the in-block mark on.
			}
			if(grid[i][cc]==0&&iB==1) return 0; //Invalid block length (too short)
			pB=0; //Resets the block warning
	}
	
	return 1; //Valid!
}

int main(){
	int i, j;
	scanf("%d %d", &r, &c);
	
	grid = calloc(r,sizeof(int *));
	for(i=0;i<r;i++){
		grid[i] = calloc(c,sizeof(int));
		for(j=0;j<c;j++)	 grid[i][j] = -1;
	}

	
	rows = calloc(r,sizeof(int *));
	for(i=0;i<r;i++) 	{
		rows[i] = calloc(c+1,sizeof(int));
		lineInput(rows[i],c+1);
	}
	
	cols = calloc(c,sizeof(int *));
	for(i=0;i<c;i++){
		cols[i] = calloc(r+1,sizeof(int));	
		lineInput(cols[i],r+1);
	}
	

	
	fill(0,0);

	printSolution();
	
	//Garbage handling
	for(i=0;i<r;i++) 	free(rows[i]);
	free(rows);
	for(i=0;i<c;i++) 	free(cols[i]);
	free(cols);
	for(i=0;i<r;i++)	free(grid[i]);
	free(grid);
	
	return 0;
}
