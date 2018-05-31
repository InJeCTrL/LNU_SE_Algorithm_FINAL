#include<stdio.h>
#include<malloc.h>
typedef struct
{
	int Begin;
	int End;
}Task;
Task* CreateTaskList(int n,int a,int b)
{
	int i;
	Task tTask;
	Task *tTaskList=NULL;
	tTaskList = (Task*)malloc(n*sizeof(Task));
	srand(GetTickCount());
	for (i=0;i<n;i++)
	{
		tTask.Begin = rand()%(b-a+1)+a;
		tTask.End = rand()%(b-tTask.Begin+1)+tTask.Begin;
		if (tTask.Begin == tTask.End)
		{
			i--;
			continue;
		}
		tTaskList[i] =tTask;
	}
	return tTaskList;
}
int OutPutTasks(Task *pTaskList,int n)
{
	int i;
	for (i=0;i<n;i++)
		printf("Task %d :From %d\tTo %d\n",i,pTaskList[i].Begin,pTaskList[i].End);
	return 0;
}
int GetMaxTaskNum(Task *pTaskList,int n,int *pTBuffer,int a,int b)
{
	int i,m,ti,j=0,FOUND=0;
	int *FULL = NULL;
	Task tTask;
	FULL = (int*)malloc(b*sizeof(int));
	for (i=0;i<b;i++)
		FULL[i] = 0;
	do
	{
		FOUND=0;//没有找到可插入的任务
		tTask.End = b;
		for (i=0;i<n;i++)
		{
			if (FULL[pTaskList[i].Begin]==0 && pTaskList[i].End<tTask.End)
			{//任务可插入且结束时间为当前最小
				FOUND = 1;
				tTask.End = pTaskList[i].End;
				tTask.Begin = pTaskList[i].Begin;
				ti = i;
			}
		}
		if (FOUND)
		{
			pTBuffer[j++] = ti;
			pTaskList[ti].End = b;
			for (m=a;m<tTask.End;m++)
				FULL[m] = 1;
		}
	}while(FOUND);
	return j;
}

int main(void)
{
	int n;//共n件任务
	int MaxCount;
	Task *pTaskList=NULL;
	int *pTBuffer=NULL;//最大任务缓冲区
	scanf_s("%d",&n);
	pTBuffer = (int*)malloc(n*sizeof(int));
	pTaskList = CreateTaskList(n,0,10);//随机生成n件任务列表，0单件任务最早时间，10单件任务最晚时间
	OutPutTasks(pTaskList,n);
	MaxCount = GetMaxTaskNum(pTaskList,n,pTBuffer,0,10);//返回最大任务数，pTBuffer返回任务列表
	printf("MaxTaskNum: %d\nTask List:",MaxCount);
	for (n=0;n<MaxCount;n++)
		printf("%d\t",pTBuffer[n]);
	printf("\n");
	system("pause");
	return 0;
}
