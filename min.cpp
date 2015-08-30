#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

void initialize(int node, int b, int e, long long int min[],long long int arr[])
{
      if (b==e)
          min[node] = arr[b];
      else
      {
          initialize(2*node+1,b,(b+e)/2,min,arr);
          initialize(2*node+2,(b+e)/2+1,e,min,arr);
	  min[node] = min[2*node+1]<=min[2*node+2]?min[2*node+1]:min[2*node+2];
      }
}

long long int query(int node, int b, int e, long long int min[], int i, int j)
{
      long long int p1, p2;
      if (i > e || j < b)
          return 1000000001LL;
   
      if (b>=i && e<=j)
          return min[node];
   
      p1 = query(2*node+1, b, (b + e) / 2, min,i, j);
      p2 = query(2*node+2, (b + e)/2 + 1, e, min,i, j);
   
      if (p1 == 1000000001LL)
          return p2;
      if (p2 == 1000000001LL)
          return p1;
      return p1<=p2?p1:p2;
}

int main()
{
        int t,n,j,k,q,i=1;
	long long int num;
        scanf("%d",&t);
        while(t--)
        {
                scanf("%d %d",&n,&q);
                long long int arr[n];
                long long int min[n];
		for(j=0;j<n;j++)
		{
			scanf("%lld",&num);
			arr[j]=num;
		}
      		initialize(0,0,n-1,min,arr);
                printf("Scenario #%d:\n\n",i++);
                while(q--)
                {
                        scanf("%d %d",&k,&j);
                        printf("%lld\n",query(0,0,n-1,min,k-1,j-1));
                }
        }
        return 0;
}






