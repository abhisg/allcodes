#include<stdio.h>
#include<string.h>

long long int ar[2];
int stoi(char str[],int len)
{
        char c;
        long long int val1=-1,val2=-1;
        int i;
        for(i=0;i<len;i++)
        {
        	if(isdigit(str[i]))
        	{
        		if(val1==-1)
        		{
        			c=str[i];
        			val1=0;
        			while(isdigit(c))
        			{
        				val1=10*val1+(c-'0');
        				c=str[++i];
        			}
        			i--;
        			ar[0]=val1;
        		}
        		else
        		{
        			c=str[i];
        			val2=0;
        			while(isdigit(c))
        			{
        				val2=10*val2+(c-'0');
        				c=str[++i];
        			}
        			i--;
        			ar[1]=val2;
        		}
        	}
        }
        if(val1==-1 && val2==-1)
        	return 0;
        else if(val2==-1)
        	return 1;
        else 
        	return 2;
}


int main()
{
	char inp[15000];
	while(gets(inp))
	{
		int len=strlen(inp);
		int stat=stoi(inp,len);
		if(stat==0)
			continue;
		else if(stat==2)
		{
			long long int x=ar[0];
			long long int y=ar[1];
			if(x==0 && y==0)
				break;
			if((x-2)%23==0)
			{
				long long int div=(x-2)/23*2;
				if(y>=(div>>1)*23+1 && y<=(div>>1)*23+24)
				{
					printf("%lld\n",x+y-2);
				}
				else
					printf("No Number\n");
			}
			else if((y-1)%23==0)
			{
				long long int div=(y-1)/23*2-1;
				if(x>=((div-1)>>1)*23+2 && x<=((div-1)>>1)*23+25)
				{
					printf("%lld\n",x+y-2);
				}
				else
					printf("No number\n");
			}
			else
			{
				printf("No Number\n");
			}
		}
		else
		{
			long long int num=ar[0];
			long long int div=(num-1)/23;
			long long int x,y;
			if(div%2==0)
			{
				x=2+(div>>1)*23;
				y=2+num-x;
			}
			else
			{
				y=24+(div>>1)*23;
				x=2+num-y;;
			}
			printf("%lld, %lld\n",x,y);
		}
	}
	return 0;
}









