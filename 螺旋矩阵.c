#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int n;//n阶矩阵
	int j,i,tx=0,ty=0;//初始计数值，初始下标
	int dsta=0;//初始方向向下，{0,1,2,3}向下、向右、向上、向左
	int **pMatrix = NULL;
	scanf_s("%d",&n);
	pMatrix = (int**)malloc(n*sizeof(int*));
	for (i=0;i<n;i++)
	{
		pMatrix[i] = (int*)malloc(n*sizeof(int));
		for (j=0;j<n;j++)
			pMatrix[i][j] = 0;
	}
	i = 1;
	while (i<=n*n)
	{
		pMatrix[tx][ty] = i++;
		switch (dsta)
		{
		case 0:
			if (tx == n-1 || pMatrix[tx+1][ty])
			{
				dsta = (dsta+1)%4;
				ty++;
			}
			else
				tx++;
			break;
		case 1:
			if (ty == n-1 || pMatrix[tx][ty+1])
			{
				dsta = (dsta+1)%4;
				tx--;
			}
			else
				ty++;
			break;
		case 2:
			if (tx == 0 || pMatrix[tx-1][ty])
			{
				dsta = (dsta+1)%4;
				ty--;
			}
			else
				tx--;
			break;
		case 3:
			if (ty == 0 || pMatrix[tx][ty-1])
			{
				dsta = (dsta+1)%4;
				tx++;
			}
			else
				ty--;
			break;
		}
	}
	for(i=0;i<n;i++,printf("\n"))
		for (j=0;j<n;j++)
			printf("%3d",pMatrix[i][j]);
	system("pause");
	return 0;
}
