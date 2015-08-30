#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t,n,m,i,j,x,y,k,start=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		int **arr=(int **)malloc(m*sizeof(int *));
		for(i=0;i<m;i++)
			arr[i]=(int *)malloc(n*sizeof(int));
		for(i=0;i<m;i++)
		{
			start=0;
			while(start<n)
			{
				scanf("%d",&x);
				scanf("%d",&y);
				for(j=start;j<x+start;j++)
					arr[i][j]=y;
				start+=x;
			}
		}
		long long int *diag=(long long int*)malloc((m+n-1)*sizeof(long long int));
		for(i=0;i<m+n-1;i++)
			diag[i]=0;
		for(i=0;i<m+n-1;i++)
		{
			for(j=0;j<n;j++)
			{
				for(k=0;k<m;k++)
				{
					if(k+j==i)
						diag[i]+=arr[k][j];
				}
			}
		}
		i=0;
		while(i<m+n-2)
		{
			start=1;
			while(diag[i]==diag[i+1])
			{
				start++;
				i++;
			}
			printf("%d %lld ",start,diag[i]);
			i++;
		}
		if(diag[i]!=diag[i-1])
			printf("%d %lld",1,diag[i]);
		printf("\n");
	}
	return 0;
}

