
#include<stdio.h>
#include<windows.h>
int** CreateMatrix(int n,int Min,int Max)
{
	int **tMatrix = NULL;
	int i;
	srand(GetTickCount());
	tMatrix = (int**)malloc(2*sizeof(int*));
	tMatrix[0] = (int*)malloc(n*sizeof(int));
	tMatrix[1] = (int*)malloc(n*sizeof(int));
	tMatrix[0][n-1] = Min;
	for (i=n-2;i>=0;i--)
		tMatrix[0][i] = rand()%((Max-Min+1)/n)+Min+tMatrix[0][i+1];
	for (i=0;i<n;i++)
		tMatrix[1][i] = 0;
	return tMatrix;
}
int ShowMatrix(int **pMatrix,int n)
{
	int i;
	printf("\t");
	for (i=0;i<n;i++)
		printf("%d\t",i);
	printf("\n");
	printf("Num:\t");
	for (i=0;i<n;i++)
		printf("%d\t",pMatrix[0][i]);
	printf("\n");
	printf("Sta:\t");
	for (i=0;i<n;i++)
		printf("%d\t",pMatrix[1][i]);
	printf("\n");
	return 0;
}
int Finish(int **pMatrix,int n)
{
	int i;
	for (i=0;i<n;i++)
		if (pMatrix[1][i]==0)
			return 0;
	return 1;
}
int INC(int *F,int n)
{
	int i=n-1;
	F[n-1] += 1;
	while (F[i] == 2)
	{
		F[i] %= 2;
		i--;
		F[i] += 1;
	}
	return 0;
}
int IsMatch(int **pMatrix,int n,int Targ)
{
	int i,tb=0;
	for(i=0;i<n;i++)
		tb += pMatrix[0][i]*pMatrix[1][i];
	if (tb == Targ)
		return 1;
	return 0;
}

int main(void)
{
	int Targ,n,Flag=0;
	int **pMatrix=NULL;//指向数组-状态矩阵
	printf("数组中所含数字个数，目标数字：\n");
	scanf_s("%d %d",&n,&Targ);
	pMatrix = CreateMatrix(n,1,20);//递减序生成n个1~20的数
	ShowMatrix(pMatrix,n);
	while (!Finish(pMatrix,n))
	{
		INC(pMatrix[1],n);
		if (IsMatch(pMatrix,n,Targ))
		{
			Flag = 1;
			printf("找到一种方案：\n");
			ShowMatrix(pMatrix,n);
		}
	}
	if (!Flag)
		printf("没有找到匹配方案\n");
	system("pause");
	return 0;
}