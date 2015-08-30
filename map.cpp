using namespace std;
#include<cstdio>
#include<map>
#include<algorithm>

long long int returnSum(long long int num)
{
	long long int sum=0;
	while(num)
	{
		long long int dig=num%10;
		sum+=dig*dig;
		num=num/10;
	}
	return sum;
}

int main()
{
	long long int num,i;
	map<long long int,long long int> add;
	long long int count=0;
	int flag=1;
	scanf("%lld",&num);
	add[num]=1;
	count++;
	while(flag)
	{
		num=returnSum(num);
		if(num==1 || add[num]!=0)
		{
				flag=0;
				break;
		}
		add[num]=1;
		count++;
	}
	if(num==1)
	{
			printf("%lld\n",count);
	}
	else
	{
			printf("%lld\n",-1LL);
	}
	return 0;
}
