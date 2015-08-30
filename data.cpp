using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
int main()
{
	int n,m,i;
	scanf("%d %d",&n,&m);
	vector<string> inp;
	vector<int> result;
	while(n!=0 && m!=0)
	{
		result.resize(n);
		for(i=0;i<n;i++)
		{
			string s;
			cin>>s;
			inp.push_back(s);
		}
		sort(inp.begin(),inp.end());
		int val=0;
		for(i=1;i<n;i++)
		{
//			cout<<inp[i]<<"\n";
			if(inp[i]==inp[i-1])
				val++;
			else
			{
//				printf("%dv %d\n",result[val],val);
				result[val]++;
				val=0;
			}
		}
		if(inp[i-1]==inp[i-2])
			result[val]++;
		for(i=0;i<result.size();i++)
			printf("%d %d\n",result[i]);
		inp.clear();
		result.clear();
		scanf("%d %d",&n,&m);
	}
	return 0;
}
