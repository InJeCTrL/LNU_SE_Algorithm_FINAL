#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int n,i,j;
	int tx,ty,tx2,ty2;
	int **pMatrix = NULL;
	scanf_s("%d",&n);
	pMatrix = (int**)malloc(n*sizeof(int*));
	for (i=0;i<n;i++)
	{
		pMatrix[i] = (int*)malloc(n*sizeof(int));
		for (j=0;j<n;j++)
			pMatrix[i][j] = 0;
	}
	pMatrix[0][n/2] = 1;
	i = 2;
	tx = 0;
	ty = n/2;
	while (i<=n*n)
	{
		tx2 = tx-1;
		ty2 = ty-1;
		if (tx2<0)
			tx2 = n-1;
		if (ty2<0)
			ty2 = n-1;
		if (pMatrix[tx2][ty2])
		{
			tx2 = tx+1;
			ty2 = ty;
		}
		tx = tx2;
		ty = ty2;
		pMatrix[tx2][ty2] = i++;
	}
	for (i=0;i<n;i++,printf("\n"))
		for (j=0;j<n;j++)
			printf("%4d",pMatrix[i][j]);
	system("pause");
	return 0;
}
