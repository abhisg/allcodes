#include<stdio.h>
#include<stdlib.h>

long long int hcf(long long int a,long long int b)
{
	long long int gcd=a;
	while(b%a!=0)
	{
		gcd=b%a;
		b=a;
		a=gcd;
	}
	return gcd;
}

int main()
{
	long long int n,co,i,min=0;
	scanf("%lld",&n);
	if(n==2)
	{
		printf("%d\n",0);
	}
	else
	{
		long long int *coor=(long long int *)malloc(n*sizeof(long long int));
		scanf("%lld",coor);
		scanf("%lld",coor+1);
		scanf("%lld",coor+2);
		long long int gcd=hcf(coor[1]-coor[0],coor[2]-coor[1]);
		for(i=3;i<n;i++)
		{
			scanf("%lld",coor+i);
			gcd=hcf(gcd,coor[i]-coor[i-1]);
		}
		for(i=1;i<n;i++)
		{
			min+=(coor[i]-coor[i-1])/gcd-1;
		}
		printf("%lld\n",min);
		return 0;
	}
}


