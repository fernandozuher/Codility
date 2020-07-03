/*
Author: Fernando Zuher
Place: Brazil
Date: 03 July 2020
About: codility.com -> Lesson 6, Sorting -> MaxProductOfThree

I solved this problem in the languages:
    C, C++, Java, Python and JavaScript. ;-)
*/

int solution(int A[], int N){

	if(N==3)
		return A[0]*A[1]*A[2];

	int triple[6] = {A[0], A[1], A[2]};
	
	for(int i=0; i<2; i++)
		for(int j=0; j<2-i; j++)
			if(abs(triple[j])<abs(triple[j+1]){
				temp = triple[j+1];
				triple[j+1] = triple[j];
				triple[j] = temp;
			}

	for(int i=3; i<N; i++)
		for(int j=0; j<6; j++)
			if(abs(A[i])>triple[j]){
				for(int k=5; k>j; k--)
					triple[k] = triple[k-1];
				triple[j] = A[i];
				break;
			}

	int menos[6], mais[6], menosN=0, maisN=0;
	int temp = (N-6)<=0 ? N : 6;

	for(int i=0; i<temp; i++)
		if(triple[i]<0)
			menos[menosN++];
		else
			mais[maisN++];

	int menosR, menosMais, maisR;

	if(menos==3)
		menosR = A[menos[0]] * A[menos[1]] * A[menos[2]];
	else if(menos==2)
		menosMais = A[menos[0]] * A[menos[1]] * A[mais[0]];
	else if(menos<=1)
		maisR = A[mais[0]] * A[mais[1]] * A[mais[2]];

	if(menosR>menosMais && menosR>maisR)
		return menosR;
	if(menosMais>menosR && menosMais>maisR)
		return menosMais;
	return maisR;
}
