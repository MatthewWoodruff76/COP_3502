#include <stdio.h>
#include <stdlib.h>

int search(int min, int max, int * pricePerNights, int N);

int main(){
	int prices[11] = {1, 2, 3, 4, 5, 5, 5, 8, 9, 10, 11};
	printf("%d ", search(0,10,prices,9));
	return 0;
}

int search(int start, int end, int * arr, int target) {
   int mid = (start + end) / 2;
   if (target < arr[mid]) {
      return search(start, mid - 1, arr, target);
   }
   if (arr[mid] == target) {
   	printf("%d found!\n", mid);
      return 1;
   }
   return search(mid + 1, end, arr, target);
}
