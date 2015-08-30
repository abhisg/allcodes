#include<stdio.h>
#define MOD 1000000007

int main()
{
	int n,m,a,b,i,num,den,r1,r2,r2_fake;
	scanf("%d %d %d %d",&n,&m,&a,&b);
	r1=1;
	num=1,den=1;
	for(i=n+m-b;i>m-b;i--)
		num=(num*i)%MOD;
	for(i=n;i>0;i--)
		den=(den*i)%MOD;
	r2=((num%MOD)/(den%MOD))%MOD;
	r2_fake=r2;
	long long int ways=(r1*r2_fake)%MOD;
	for(i=1;i<=n-a;i++)
	{
		r1=((r1%MOD)*((b+i)%MOD))/(i%MOD);
		//r2=((r2%MOD)*((n-i+1)%MOD))/((n+m-b-i+1)%MOD);
		r2_fake=(((r2-1)%MOD)*((n-i+1)%MOD))/((n+m-b-i+1)%MOD);
		r2=((r2%MOD)*((n-i+1)%MOD))/((n+m-b-i+1)%MOD);
		ways+=(r1*r2_fake)%MOD;
	}
	printf("%lld\n",ways);
	return 0;
}
