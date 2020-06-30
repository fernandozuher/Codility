int solution(int A[], int N){

	int iMin=0, temp[N];
	float minMedia = 20000;

	for(int i=0; i<N-1; i++)
		temp[i] = 0;

	temp[0] = A[0];
	for(int q=1; q<N; q++){
		temp[q] = A[q];
		for(int p=0; p<q; p++){
			temp[p] += A[q];

			if( (temp[p]/(float)(q-p+1)) < minMedia ){
				minMedia = (temp[p]/(float)(q-p+1));
				iMin = p;
			}
		}
	}
	return iMin;
}