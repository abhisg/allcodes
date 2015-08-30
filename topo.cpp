#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
using namespace std;

map<char,vector<char> > graph;
map<char,bool> visited;
queue<char> vertices;
vector<pair<char,int> > incoming_edges_;

bool compare( pair p1, pair p2)
{
	return p1.second <= p2.second;
}

void dfs(char c)
{
	if ( visited[c] )
		return;
	vector<char> adjacent = graph[c];
	visited[c] = true;
	for ( unsigned i = 0 ; i < adjacent.size() ; i++)
	{
		dfs(adjacent[i]);
	}
	printf("%c\n",c);
	vertices.push(c);
}

int main()
{
	FILE* fp=freopen("graph.txt","r",stdin);
	char inp[10];
	while(scanf("%s",inp) > 0)
	{
		char head = inp[2];
		char tail = inp[0];
		graph[head].push_back(tail);
		visited[head] = false;
		visited[tail] = false;
	}
	for(map<char,vector<char> >::iterator it = graph.begin() ; it != graph.end() ; it++)
	{
		if(!visited[it->first])
		{
			dfs(it->first);
		}
	}
	while(!vertices.empty())
	{
		printf("%c ",vertices.front());
		vertices.pop();
	}
	printf("\n");
	return 0;
} 
