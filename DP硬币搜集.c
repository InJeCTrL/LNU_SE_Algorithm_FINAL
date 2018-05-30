#include<stdio.h>
#include<windows.h>
int** CreateRndMap(int n)
{
	int i,j;
	int **tMap = NULL;
	srand(GetTickCount());
	tMap = (int**)malloc((n+1)*sizeof(int*));
	for (i=0;i<=n;i++)//0行不用
		tMap[i] = (int*)malloc((n+1)*sizeof(int));
	for (i=0;i<=n;i++)
		tMap[i][0] = tMap[0][i] = 0;
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			tMap[i][j] = rand()%2;
	return tMap;
}
int ShowMap(int **Map,int n)
{
	int i,j;
	printf("Map Matrix:\n");
	for (i=0;i<=n;i++,printf("\n"))
		for (j=0;j<=n;j++)
			printf("%d\t",Map[i][j]);
	return 0;
}
int** CreateDPMatrix(int **pMap,int n)
{
	int i,j;
	int **tDPMx = NULL;
	tDPMx = (int**)malloc((n+1)*sizeof(int*));
	for (i=0;i<=n;i++)
		tDPMx[i] = (int*)malloc((n+1)*sizeof(int));
	for (i=0;i<=n;i++)
		tDPMx[i][0] = tDPMx[0][i] = 0;
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			tDPMx[i][j] = max(tDPMx[i-1][j],tDPMx[i][j-1])+pMap[i][j];
	return tDPMx;
}
int ShowDPMatrix(int **pDPMatrix,int n)
{
	int i,j;
	printf("DP Matrix:\n");
	for (i=0;i<=n;i++,printf("\n"))
		for (j=0;j<=n;j++)
			printf("%d\t",pDPMatrix[i][j]);
	return 0;
}

int main(void)
{
	int n;//矩阵行列数
	int **pMap = NULL;//指向矩阵
	int **pDPMx = NULL;//指向DP矩阵
	scanf_s("%d",&n);
	pMap = CreateRndMap(n);//产生随机Map矩阵
	ShowMap(pMap,n);
	pDPMx = CreateDPMatrix(pMap,n);//生成DP矩阵
	ShowDPMatrix(pDPMx,n);
	printf("最大硬币数:%d\n",pDPMx[n][n]);
	system("pause");
	return 0;
}
