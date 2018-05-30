#include<iostream>
#include<windows.h>
#include<queue>
using namespace std;
typedef struct Node
{
	int v;
	int pre;
	int count;
}Node;
int** CreateMap(int n)
{//0通，1不通
	int **tMap = NULL;
	int i,j;
	srand(GetTickCount());
	tMap = (int**)malloc(n*sizeof(int*));
	for (i=0;i<n;i++)
	{
		tMap[i] = (int*)malloc(n*sizeof(int));
		for (j=0;j<n;j++)
			tMap[i][j] = 0;
	}
	for (i=0;i<n;i++)
		for (j=i+1;j<n;j++)
			tMap[i][j] = rand()%2;
	return tMap;
}
int ShowMap(int **pMap,int n)
{
	int i,j;
	printf("    ");
	for (i=0;i<n;i++)
		printf("%3d",i);
	printf("\n");
	for (i=0;i<n;i++)
	{
		printf("%4d",i);
		for (j=0;j<n;j++)
			printf("%3d",pMap[i][j]);
		printf("\n");
	}
	return 0;
}
int GetMinRt(int **pMap,int n,int a,int b)
{
	int i,count=0;
	queue<Node> q;
	Node tNode,preNode;
	int *Status=NULL;//下标是否进过队列
	Status = (int*)malloc(n*sizeof(int));
	for (i=0;i<n;i++)
		Status[i] = 0;
	preNode.v = a;
	preNode.pre = 0;
	preNode.count = 0;
	q.push(preNode);
	Status[a] = 1;
	do
	{
		preNode = q.front();
		q.pop();
		for (i=0;i<n;i++)
			if (pMap[preNode.v][i]&&!Status[i])
			{
				tNode.pre = preNode.v;
				tNode.v = i;
				tNode.count = preNode.count+1;
				if (i==b)
					return tNode.count;
				q.push(tNode);
				Status[i] = 1;
			}
	}while (q.empty()==false);
	return 0;
}
int main(void)
{
	int n;//共n个结点
	int a,b;//记录即止点序号
	int RtC;
	int **pMap = NULL;//指向地图矩阵
	scanf_s("%d",&n);
	pMap = CreateMap(n);//生成n阶地图矩阵
	ShowMap(pMap,n);
	scanf_s("%d %d",&a,&b);
	if (RtC=GetMinRt(pMap,n,a,b))
		printf("%d\n",RtC);
	else
		printf("无法到达\n");
	system("pause");
	return 0;
}
