#include<stdio.h>
#include<stdlib.h>
int OutputMx(int *pList,int n)
{//传入空列表与层数
	int i;
	if (!pList[n])//未全部生成
	{
		OutputMx(pList,n-1);
		for (i=n;i>=1;i--)
			pList[i] += pList[i-1];
		for (i=1;i<=n;i++)
			printf("%d\t",pList[i]);
		printf("\n");
	}
	else
		printf("%d\n",pList[n]);
	return 0;
}

int main(void)
{
	int n,i;
	int *pList=NULL;
	scanf_s("%d",&n);
	pList = (int*)malloc((n+1)*sizeof(int));
	for (i=0;i<=n;i++)
		pList[i] = 0;
	pList[1] = 1;
	OutputMx(pList,n);
	getchar();
	getchar();
	return 0;
}