
#include<stdio.h>
#include<windows.h>
int** CreateItemList(int n,int LowW,int HighW,int LowV,int HighV)
{
	int **tItems = NULL;
	int i;
	srand(GetTickCount());
	tItems = (int**)malloc(2*sizeof(int*));
	tItems[0] = (int*)malloc(n*sizeof(int));
	tItems[1] = (int*)malloc(n*sizeof(int));
	tItems[0][0] = LowW;
	tItems[1][0] = LowV;
	for (i=1;i<n;i++)
		tItems[0][i] = rand()%(HighW-LowW+1)/n+LowW+tItems[0][i-1];
	for (i=1;i<n;i++)
		tItems[1][i] = rand()%(HighV-LowV+1)/n+LowV+tItems[1][i-1];
	return tItems;
}
int ShowItemList(int **pItems,int n)
{
	int i;
	printf("\t");
	for (i=0;i<n;i++)
		printf("%d\t",i);
	printf("\n");
	printf("W\t");
	for (i=0;i<n;i++)
		printf("%d\t",pItems[0][i]);
	printf("\n");
	printf("V\t");
	for (i=0;i<n;i++)
		printf("%d\t",pItems[1][i]);
	printf("\n");
	return 0;
}
double* GetVDW(int **pItems,int n)
{
	int i;
	double *tVDWList = NULL;
	tVDWList = (double*)malloc(n*sizeof(double));
	for (i=0;i<n;i++)
		tVDWList[i] = (double)pItems[1][i]/pItems[0][i];
	return tVDWList;
}
int ShowVDWList(double *pVDWList,int n)
{
	int i;
	printf("性价比：\n\t");
	for (i=0;i<n;i++)
		printf("%.3lf\t",pVDWList[i]);
	printf("\n");
	return 0;
}
double GetMaxValue(int **pItems,double *pVDWList,int n,int MaxW)
{
	int i,ti=0,tMaxW = MaxW;
	double tMaxValue=0.0,tMaxVDW=0.0;
	while (tMaxW)
	{
		for (i=0;i<n;i++)
		{
			if (pVDWList[i]>tMaxVDW)
			{
				tMaxVDW = pVDWList[i];
				ti = i;
			}
		}
		if (tMaxW>=pItems[0][ti])
		{
			tMaxW -= pItems[0][ti];
			tMaxValue += pItems[1][ti];
		}
		else
		{
			tMaxValue += (double)pItems[1][ti]*((double)tMaxW/pItems[0][ti]);
			tMaxW = 0;
		}
		pVDWList[ti] = -1;
	}
	return tMaxValue;
}

int main(void)
{
	int n;//共n个物品
	int MaxW;//背包总载荷
	int **pItems = NULL;//指向物品列表
	double *pVDWList = NULL;//指向性价比列表
	scanf_s("%d",&n);
	pItems = CreateItemList(n,1,15,2,30);//生成含n个物品的物品列表(最小重量1，最大重量15，最小价值2，最大价值30)
	ShowItemList(pItems,n);
	pVDWList = GetVDW(pItems,n);
	ShowVDWList(pVDWList,n);
	scanf_s("%d",&MaxW);
	printf("%.3lf\n",GetMaxValue(pItems,pVDWList,n,MaxW));
	system("pause");
}
