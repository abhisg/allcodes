#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
char m[10][10];
//char n[10][10];
int main()
{
	int i,j,treecount=0,time=0,up,down,left,right;
	string s="";
	for(i=0;i<10;i++)
	{
		cin>>s;
		for(j=0;j<10;j++)
		{
			m[i][j]=s[j];
			if(m[i][j]=='T')
				treecount++;
		}
	}
	if(treecount==0)
		printf("%d\n",time);
	else
	{
		bool burn=true;
		while(treecount>0 && burn==true)
		{
			char n[10][10];
			for(i=0;i<10;i++)
			{
				for(j=0;j<10;j++)
					n[i][j]='d';
			}
			burn=false;
			for(i=0;i<10;i++)
			{
				for(j=0;j<10;j++)
				{
					if(n[i][j]=='d')
						n[i][j]=m[i][j];
					if(m[i][j]=='F')
					{
						up=i-1>=0?i-1:0;
						down=i+1<10?i+1:9;
						left=j-1>=0?j-1:0;
						right=j+1<10?j+1:9;
						if(m[up][j]=='T' && n[up][j]!='F')
						{
							n[up][j]='F';
							treecount--;
							burn=true;
						}
						if(m[i][left]=='T' && n[i][left]!='F')
						{
							n[i][left]='F';
							treecount--;
							burn=true;
						}
						if(m[i][right]=='T' && n[i][right]!='F')
						{
							n[i][right]='F';
							treecount--;
							burn=true;
						}
						if(m[down][j]=='T' && n[down][j]!='F')
						{
							n[down][j]='F';
							treecount--;
							burn=true;
						}
					}
				}
			}
			for(i=0;i<10;i++)
			{
				for(j=0;j<10;j++)
					m[i][j]=n[i][j];
			}
			if(burn==true)
				time++;
			//printf("%d %d\n",treecount,burn);
		}
		if(treecount>0 && burn==false)
			printf("%d\n",-1);
		else
			printf("%d\n",time);
	}
	return 0;
}

