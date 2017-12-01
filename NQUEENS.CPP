//	Nqueens solution

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define	N	8

int X[N+1] = {0};

int place(int);

void main(void)
{
	int k, i, t=0;

	k = 1;
	X[1] = 0;

	while(k > 0) {

		X[k]++;

		while(X[k] <= N && !(place(k))) X[k]++;

		if(X[k] <= N) {
			if(k == N) {
				t++;
				for(i=1; i<=N; i++) printf("%d ",X[i]);
				puts("\n");
			}
			else {
				k++; X[k] = 0;
			}
		}
		else k--;
	}

	printf("\n\nTotal solutions %d", t);

	getch();
}

int place(int k)
{
	int i;

	for(i=1; i<k; i++)
		if((X[i] == X[k]) || (abs(X[i]-X[k]) == abs(i-k)))
			return 0;

	return 1;
}