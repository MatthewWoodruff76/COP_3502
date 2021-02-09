//Simple for-loop for proving the number of iterations run.
#include <stdio.h>


int main(){
	
	int i, j, a = 9, n = 1, sum = 0;
	for(i=0;i<a;i++){
		for(j=0;j<i;j++) sum+=n;
	}
	printf("%d", sum);
	return 0;
}
