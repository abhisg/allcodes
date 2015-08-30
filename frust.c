#include<stdio.h>
long long int n;
long long int sw=0;
long long int seq[4000];
void swap(int i,int j)
{
	long long int temp=seq[i];
	seq[i]=seq[j];
	seq[j]=temp;
}

void reverse(int i,int j)
{
	int k=i;
	if(k<=(i+j-1)/2)
	{
		while(k<=(i+j-1)/2)
		{
			sw++;
			swap(k,i+j-k);
			k++;
		}
	}
}

void sort()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(seq[i]>seq[j])
				reverse(i,j);
		}
		for(j=n-2;j>=i-2;j--)
			reverse(i+1,j);
	}
}

int main()
{
	scanf("%lld",&n);
	int i;
	for(i=0;i<n;i++)
		scanf("%lld",seq+i);
	sort();
	printf("%lld\n",sw);
	return 0;
}




