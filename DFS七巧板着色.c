#include<stdio.h>
int OK(int pMap[][7],int i)
{
	if (pMap[i][i])
		return 0;
	return 1;
}
int DiffColor(int pMap[][7],int trv,int j)
{
	int i;
	for (i=0;i<7;i++)
		if (pMap[trv][i]==1 && pMap[i][i]==j)//可连通并且配色重合
			return 0;
	return 1;
}

int main(void)
{
	int pMap[][7] = {{0,1,1,1,0,0,0},
					 {1,0,0,0,1,1,0},
					 {1,0,0,1,0,0,1},
					 {1,0,1,0,1,0,0},
					 {0,1,0,1,0,1,1},
					 {0,1,0,0,1,0,0},
					 {0,0,1,0,1,0,0}};//指向七巧板图，0为连通，1为不连通，横纵坐标相等的点记录颜色(2~5)
	int i,j,trv=0;
	int stack=0;
	pMap[trv][trv] = 2;
	do
	{
		for (i=0;i<7;i++)
		{
			if (pMap[trv][i]==1 && OK(pMap,i))//检查将要加入的点是否连通、是否未被着色过
			{
				trv = i;
				stack = stack*10+trv;
				for (j=2;j<=5;j++)//4色涂色
				{
					if (DiffColor(pMap,trv,j))//找到一种可用的配色
					{
						pMap[trv][trv] = j;
						i = 8;
						break;
					}
				}
			}
		}
		if (i==7)
		{
			trv = stack/10%10;
			stack /= 10;
		}
	}while(stack);
	for (i=0;i<6;i++)
		printf("%d,",pMap[i][i]);
	printf("%d\n",pMap[6][6]);
	getchar();
	return 0;
}