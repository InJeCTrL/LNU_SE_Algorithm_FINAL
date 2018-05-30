//只有三个公司
#include<stdio.h>
#include<windows.h>
int** CreateMatrix(int n,int MaxDelta)
{
	int i,j;
	int **tList = NULL;
	srand(GetTickCount());
	tList = (int**)malloc(3*sizeof(int*));
	for (i=0;i<n;i++)
	{
		tList[i] = (int*)malloc((n+1)*sizeof(int));
		tList[i][0] = 0;
	}
	for (i=0;i<3;i++)
		for (j=1;j<=n;j++)
			tList[i][j] = tList[i][j-1] + rand()%MaxDelta+1;
	return tList;
}
int ShowMatrix(int **pMatrix,int n)
{
	int i;
	printf("Rs Set:\n");
	printf("\t");
	for (i=1;i<=n;i++)
		printf("%d\t",i);
	printf("\n");
	printf("A\t");
	for (i=1;i<=n;i++)
		printf("%d\t",pMatrix[0][i]);
	printf("\nB\t");
	for (i=1;i<=n;i++)
		printf("%d\t",pMatrix[1][i]);
	printf("\nC\t");
	for (i=1;i<=n;i++)
		printf("%d\t",pMatrix[2][i]);
	return 0;
}
int** CreateDPAB(int **pMatrix,int n)
{
	int i,j;
	int **tMatrix = NULL;
	tMatrix = (int**)malloc((n+1)*sizeof(int*));//生成行(标记总投资额)
	for (i=1;i<=n;i++)
	{
		tMatrix[i] = (int*)malloc((n+2)*sizeof(int));//生成列(标记A公司投资额)，最后一列标记当前投资总额的最大利润
		tMatrix[i][n+1] = 0;
		for (j=0;j<=i;j++)
		{
			tMatrix[i][j] = pMatrix[0][j]+pMatrix[1][i-j];
			if (tMatrix[i][j]>tMatrix[i][n+1])
				tMatrix[i][n+1] = tMatrix[i][j];
		}		
	}
	return tMatrix;
}
int** CreateDPABC(int **pMatrix,int **pDP1,int n)
{
	int i,j;
	int **tMatrix = NULL;
	tMatrix = (int**)malloc((n+1)*sizeof(int*));//生成行(标记总投资额)
	for (i=1;i<=n;i++)
	{
		tMatrix[i] = (int*)malloc((n+2)*sizeof(int));//生成列(标记AB公司投资额)，最后一列标记当前投资总额的最大利润
		tMatrix[i][n+1] = 0;
		for (j=0;j<=i;j++)
		{
			if (j==0)
				tMatrix[i][0] = pMatrix[2][i];
			else
				tMatrix[i][j] = pDP1[j][n+1]+pMatrix[2][i-j];
			if (tMatrix[i][j]>tMatrix[i][n+1])
				tMatrix[i][n+1] = tMatrix[i][j];
		}		
	}
	return tMatrix;
}
int ShowDP1(int **pDP,int n)
{
	int i,j;
	printf("\nDP1 Matrix:\n");
	printf("Total-A\t");
	for (i=0;i<=n;i++)
		printf("%d\t",i);
	printf("Max\n");
	for (i=1;i<=n;i++)
	{
		printf("%d\t",i);
		for (j=0;j<=i;j++)
			printf("%d\t",pDP[i][j]);
		for (;j<=n;j++)
			printf("\t");
		printf("%d\n",pDP[i][n+1]);
	}
	return 0;
}
int ShowDP2(int **pDP,int n)
{
	int i,j;
	printf("\nDP2 Matrix:\n");
	printf("Tot-AB\t");
	for (i=0;i<=n;i++)
		printf("%d\t",i);
	printf("Max\n");
	for (i=1;i<=n;i++)
	{
		printf("%d\t",i);
		for (j=0;j<=i;j++)
			printf("%d\t",pDP[i][j]);
		for (;j<=n;j++)
			printf("\t");
		printf("%d\n",pDP[i][n+1]);
	}
	return 0;
}
int main(void)
{
	int n;//资金总数
	int **pMatrix;//指向资源配置
	int **pDPList1,**pDPList2;//指向DP列表
	scanf_s("%d",&n);
	pMatrix = CreateMatrix(n,3);//生成资源分配矩阵(3公司，最小增量1，最大增量3)
	ShowMatrix(pMatrix,n);
	pDPList1 = CreateDPAB(pMatrix,n);//生成DP1,算AB公司
	ShowDP1(pDPList1,n);
	pDPList2 = CreateDPABC(pMatrix,pDPList1,n);
	ShowDP2(pDPList2,n);
	printf("最大利润:%d\n",pDPList2[n][n+1]);
	system("pause");
	return 0;
}