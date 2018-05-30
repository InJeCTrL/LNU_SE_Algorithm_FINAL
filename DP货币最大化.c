
#include<stdio.h>
#include<windows.h>
int* CreateCoinList(int n,int Start,int End)
{
	int i;
	int *tList = NULL;
	srand(GetTickCount());
	tList = (int*)malloc((n+1)*sizeof(int));
	for (i=1;i<=n;i++)
		tList[i] = rand()%(End-Start+1)+Start;
	tList[0] = 0;
	return tList;
}
int ShowCoinList(int *pList,int n)
{
	int i;
	printf("Coin List:\n");
	for (i=0;i<=n;i++)
		printf("%d\t",pList[i]);
	printf("\n");
	return 0;
}
int* CreateDPList(int *pList,int n)
{
	int i;
	int *tList = NULL;
	tList = (int*)malloc((n+1)*sizeof(int));
	tList[0] = 0;
	tList[1] = pList[1];
	for (i=2;i<=n;i++)
		tList[i] = max(tList[i-2]+pList[i],pList[i-1]);
	return tList;
}
int ShowDPList(int *pDPList,int n)
{
	int i;
	printf("DP List:\n");
	for (i=0;i<=n;i++)
		printf("%d\t",pDPList[i]);
	printf("\n");
	return 0;
}

int main(void)
{
	int n;//硬币总数
	int *pList;//指向硬币列表
	int *pDPList;//指向DP列表
	scanf_s("%d",&n);
	pList = CreateCoinList(n,1,10);//生成硬币列表(1~10)
	ShowCoinList(pList,n);
	pDPList = CreateDPList(pList,n);//生成DP列表
	ShowDPList(pDPList,n);
	printf("最大币值:%d\n",pDPList[n]);
	system("pause");
	return 0;
}
