#include<stdio.h>
#include<string.h>
long long int val(char str[],int len,long long int node)
{
	if(len==1)
	{
		if(str[0]=='P')
			return node;
		else if(str[0]=='L')
			return 2*node;
		else if(str[0]=='R')
			return 2*node+1;
		else
			return 5*node+1;
	}
	if(str[0]=='L')
		return val(str+1,len-1,2*node);
	if(str[0]=='R')
		return val(str+1,len-1,2*node+1);
	if(str[0]=='P')
		return val(str+1,len-1,node);
	else
		return val(str+1,len-1,2*node)+val(str+1,len-1,2*node+1)+val(str+1,len-1,node);
}

int main()
{
	char str[10001];
	scanf("%s",str);
	printf("%lld\n",val(str,strlen(str),1));
	return 0;
}

