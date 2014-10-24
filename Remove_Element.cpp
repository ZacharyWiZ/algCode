class Solutoin {
public:
	int removeElement(int A[], int n, int elem) {
		int flag=0, len;
		int *A_new;
		for(int i=0; i<n; i++){
			if(A[i]==elem)
				flag++;
			else A[i-flag]=A[i];
		}
		len=n-flag;
		A_new=(int*)malloc(len*sizeof(int));
		for(int i=0; i<len; i++){
			A_new[i]=A[i];
		}
		A=A_new;
		return len;
	}
}