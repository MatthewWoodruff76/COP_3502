void SelectionSort(long long int * val, int n);

void simpleSort(long long int * val, int n){
	int i, j, pos;
	long long int max, tempn;
	for(i=0;i<n;i++){
		pos = i;
		max = val[i];
		for(j=i;j<n;j++){
			if(val[j]>max) {
			max = val[j];
			pos = j;	
			}
		}
		tempn = val[pos];
		val[pos] = val[i];
		val[i] = tempn;
	}
}
