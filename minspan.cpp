#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#define SIZE 200
using namespace std;
typedef struct edge
{
	int head;
	int tail;
	long long int weight;
}edge;

vector<edge> graph;
bool pushed[SIZE];

bool compare (edge e1 , edge e2)
{
	return e1.weight <= e2.weight;
}

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
	FILE* fp=freopen("int.txt","r",stdin);
	int head,i;
	char inp[10];
	while(scanf("%s",inp)>0)
	{
		int len = strlen(inp);
		int first_pos_ = posofcom(inp , len);
		int second_pos_ = posofcom(inp + first_pos_ + 1 , len) + first_pos_ + 1;
//		cout<<first_pos_<<" "<<second_pos_<<"\n";
		long long int head_ = stoi(inp,first_pos_);
		long long int tail_ = stoi(inp + first_pos_ + 1 , second_pos_ - first_pos_ - 1);
		long long int weight_ = stoi ( inp + second_pos_ + 1, len - second_pos_ - 1);
//		cout<<head_<<" "<<tail_<<" "<<weight_<<"\n";
		graph.push_back({head_,tail_,weight_});
		pushed[head_] = false;
		pushed[tail_] = false;
	}
	fclose(fp);
	sort(graph.begin(),graph.end(),compare);
	vector<edge> min_spanning_tree_;
	pushed[graph[0].head] = true;
	for ( unsigned i = 0; i < graph.size(); i++)
	{
		edge under_consideration_ = graph[i];
		if ( (pushed[under_consideration_.head] && !pushed[under_consideration_.tail]) || (pushed[under_consideration_.tail] && !pushed[under_consideration_.head]))
		{
			min_spanning_tree_.push_back(under_consideration_);
			pushed[under_consideration_.tail] = true;
		}
	}
	for(unsigned i = 0; i< min_spanning_tree_.size(); i++)
	{
		cout<<min_spanning_tree_[i].head<<" "<<min_spanning_tree_[i].tail<<" "<<min_spanning_tree_[i].weight<<"\n";
	}
	return 0;
}

	
