#include<cstdio>
#include<cstdlib>
using namespace std;
long long degree(long long a, long long k, long long p) {
	long long res = 1;
	long long cur = a;

	while (k) {
		if (k%2) {
			res = (res * cur)%p;
		}
		k /= 2;
		cur = (cur * cur) % p;
	}
	return res;
}
int get_degree(long long n, long long p) { // returns the degree with which p is in n!
	int degree_num = 0;
	long long u = p;
	long long temp = n;
	while (u <= temp) {
		degree_num += temp/u;
		u *= p;
	}
	return degree_num;
}

long long combinations(int n, int k, long long p) {
	int num_degree = get_degree(n,p) - get_degree(n- k,p);
	int den_degree = get_degree(k,p);
	if (num_degree > den_degree) {
		return 0;
	}
	long long res = 1;
	for (long long i = n; i > n- k; --i) {
		long long ti = i;
		while(ti % p == 0) {
			ti /= p;
		}
		res = (res *ti)%p;
	}
	for (long long i = 1; i <= k; ++i) {
		long long ti = i;
		while(ti % p == 0) {
			ti /= p;
		}
		res = (res * degree(ti, p-2, p))%p;
	}
	return res;
}
int compare (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}
int main()
{
	int t,n,k,i=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		int *arr=(int *)malloc(n*sizeof(int));
		for(int j=0;j<n;j++)
			scanf("%d",arr+j);
		qsort(arr,n,sizeof(int),compare);
		long long int sum=0;
		for(int j=k-1;j<n;j++)
		{
			long long int c=combinations(j,k-1,1000000007);
			long long int inter=((c%1000000007)*(arr[j]%1000000007))%1000000007;
			sum=(sum%1000000007+inter%1000000007)%1000000007;
		}
		printf("Case #%d: %lld\n",i++,sum);
	}
}
