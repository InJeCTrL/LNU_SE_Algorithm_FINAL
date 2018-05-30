#include<stdio.h>
#include<stdlib.h>
void INC(int *F,int n)
{
	int i=1;
	F[n-1]++;
	while(F[n-i]/n)
	{
		F[n-i] %= n;
		i++;
		F[n-i]++;
	}
}
int isOk(int *F,int n)
{
	int i;
	int *temp = NULL;
	temp = (int*)malloc(n*sizeof(int));
	for (i=0;i<n;i++)
		temp[i] = 0;
	for (i=0;i<n;i++)
		temp[F[i]] = 1;
	for (i=0;i<n;i++)
		if (temp[i] == 0)	return 0;
	return 1;
}
void GetNext(int *F,int n)
{
	do
	{
		INC(F,n);
	}while(isOk(F,n) == 0);
}
int Calc(int **Matrix,int *F,int n)
{
	int i,tTotal=0;
	for (i=0;i<n-1;i++)//F[0]=0	F[1]=2	F[2]=1
		if (F[i]<F[i+1])
			tTotal += Matrix[F[i]][F[i+1]];
		else
			tTotal += Matrix[F[i+1]][F[i]];
	tTotal += Matrix[F[0]][F[i]];
	return tTotal;
}
void Cpy(int *dest,int *src,int n)
{
	int i;
	for (i=0;i<n;i++)
		dest[i] = src[i];
}
int main(void)
{
	int *MinF = NULL;
	int *F=NULL,**p=NULL;
	int Begin,i,j,n,tmin,MinT=INT_MAX;
	printf("共n个点，n=");
	scanf_s("%d",&n);
	p = (int**)malloc(n*sizeof(int*));
	MinF = (int*)malloc(n*sizeof(int));
	F = (int*)malloc(n*sizeof(int));
	for (i=0;i<n;i++)
	{
		F[i] = i;
		p[i] = (int*)malloc(n*sizeof(int));
	}
	for (i=0;i<n;i++)
	{
		for (j=i+1;j<n;j++)
		{
			printf("D:%d--%d：\n",i,j);
			scanf_s("%d",&p[i][j]);
		}
	}
	printf("起止点Begin=：\n");
	scanf_s("%d",&Begin);
	while(F[0]<Begin)
		GetNext(F,n);
	while(F[0] == Begin)
	{
		if ((tmin=Calc(p,F,n))<MinT)
		{
			MinT = tmin;
			Cpy(MinF,F,n);
		}
		GetNext(F,n);
	}
	printf("最短路程： %d \n",MinT);
	printf("路径：");
	for (i=0;i<n;i++)
		printf("%d ",MinF[i]);
	printf("%d\n",Begin);
	system("pause");
}