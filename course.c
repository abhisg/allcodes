#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
typedef struct data
{
	long long int val;
	struct data *next;
	int visited;
}data;

long long int *time;
data **g,**grev,**end;
long long int t=1;

void dfs(data *start)
{
	//printf("%lld\n",start->val);
	if(grev[start->val-1]->visited==1)
		return;
	//printf("hi\n");
	if((start)->next==NULL)
	{
		grev[start->val-1]->visited=1;
		//printf("hello\n");
		time[(start)->val-1]=t++;
	}
	else
	{
		grev[start->val-1]->visited=1;
		dfs(grev[start->next->val-1]);
		time[(start)->val-1]=t++;
	}
	//printf("%lld %lld\n",(*start)->val,time[(*start)->val-1]);
}
		
int main()
{
	time=(long long int *)malloc(SIZE*sizeof(long long int));
	g=(data **)malloc(SIZE*sizeof(data *));
	end=(data **)malloc(SIZE*sizeof(data *));
	grev=(data **)malloc(SIZE*sizeof(data *));
	long long int i,num,n;
	char c;
	for(i=0;i<SIZE;i++)
	{
		g[i]=(data *)malloc(sizeof(data));
                grev[i]=(data *)malloc(sizeof(data));
	}
	for(i=0;i<SIZE;i++)
	{
		scanf("%lld",&num);
		grev[num-1]->val=num;
		grev[num-1]->next=NULL;
		grev[num-1]->visited=0;
		end[num-1]=grev[num-1];
		g[num-1]->val=num;
		g[num-1]->next=NULL;
		g[num-1]->visited=0;
		data *en=g[num-1];
		scanf("%c",&c);
		while(c!='\n')
		{
			data *ptr=(data *)malloc(sizeof(data));
			scanf("%lld",&(ptr->val));
			ptr->next=NULL;
			ptr->visited=0;
			en->next=ptr;
			en=ptr;
			scanf("%c",&c);
		}
	}
	for(i=0;i<SIZE;i++)
	{
		data *start=g[i]->next;
		while(start!=NULL)
		{
			data *ptr=(data *)malloc(sizeof(data));
			ptr->val=g[i]->val;
			ptr->next=NULL;
			ptr->visited=0;
			end[start->val-1]->next=ptr;
			end[start->val-1]=ptr;
			start=start->next;
		}
	}
	for(i=SIZE-1;i>=0;i--)
	{
		//printf("%lld h%d h%u\n",grev[i]->val,grev[i]->visited,grev+i);
		if(grev[i]->visited==0)
		{
			dfs(grev[i]);
		}
		//printf("%lld\n",i);
		//while(start!=NULL)
		//{
			//printf("%lld ",start->val);
			//start=start->next;
		//}
		//printf("\n");
		//printf("hi\n");*/
 		/*if(start!=NULL)
		{
			printf("sob\n");
			printf("%u ",start);
			if(start->visited==0)
				dfs(start);
		}*/
	}
	for(i=0;i<SIZE;i++)
		printf("%lld\n",time[i]);
}

	

