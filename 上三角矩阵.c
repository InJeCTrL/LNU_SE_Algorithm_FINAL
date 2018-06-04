#include<stdio.h>
#include<stdlib.h>
int **CreateMatrix(int n)
{
	int **pMatrix = NULL;
	int i,j,k=1;
	pMatrix = (int**)malloc(n*sizeof(int*));
	for (i=0;i<n;i++)
		pMatrix[i] = (int*)malloc(n*sizeof(int));
	for (i=0;i<n;i++)
	{
		for (j=0;j<=i;j++)
			pMatrix[i-j][j] = k++;
	}
	return pMatrix;
}

int main(void)
{
	int n;//输入n个数
	int i,j;
	int **pMatrix = NULL;//指向生成的矩阵
	scanf_s("%d",&n);
	pMatrix = CreateMatrix(n);
	for (i=0;i<n;i++,printf("\n"))
		for (j=0;j<n-i;j++)
			printf("%5d",pMatrix[i][j]);
	system("pause");
	return 0;
}
