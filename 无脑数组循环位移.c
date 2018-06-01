#include<stdio.h>
#include<windows.h>
int* CreateList(int n,int Start,int End)
{
	int *tList = NULL;
	int i;
	srand(GetTickCount());
	tList = (int*)malloc(n*sizeof(int));
	for (i=0;i<n;i++)
		tList[i] = rand()%(End-Start+1)+Start;
	return tList;
}
int OutputList(int *pList,int n)
{
	int i;
	for (i=0;i<n;i++)
		printf("%d ",pList[i]);
	printf("\n");
	return 0;
}
int RHX(int *pList,int t,int n)
{
	int *tList = NULL;
	int i;
	tList = (int*)malloc(n*sizeof(int));
	for (i=0;i<n;i++)
		tList[(i+t)%n] = pList[i];
	for (i=0;i<n;i++)
		pList[i] = tList[i];
	return 0;
}

int main(void)
{
	int n;//共n个数
	int t;//移动t次
	int *pList = NULL;//指向生成的随机数数字
	scanf_s("%d",&n);
	pList = CreateList(n,0,20);//生成随机数数组(0~20)
	OutputList(pList,n);
	scanf_s("%d",&t);
	RHX(pList,t,n);//循环移动t
	OutputList(pList,n);
	system("pause");
	return 0;
}