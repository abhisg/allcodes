#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#define SIZE 200
using namespace std;
typedef struct edge
{
	int tail;
	long long int weight;
}edge;

typedef struct node
{
	bool visited;
	long long int weight;
	vector<edge> links;
}node;

node graph[SIZE];
vector<int> current;
//priority_queue<int,vector<int>,Compare >current;
bool pushed[SIZE];

long long int stoi(char *str,int len)
{
	long long int val=0,i=0;
	while(i<len)
	{
		val=10*val+(str[i++]-'0');
	}
	return val;
}

int posofcom(char str[],int len)
{
	int pos=0;
	while(str[pos]!=',')
		pos++;
	return pos;
}

int main()
{
	FILE* fp=freopen("inp.txt","r",stdin);
	int head,i;
	char inp[10];
	while(scanf("%s",inp)>0)
	{
		int len=strlen(inp);
		int pos=posofcom(inp,len);
		if(pos>len)
		{
			head=stoi(inp,len)-1;
		}
		else
		{
			edge ins={stoi(inp,pos)-1,stoi(inp+pos+1,len-(pos+1))};
			graph[head].links.push_back(ins);
		}
	}
	fclose(fp);
	for(i=0;i<SIZE;i++)
	{
		graph[i].visited=false;
		graph[i].weight=1000000;
		pushed[i]=false;
	}
	graph[0].weight=0;
	current.push_back(0);
	while(!current.empty())
	{
		int pos=0;
		int va=current[0];
		long long int wei=graph[current[0]].weight;
		for(i=1;i<current.size();i++)
		{
			if(graph[current[i]].weight<wei)
			{
				wei=graph[current[i]].weight;
				va=current[i];
				pos=i;
			}
		}
		current.erase(current.begin()+pos);
		graph[va].visited=true;
		vector<edge> itr=graph[va].links;
		for(i=0;i<itr.size();i++)
		{
			if(graph[itr[i].tail].visited==false)
			{
				if(graph[va].weight+itr[i].weight<graph[itr[i].tail].weight)
					graph[itr[i].tail].weight=graph[va].weight+itr[i].weight;
				if(!pushed[itr[i].tail])
				{
					pushed[itr[i].tail]=true;
					current.push_back(itr[i].tail);
				}
			}
		}
	}
	for(i=0;i<SIZE;i++)
	{
		printf("NODE %d : WEIGHT %lld\n",i,graph[i].weight);
	}
	return 0;
}

	
