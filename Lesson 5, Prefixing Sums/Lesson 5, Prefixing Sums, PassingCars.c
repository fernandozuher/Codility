//O(N)
int solution(int A[], int N){
    
    unsigned int passing=0, zeros=0;
    for(int i=0; i<N; i++)
    	if(!A[i])
    		zeros++;
		else
			passing += zeros;
		
    return passing<=1000000000 ? passing : -1;
}

/*
//O(N^2)
int solution(int A[], int N){
    
    unsigned int passing=0;
    for(int i=0; i<N-1; i++)
    	if(!A[i])
    		for(int j=i; j<N; j++)
    			if(A[j])
    				passing++;
    
    return passing<=1000000000 ? passing : -1;
}
*/