#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

map<int,vector<int> > adlist;
vector<int> original_indexes;	//indexes of values
vector<int> original;		//initial nodes
vector<int> groups;
vector<bool> visited;	
map<int,vector<int> > components;	//connected components

void dfs(int group,int begin)
{
	vector<int> adjacent=adlist[begin];
	for(int i=0;i<adjacent.size();i++)
	{
		if(visited[adjacent[i]]==false)
		{
			groups[adjacent[i]]=group;
			visited[adjacent[i]]=true;
			components[group].push_back(adjacent[i]);
		}
	}
}

int main()
{
	int i,j,num;
	scanf("%d",&num);
	visited.resize(num+1);
	original_indexes.resize(num+1);
	groups.resize(num+1);
	original.resize(num);
	for(i=0;i<num;i++)
	{
		scanf("%d",&(original[i]));
		original_indexes[original[i]]=i;
		groups[i]=0;
		visited[original[i]]=false;
	}
	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
		{
			char y;
			cin>>y;
			if(y=='y')
				adlist[original[i]].push_back(original[j]);
		}
	}
	int group=0;
	for(i=0;i<num;i++)
	{
		if(visited[original[i]]==false)
		{
			visited[original[i]]=true;
			components[group].push_back(original[i]);
			groups[original[i]]=group;
			dfs(group,original[i]);
			group++;
		}
	}
	for(i=0;i<group;i++)
		sort(components[i].begin(),components[i].end());
	int current_pointer[group];
	for(i=0;i<group;i++)
		current_pointer[i]=0;
	for(i=0;i<num;i++)
		original[i]=components[groups[original[i]]][current_pointer[groups[original[i]]]++];
	for(i=0;i<num;i++)
		printf("%d ",original[i]);
	return 0;
}
