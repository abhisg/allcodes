#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	map<long long int,long long int>count;
	vector<long long int>val;
	long long int n,i,num;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&num);
		val.push_back(num);
		count[num]++;
	}
	long long int v=val[0];
	long long int max=count[v];
	for(i=1;i<count.size();i++)
	{
		if(count[val[i]]>max)
		{
			max=count[val[i]];
			v=val[i];
		}
	}
	printf("%lld\n",v);
	return 0;
}

