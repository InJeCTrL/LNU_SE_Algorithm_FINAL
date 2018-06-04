#include<stdio.h>
#include<windows.h>
int* CreateNumList(int n,int Begin,int End)
{
	int *tList = NULL;
	int i;
	srand(GetTickCount());
	tList = (int*)malloc(n*sizeof(int));
	for (i=0;i<n;i++)
		tList[i] = rand()%(End-Begin+1)+Begin;
	return tList;
}
int **CreateMatrix(int n,int *pList)
{
	int **pMatrix = NULL;
	int i,j,k=0;
	pMatrix = (int**)malloc(n*sizeof(int*));
	for (i=0;i<n;i++)
		pMatrix[i] = (int*)malloc(n*sizeof(int));
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			pMatrix[i][j] = pList[(i+k++)%n];
		}
		k = k+n-2;
	}
	return pMatrix;
}

int main(void)
{
	int n;//输入n个数
	int i,j;
	int *pList = NULL;//指向生成的一位数组列表
	int **pMatrix = NULL;//指向生成的矩阵
	scanf_s("%d",&n);
	pList = CreateNumList(n,1,20);
	pMatrix = CreateMatrix(n,pList);
	for (i=0;i<n;i++,printf("\n"))
		for (j=0;j<n;j++)
			printf("%5d",pMatrix[i][j]);
	system("pause");
	return 0;
}
