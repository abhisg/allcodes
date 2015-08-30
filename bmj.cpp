#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n,round,x,y,i,j;
	while(cin>>n)
	{
		if(n==1)
		{
			printf("%d %d\n",0,0);
		}
		else
		{
			round=1;
			i=2;
			while(1)
			{
				if(6*round+i-1>=n)
					break;
				i=6*round+i;
				round++;
			}
			//printf("%d %d\n",round,i);
			x=round-1;
			y=1;
			j=i;
			while(i<n)
			{
				if(i<j+round-1)
				{
					x--;
					y++;
				}
				else if(i<j+round-1+round)
				{
					x--;
				}
				else if(i<j+3*round-1)
				{
					y--;
				}
				else if(i<4*round-1+j)
				{
					y--;
					x++;
				}
				else if(i<j+5*round-1)
				{
					x++;
				}
				else if(i<j+6*round-1)
				{
					y++;
				}
				i++;
			}
			printf("%d %d\n",x,y);
		}
	}
	return 0;
}

		
								
