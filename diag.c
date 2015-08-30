#include<stdio.h>
int main()
{
	long long int t,n;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		long long int n1=n*((n-1)/2)-n;
		long long int n2=n1-2*n+7;
		long long int res=(n1*(n2/2))%(1000000007);
		if(n<4)
			printf("%lld\n",0LL);
		else if(n==4)
			printf("%lld\n",1LL);
		else
			printf("%lld\n",res);
	}
	return 0;
}

