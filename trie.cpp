#include<string>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

typedef struct Node
{
	bool isEnd;
	map<char,struct Node *> children;
}Node;

Node *root;

void InsertElement(string s)
{
	if ( root == NULL)
	{
		root = new Node;
	}
	Node *n_copy = root;
	n_copy->isEnd = false;
	for ( unsigned i = 0; i < s.size() ;i++)
	{
		Node *child;
		map<char,struct Node*>::iterator it = n_copy->children.find(s.at(i));
		if ( it != n_copy->children.end())
		{
			child = it->second;
		}
		else
		{
			child = new Node;
			n_copy->children.insert(pair<char,Node*>(s.at(i),child));
		}
		n_copy = child;
	}
}

bool find(string s)
{
	Node *root_copy = root;
	for ( unsigned i = 0; i < s.size() ;i++)
	{
		Node *child;
		map<char,struct Node*>::iterator it = root_copy->children.find(s.at(i));
		if ( it == root_copy->children.end())
		{
			return false;
		}
		else
		{
			root_copy = it->second;
		}
	}
	return true;
}
 
int main()
{
	root = NULL;
	InsertElement("zebra");
	cout<<find("zebra");
	return 0;
}

