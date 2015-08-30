#include<cstdio>
#include<map>
#include<string>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	string s1,s2;
	int n,m,i,j,k,count=1;
	scanf("%d",&n);
	while(n!=0)
	{
		map<string,int> vals;
		double wei[n+1][n+1];
		for(i=1;i<n+1;i++)
		{
			for(j=1;j<=n;j++)
				wei[i][j]=100000;
		}
		for(i=1;i<=n;i++)
		{
			cin>>s1;
			vals[s1]=i;
			wei[i][i]=0;
		}
		scanf("%d",&m);
		double val;
		for(i=0;i<m;i++)
		{
			cin>>s1;
			scanf("%lf",&val);
			cin>>s2;
			wei[vals[s1]][vals[s2]]=-(log(val));
			//printf("%lf\n",-(log(val)));
		}
		int found=0;
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					wei[i][j]=(wei[i][j]<=wei[i][k]+wei[k][j])?wei[i][j]:(wei[i][k]+wei[k][j]);
				}
				//printf("%d %lf\n",i,wei[i][i]);
				if(wei[i][i]<0)
				{
					found=1;
					break;
				}
			}
			if(found==1)
				break;
		}
		if(found==1)
			printf("Case %d: Yes\n",count++);
		else
			printf("Case %d: No\n",count++);
		scanf("%d",&n);
	}
	return 0;
}

