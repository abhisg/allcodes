#include<stdio.h>
#include<math.h>
int main()
{
        long long int t,x,y,z;
        //long double x,y,z;
        scanf("%lld",&t);
        while(t--)
        {
                scanf("%lld %lld %lld",&x,&y,&z);
                //long double comp=(y*z)*((x+sqrtl(x*x+y*y+2*y*z))*1.0/(y*y+2*y*z));
                //long double comp=(z*1.0/(y+2*z))*((x+sqrtl(x*x+y*y+2*y*z)));
                 long long int r1=y+2*z;
                 double comp=(z*1.0/r1)*((x+sqrt(x*x+y*r1)));
                long long int res=llrintl(comp);
                if(res-comp!=0 || res>x || res<0)
                        printf("Not this time.\n");
                else
                        printf("%lld\n",res);
        }
        return 0;
}
