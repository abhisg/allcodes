#include<stdio.h>

int noOfDigits(long long int k)
{
	int n=1;
	long long int num=2,sum=2;
	while(sum<k)
	{
		n++;
		num*=2;
		sum+=num;
	}
	//printf("%d\n",n);
	return n;
}

void binary(long long int k,int bin[],int size)
{
	int i;
	for(i=0;i<size;i++)
		bin[i]=0;
	for(i=size-1;k>0;i--)
	{
		//printf("%lld\n",k);
		bin[i]=k%2;
		k/=2;
	}
}

long long int power(int n)
{
	if(n==1)
		return 2;
	if(n==0)
		return 1;
	long long int x=power(n/2);
	if(n%2==0)
		return x*x;
	else
		return x*x*2;
}

long long int calc(long long int k)
{
	long long int num=2;
	while(num+2*num<k)
	{
		num+=2*num;
	}
	return num;
}
int main()
{
	int n,i;
	long long int k,t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&k);
		if(k==1)
			printf("5\n");
		else if(k==2)
			printf("6\n");
		else
		{
			n=noOfDigits(k);
			int bin[n];
			long long int val=k-power(n)+1;
			//printf("%d %lld %lld\n",n,val,power(n));
			binary(val,bin,n);
			for(i=0;i<n;i++)
				printf("%d",5+bin[i]);
			printf("\n");
		}
	}
	return 0;
}

