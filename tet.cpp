#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

vector<map<int,unsigned long long int> > c;
//c.resize(100000);
unsigned long long int combo(long long int n,long long int m)
{
	printf("%lld %lld %lld\n",c[n][m],n,m);
	if(n<m)
		return 0;
	if(c[n][m]!=0)
	{
		//printf("%lld %lld %lld\n",c[ar],n,m);
		return c[n][m];
	}
	if(m==1)
	{
		c[n][m]=n;
                return n;
	}
        if(m==0 || m==n)
	{
		c[n][m]=1;
                return 1;
	}
        if(m<=n-m)
	{
		c[n][m]=combo(n-1,m-1)/m*n;
        	return c[n][m];
	}
        else
	{
		c[n][m]=combo(n,n-m);
        	return c[n][m];
	}
}

int main()
{
	c.resize(100001);
        long long int n,p,q,i,j=1;
        while(scanf("%lld %lld %lld",&n,&p,&q)>0)
        {
                double res=0;
                double bay=0;
                //vector<long long int>store;
                for(i=q;i<=n-p+q;i++)
                {
			//ar[0]=i;
			//ar[1]=q;
                        //int ar2[]={n-i,p-q};
                       	bay+=combo(i,q)*combo(n-i,p-q)*1.0;
			//printf("%lld %lld\n",c[ar],c[ar2]);
                }
		//printf("%lf\n",bay);
                for(i=q;i<=n-p+q;i++)
                {
                        //printf("%lf %lf\n",combo(i,q)*combo(n-i,p-q)*1.0/bay,res);
			//ar[0]=i;
			//ar[1]=q;
			unsigned long long int val1=c[i][q];
			//ar[0]=n-i;
			//ar[1]=p-q;
			unsigned long long int val2=c[n-i][p-q];
			//printf("%lld %lld\n",val1,val2);
			//int ar2[]={n-i,p-q};
                        res+=val1*val2*1.0/bay*(i-q)*1.0/(n-p);
                        //printf("%lf\n",res);
                }
                printf("Case %lld: %.4lf\n",j++,res);
        }
        return 0;
}




