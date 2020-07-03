/*
Author: Fernando Zuher
Place: Brazil
Date: 03 July 2020
About: codility.com -> Lesson 6, Sorting -> Distinct

I solved this problem in the languages:
    C, C++, Java, Python and JavaScript. ;-)
*/

int solution(int A[], int N){

	if(N==0)
		return 0;
	if(N==1)
		return 1;

	int temp[N], count = 1;
	char igual;
	temp[0] = A[0];
	
	for(int i = 1; i < N; ++i){
		igual = 'n';
		for(int j = 0; j < count; ++j)
			if(temp[j] == A[i]){
				igual='s';
				break;
			}

		if(igual=='n')
			temp[count++] = A[i];
	}
	return count;
}
