#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct book_T book_T;
typedef struct author_t author_t;

struct author_t{
	char name[20];
	int birthYear;
	int publishings;
};
struct book_T{
	char name[20];
	int year;
	int numAuthors;
	author_t * authors;
};

int main(){
	
	int i, j, n;
	printf("Enter the number of books to catalog: ");
	scanf("%d", &n);
	book_T * bookArr;
	bookArr = (book_T *) calloc(n, sizeof(book_T));
 for(i=0; i<n; i++){
	scanf("%s", bookArr[i].name);
	scanf("%d", bookArr[i].year);
	scanf("%d", bookArr[i].numAuthors);
	bookArr[i].authors = (author_t *) calloc(bookArr[i].numAuthors, sizeof(author_t));
	for (j = 0; j < bookArr[i].numAuthors; j++) {

		scanf("%s", bookArr[i].authors[j].name);
	  scanf("%d", &bookArr[i].authors[j].birthYear);
	  scanf("%d", &bookArr[i].authors[j].publishings);
	}
}
	
	return 0;
}

//read input: First line stores the number of books in the collection
//Then it loops through each book
//for each book it stores 1-19 character titles,
//the year
//the number of authors
//then info on each athor


