#include<stdio.h>
#include<string.h>
int isPossible(char str[],int i,int len,int left,int right)
{
	if(i==len)
		return left==right;
	if(str[i]=='(')
	{
		if(left>=right)
			return isPossible(str,i+1,len,left+1,right);
		else
			return 0;
	}
	if(str[i]==')')
		return isPossible(str,i+1,len,left,right+1);
	if(str[i]==':')
	{
		if(i+1<len)
		{
			if(str[i+1]=='(')
				return isPossible(str,i+2,len,left+1,right) || isPossible(str,i+2,len,left,right);
			else if(str[i+1]==')')
				return isPossible(str,i+2,len,left,right+1) || isPossible(str,i+2,len,left,right);
		}
	}
	return isPossible(str,i+1,len,left,right);
}
		
int main()
{
	int t,i,j=1;
	char str[101];
	scanf("%d",&t);
	char c=getchar();
	while(t--)
	{
		gets(str);
	//	puts(str);
		int left=0,right=0;
		//printf("%d %d\n",left,right);
		if(isPossible(str,0,strlen(str),0,0))
			printf("Case %d:YES\n",j++);
		else
			printf("Case %d:NO\n",j++);
	}
	return 0;
}
