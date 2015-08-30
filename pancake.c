#include<stdio.h>
int main()
{
	int n,r,i,j,num;
	scanf("%d %d",&n,&r);
	while(n!=0 && r!=0)
	{
		int avail[n];
		for(i=0;i<n;i++)
			scanf("%d",avail+i);
		double max=0;
		int rp=1;
		for(i=0;i<r;i++)
		{
			double min=1000000;
			for(j=0;j<n;j++)
			{
				scanf("%d",&num);
				//double min=1000000;
				if(num!=0)
				{
					if((avail[j]*10.0/num)<min)
						min=avail[j]*10.0/num;
				}
			}
			if((int)(min)>(int)max)
			{
				max=min;
				rp=i+1;
			}
		}
		int res=(int)max;
		printf("%d %d\n",rp,res);
		scanf("%d %d",&n,&r);
	}
	return 0;
}
	
