#include<malloc.h>
int NotFinish(char *F,int r)
{//判断未结束
	int i;
	for (i=0;i<r;i++)
	{
		if (F[i]==0)	return 1;
	}
	return 0;
}
int NotOK(char *F,int n,int r)
{
	int i,k=0;
	for(i=0;i<n;i++)
	{
		if (F[i])	k++;
	}
	if (k==r)	return 0;
	return 1;
}
void INC(char *F,int n)
{
	int i=n-1;
	F[n-1] += 1;
	while (F[i] == 2)
	{
		F[i] %= 2;
		i--;
		F[i] += 1;
	}
}
void GetNextNum(char *F,int n,int r)
{
	do
		INC(F,n);
	while(NotOK(F,n,r));
}
void OutPutComb(char *F,int *numl,int n)
{
	int i;
	for (i=0;i<n;i++)
	{
		if (F[i]==1)
			printf("%d,",numl[i]);
	}
	printf("\n");
}
int main()
{//从n个不同的任意数中，取出r个数的组合。要求：n、n个数及r均从键盘输入。
	int *numlist=NULL;
	char *Flag=NULL;
	int i,r,n;
	scanf("%d %d",&n,&r);
	numlist = (int*)malloc(n*sizeof(int));
	Flag = (char*)malloc(n*sizeof(char));
	for (i=0;i<n;i++)
		scanf("%d",&numlist[i]);
	for (i=0;i<n;i++)
		Flag[i] = 0;
	for (i=n-1;i>=n-r;i--)
		Flag[i] = 1;
	OutPutComb(Flag,numlist,n);
	while(NotFinish(Flag,r))
	{
		GetNextNum(Flag,n,r);
		OutPutComb(Flag,numlist,n);
	}
	system("pause");
}