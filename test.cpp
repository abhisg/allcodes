using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
int main()
{
	string x,y;
	int n,a,b;
	scanf("%d",&n);
	int p=1;
	while(n--)
	{
		scanf("%d",&a);
		cin>>x;
		scanf("%d",&b);
		cin>>y;
		string seq[a][b];
		string posx[a][b];
		string posy[a][b];
		int i=0,j=0;
		for(;i<a;i++)
		{
			if(x[i]==y[0])
			{
				seq[i][0]=x[i];
				posx[i][0].insert(posx[i][0].end(),1,(char)(i+'1'));
				posy[i][0].insert(posy[i][0].end(),1,'1');
			}
			else
				seq[i][0]="";
		}
		for(;j<b;j++)
		{
			if(x[0]==y[j])
			{
				seq[0][j]=y[j];
				posx[0][j].insert(posx[0][j].end(),1,(char)(j+'1'));
				posy[0][j].insert(posy[0][j].end(),1,'1');
			}
			else
				seq[0][j]="";
		}
		for(i=1;i<a;i++)
		{
			for(j=1;j<b;j++)
			{
				if(x[i]==y[j])
				{
					seq[i][j].append(seq[i-1][j-1]);
					seq[i][j].insert(seq[i][j].end(),1,x[i]);
					posx[i][j].append(posx[i-1][j-1]);
					posx[i][j].insert(posx[i][j].end(),1,(char)(i+'1'));
					posy[i][j].append(posy[i-1][j-1]);
					posy[i][j].insert(posy[i][j].end(),1,(char)(j+'1'));
				}
				else
				{
					if(seq[i-1][j].size()>seq[i][j-1].size())
					{
						seq[i][j]=seq[i-1][j];
						posx[i][j]=posx[i-1][j];
						posy[i][j]=posy[i-1][j];
					}
					else
					{
						seq[i][j]=seq[i][j-1];
						posx[i][j]=posx[i][j-1];
						posy[i][j]=posy[i][j-1];
					}
				}
			}
		}
		if(seq[a-1][b-1].size()>0)
		{
			cout<<"case "<<p++<<" "<<"Y\n"<<seq[a-1][b-1].size()<<"\n";
			for(i=0;i<seq[a-1][b-1].size();i++)
			{
				cout<<seq[a-1][b-1][i]<<" "<<posx[a-1][b-1][i]<<" "<<posy[a-1][b-1][i]<<"\n";
			}
		}
		else
			cout<<"case "<<p++<<" "<<"N\n";
		
	}
	return 0;
}
