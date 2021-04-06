#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node{
	int value, skill;
	Node* r;
	Node* l;
};

Node * createNode(int value) {	//Basic node creator
    Node * ret;
	ret = (Node*)malloc(sizeof(Node));
    ret->value = value;
    ret->skill = 0;
    ret->r = ret->l = NULL;
    return ret;
}

Node * insert(Node * root, int value) { //Adds branch nodes

    if (root == NULL) return createNode(value); //Base Case
    
    if (root->value < value) root->r = insert(root->r, value); //Right
    
    else root->l = insert(root->l, value); //Left
    
    return root;
}

int leaf(Node * root, int * b, int i) { //Adds leaf nodes (contestors)
    if(root->l != NULL){
        i = leaf(root->l,b,i);
    }
    else {
		root->l = createNode(0);
		root->l->skill = b[i];
		i++;
	}
    if(root->r != NULL){
    	i = leaf(root->r,b,i);
	}
	else{
		root->r = createNode(0);
		root->r->skill = b[i];
		i++;
	}
	return i;
}

Node * findNode(Node * root, int value){
	if(root->value<value) return findNode(root->r,value);
	if(root->value>value) return findNode(root->l,value);
	return root;
}

int main(){
	Node * root = NULL; //Create a bracket
	int i, n, fun = 0; //Fun saves the excitement
	scanf("%d", &n);
	int a[n-1], b[n];
	for(i=0; i<n-1; i++) scanf("%d", &a[i]); //Read in branches
	for(i=0; i<n; i++)   scanf("%d", &b[i]); //Read in leafs
	
	for(i=n-2;i>=0;i--) root = insert(root, a[i]); //Make a post-order BST of the branches
	leaf(root,b,0); //Add leafs to branches
	Node * fight; //Create an arena
	
	for(i=0;i<n-1;i++){
		fight = findNode(root,a[i]); //Find the desired node using recursion.
		if(fight->l->skill>fight->r->skill){ //If the leftward wins, they advance.
			fun+=fight->l->skill-fight->r->skill;
			fight->skill = fight->l->skill;
		}
		else { //If the rightward wins, they advance.
			fun+=fight->r->skill-fight->l->skill;
			fight->skill = fight->r->skill;
		}
		//Garbage handling
		free(fight->r);
		free(fight->l);
		fight->r = NULL;
		fight->l = NULL;
	}
	free(root);
	
	printf("%d", fun);
	return 0;
}
