
#include<stdio.h>
#include<windows.h>

typedef struct Line
{
	int *BlockedList;//屏蔽的列列表
	int Row;//选定的列
}Line;
int AddBlockList(Line LineNode,int n)
{
	int *p = LineNode.BlockedList;
	while (*p!=NULL)
		p++;
	*p = n;
	*(p+1) = 0;
	return 0;
}
int OK(Line *pLineList,int i,int j,int n)
{
	int k,c;
	for (k=i,c=1;k>1;k--,c++)
		if ((j-c>=1)&&(pLineList[i-c].Row == j-c))
			return 0;
	for (k=i,c=1;k>1;k--,c++)
		if ((j+c<=n)&&(pLineList[i-c].Row == j+c))
			return 0;
	for (k=i-1;k>=1;k--)
		if (pLineList[k].Row == j)
			return 0;
	return 1;
}
int ClearBlockList(Line LineNode)
{
	LineNode.BlockedList[0] = 0;
	return 0;
}
int GetNextOKJ(Line *pLineList,int i,int n)
{
	int *t = pLineList[i].BlockedList;
	while (*t)
		t++;
	while ((*(t-1)+1)<=n && !OK(pLineList,i,*(t-1)+1,n))
	{
		*t = *(t-1)+1;
		*(t+1) = 0;
		t++;
	}
	return *(t-1)+1;
}

Line* QueenSolution(int n)
{//N皇后
	Line *pLineList = NULL;
	int i,j;
	pLineList = (Line*)malloc((n+1)*sizeof(Line));
	for (i=1;i<=n;i++)
	{
		pLineList[i].BlockedList = (int*)malloc(n*sizeof(int));
		pLineList[i].BlockedList[0] = 0;
		pLineList[i].Row = 0;
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			AddBlockList(pLineList[i],j);
			if (OK(pLineList,i,j,n))
			{
				pLineList[i].Row = j;
				break;
			}
		}
		while (j>n)
		{
			ClearBlockList(pLineList[i]);
			i--;
			j = GetNextOKJ(pLineList,i,n);
			if (j<=n)
				AddBlockList(pLineList[i],j);
		}
		pLineList[i].Row = j;
	}
	return pLineList;
}

int main(void)
{
	int n,i,j,tBegin,tEnd;
	Line *pLineList = NULL;
	scanf_s("%d",&n);
	tBegin = GetTickCount();
	pLineList = QueenSolution(n);
	tEnd = GetTickCount();
	for (i=1;i<=n;i++)
	{
		for (j=0;j<pLineList[i].Row-1;j++)
			printf("□");
		printf("■");
		for (j=0;j<n-pLineList[i].Row;j++)
			printf("□");
		printf("\n");
	}
	printf("%d ms\n",tEnd-tBegin);
	system("pause");
	return 0;
}