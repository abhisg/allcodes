#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int sort(const void *x, const void *y) 
{
  return (*(int*)x - *(int*)y);
}
int main()
{
	int count[26];
	char str[502];
	int i,j,m;
	scanf("%d",&m);
	char c=getchar();
	for(i=1;i<=m;i++)
	{
		for(j=0;j<26;j++)
			count[j]=0;
		gets(str);
		for(j=0;j<strlen(str);j++)
		{
			if(str[j]>='a' && str[j]<='z')
				count[str[j]-'a']++;
			else if(str[j]>='A' && str[j]<='Z')
				count[str[j]-'A']++;
		}
		qsort(count,26,sizeof(int),sort);
		int mb=0;
		for(j=1;j<=26;j++)
			mb+=j*count[j-1];
		printf("Case #%d: %d\n",i,mb);
	}
	return 0;
}

