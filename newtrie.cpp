#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string grid[50][50];
vector<string> allWords;
vector<string> wordList;
int M,N,K;

typedef struct Trie
{
	map<char,struct Trie *> child;
}Trie;

Trie *root;

void generateStrings(int i,int j,string s)
{
	string newString = s + grid[i][j];
	string beginString = grid[i][j];
	allWords.push_back(newString);
	if ( i+1 < M && j+1 < N)
	{
		
		generateStrings(i+1,j+1,newString);
		generateStrings(i,j+1,newString);
		generateStrings(i+1,j,newString);
		if ( beginString != newString)
		{
			generateStrings(i+1,j+1,beginString);
			generateStrings(i,j+1,beginString);
			generateStrings(i+1,j,beginString);	
		}
	}
	else if ( i+1 < M)
	{
		generateStrings(i+1,j,newString);
		if ( beginString != newString)
		{
			generateStrings(i+1,j,beginString);
		}
	}
	else if ( j+1 < N)
	{
		generateStrings(i,j+1,newString);
		if ( beginString != newString)
		{
			generateStrings(i,j+1,beginString);
		}
	}
}

void insertElement(string s)
{
	if ( root == NULL)
	{
		root = new Trie;
	}
	Trie *looper = root;
	for ( unsigned i = 0;i<s.size();i++)
	{
		map<char,struct Trie *>::iterator it = looper->child.find(s.at(i));
		if ( it != looper->child.end())
		{
			looper = it->second;
		}
		else
		{
			Trie *child = new Trie;
			looper->child[s.at(i)] = child;
			looper = child;
		}
	}
}

bool findElement(string s) 
{ 
        Trie *root_copy = root; 
        for ( unsigned i = 0; i < s.size() ;i++) 
        { 
                Trie *child; 
                map<char,Trie*>::iterator it = root_copy->child.find(s.at(i)); 
                if ( it == root_copy->child.end()) 
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

int main() {
	// your code goes here
	cin>>M>>N>>K;
	for(unsigned i = 0 ;i<M; i++)
	{
		string s;
		cin>>s;
		for ( unsigned j = 0; j<N ;j++)
		{
			grid[i][j] = s.substr(j,1);
		}
	}
	wordList.resize(K);
	for ( unsigned i=0;i<K;i++)
	{
		cin>>wordList[i];
	}
	generateStrings(0,0,"");
	root = NULL;
	for ( unsigned i = 0 ;i<allWords.size() ;i++)
	{
		insertElement(allWords[i]);
	}
	for ( unsigned i = 0;i<K;i++)
	{
		if ( findElement(wordList[i]))
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}
