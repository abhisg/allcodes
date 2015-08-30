#include<stdio.h>
#include<stdlib.h>
int main()
{
        long long int n,m,t,i;
        scanf("%lld",&t);
        while(t--)
        {
                scanf("%lld %lld",&n,&m);
                long long int a=0;
                long long int b=1;
                long long int c=(a+b);
                for(i=2;i<=n;i++)
                {
                        c=a%m+b%m+(n-1)%m;
                        a=b%m;
                        b=c%m;
                }
                if(n==0)
                	printf("%lld\n",a);
                else if(n==1)
                	printf("%lld\n",b);
                else
                	printf("%lld\n",c);
        }
	return 0;
}








