#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fav fav;

struct fav{
	char name[100];
	struct fav *dislikes;
	struct fav *likes;
	struct fav **liked[10];
};
struct fav newFav(struct fav fav){
	strcpy(fav.name,"Yes");
	fav.dislikes = NULL;
	fav.likes = NULL;
	int i;
	for(i=0;i<10;i++){
		fav.liked[i] = NULL;
	}
	return fav;
}

int main(){
	struct fav friends[10];
	struct fav greg;
	friends[0] = newFav(greg);
	struct fav steve;
	friends[1] = steve = newFav(steve);
	struct fav matt;
	friends[2] = newFav(matt);
	friends[2].likes = &matt;
	friends[1].likes = &greg;
	strcpy(friends[1].name,"You did it!");
	printf("%s", friends[0].name);
	printf("\n%s", friends[2].likes->name);//Having issues here.
	return 0;
}


