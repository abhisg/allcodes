#include<stdio.h>
int main()
{
	long long int ar[4];
	long long int k=1;
	while(scanf("%lld",ar)>0 && scanf("%lld",ar+1)>0 && scanf("%lld",ar+2)>0 && scanf("%lld",ar+3)>0)
	{
		int i=0,j=0;
		long long int max=ar[0]+ar[1];
		for(i=0;i<3;i++)
		{
			for(j=i+1;j<4;j++)
			{
				long long int comp=ar[i]+ar[j];
				if(comp>max)
					max=comp;
			}
		}
		printf("Case %lld: %lld\n",k++,max);
	}
	return 0;
}







