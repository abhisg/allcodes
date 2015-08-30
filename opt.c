#include<stdio.h>
int main()
{
	int h,w,m,t,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&h,&w);
		int opt[h][w];
		int arr[h][w];
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				scanf("%d",&m);
				arr[i][j]=m;
				opt[i][j]=0;
			}
		}
		for(i=0;i<w;i++)
			opt[0][i]=arr[0][i];
		for(i=1;i<h;i++)
		{
			opt[i][0]=opt[i-1][0]>opt[i-1][1]?arr[i][0]+opt[i-1][0]:arr[i][0]+opt[i-1][1];
			for(j=1;j<w-1;j++)
			{
				if(opt[i-1][j-1]>opt[i-1][j] && opt[i-1][j-1]>opt[i-1][j+1])
					opt[i][j]=opt[i-1][j-1]+arr[i][j];
				else if(opt[i-1][j]>opt[i-1][j-1] && opt[i-1][j]>opt[i-1][j+1])
					opt[i][j]=opt[i-1][j]+arr[i][j];
				else
					opt[i][j]=opt[i-1][j+1]+arr[i][j];
			}
			opt[i][w-1]=opt[i-1][w-1]>opt[i-1][w-2]?arr[i][w-1]+opt[i-1][w-1]:arr[i][w-1]+opt[i-1][w-2];
		}
		int max=opt[h-1][0];
		for(i=1;i<w;i++)
		{
			if(opt[h-1][i]>max)
				max=opt[h-1][i];
		}
		printf("%d\n",max);
	}
	return 0;
}

		
		
		
		
		
		
		

