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
int InsertSort(int *pList,int maxp,int R)
{
	int i,t;
	if (R<maxp)
	{
		i = R;
		t = pList[i+1];
		while (i>=0 && pList[i]>t)
			pList[i+1] = pList[i--];
		pList[i+1] = t;
		InsertSort(pList,maxp,R+1);
	}
	return 0;
}

int main(void)
{
	int n;//共n个数
	int *pList = NULL;//指向生成的随机数数字
	scanf_s("%d",&n);
	pList = CreateList(n,0,20);//生成随机数数组(0~20)
	OutputList(pList,n);
	InsertSort(pList,n-1,0);//初始有序最后一元素的下标为0,数组下标最大为n-1
	OutputList(pList,n);
	system("pause");
	return 0;
}