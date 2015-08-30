#include<stdio.h>
int main()
{
	int n,i,l,j;
	while(scanf("%d",&n)>0)
	{
		int dp[n][n],cost[n][n];
		int arr[n];
		for(i=0;i<n;i++)
		{
			scanf("%d",arr+i);
			dp[i][i]=0;
			cost[i][i]=arr[i];
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
				cost[i][j]=(cost[i][j-1]+arr[j])%100;
		}
		for(i=0;i<n-1;i++)
			dp[i][i+1]=arr[i]*arr[i+1];
		for(l=2;l<n;l++)
		{
			for(i=0;i+l<n;i++)
			{
				dp[i][i+l]=dp[i][i]+dp[i+1][i+l]+cost[i][i]*cost[i+1][i+l];
				for(j=i+1;j<i+l;j++)
				{
					if(dp[i][j]+dp[j+1][i+l]+cost[i][j]*cost[j+1][i+l]<dp[i][i+l])
						dp[i][i+l]=dp[i][j]+dp[j+1][i+l]+cost[i][j]*cost[j+1][i+l];
				}
			}
		}
		printf("%d\n",dp[0][n-1]);
	}
	return 0;
}

