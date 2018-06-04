#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int n;//共n阶
	int i,j;
	int **pMatrix = NULL;
	scanf_s("%d",&n);
	pMatrix = (int**)malloc(n*sizeof(int*));
	for (i=0;i<n;i++)
	{
		pMatrix[i] = (int*)malloc(n*sizeof(int));
		pMatrix[i][i] = pMatrix[i][n-i-1] = 0;
	}
	for (i=n-1;i>n/2;i--)
		for (j=i-1;j+i>=n;j--)
		{
			pMatrix[i][j] = 3;
			pMatrix[j][i] = 4;
		}
	for (i=0;i<n/2;i++)
		for (j=i+1;j+i<n-1;j++)
		{
			pMatrix[i][j] = 1;
			pMatrix[j][i] = 2;
		}
	for (i=0;i<n;i++,printf("\n"))
		for (j=0;j<n;j++)
			printf("%3d",pMatrix[i][j]);
	system("pause");
	return 0;
}
