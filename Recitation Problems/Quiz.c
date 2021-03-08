#include <string.h>
#include <stdio.h>

//This block is entirely unaltered from the quiz
typedef struct person person;
typedef struct likeable_person likeable_person;

struct likeable_person {
   char name[20 + 1];
};

struct person {
   char name[20 + 1];
   likeable_person liked;
   likeable_person disliked;
};
//End of block

int main(){
	
	struct likeable_person dave;
	strcpy(dave.name,"dave");
	struct likeable_person sam;
	strcpy(sam.name,"sam");
	struct person greg;
	strcpy(greg.name,"greg");
	greg.liked = dave;
	greg.disliked = sam;
	printf("%s likes %s\n", greg.name, (greg.liked).name);
	printf("%s dislikes %s\n", greg.name, (greg.disliked).name);
	return 0;
}
