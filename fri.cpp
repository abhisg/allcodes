#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int t,m,i,j,k,x,y,max=0;
	scanf("%d",&t);
	while(t--)
	{
		char first[100];
		scanf("%s",first);
		m=strlen(first);
		char friends[m][m];
		int looked[m][m];
		int possible[m];
		possible[0]=0;
		for(i=0;i<m;i++)
		{
			looked[0][i]=0;
			friends[0][i]=first[i];
		}
		for(i=1;i<m;i++)
		{
			possible[i]=0;
			char x=getchar();
			for(j=0;j<m;j++)
			{
				looked[i][j]=0;
				friends[i][j]=getchar();
			}
		}
		for(i=0;i<m;i++)
		{
			vector<int> locate;
			for(j=0;j<m;j++)
			{
				if(friends[i][j]=='Y')
				{
					locate.push_back(j);
					y=j;
					if(locate.size()>1)
					{
						for(k=0;k<locate.size()-1;k++)
						{
							x=locate[k];
							if(looked[x][y]==0)
							{
								looked[x][y]=1;
								looked[y][x]=1;
								if(friends[x][y]=='N')
								{
									//printf("%d %d %d\n",x,y,t);
									possible[x]++;
									possible[y]++;
								}
							}
						}
					}
				}
			}
			locate.clear();
		}
		max=possible[0];
		j=0;
		for(i=1;i<m;i++)
		{
			if(possible[i]>max)
			{
				max=possible[i];
				j=i;
			}
		}
		printf("%d %d\n",j,max);
	}
	return 0;
}

			
