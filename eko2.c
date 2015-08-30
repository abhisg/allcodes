#include<stdio.h>
#include<stdlib.h>

void mergeSort(int begin,int end,int ar[])
{
        int mid=(end+begin)>>1;
        if(begin==end-1 || begin>=end)
                return;
        mergeSort(begin,mid,ar);
        mergeSort(mid,end,ar);
        int k=0,left=begin,right=mid;
        int *temp=(int *)malloc((end-begin)*sizeof(int));
        while(k<(end-begin))
        {
                if(left<mid && right<end)
                {
                        if(ar[left]<=ar[right])
                        {
                                temp[k++]=ar[left++];
                        }
                        else
                        {
                                temp[k++]=ar[right++];
                        }
                }
                else if(left>=mid && right<end)
                {
                        temp[k++]=ar[right++];
                }
                else if(right>=end)
                {
                        temp[k++]=ar[left++];
                }
        }
        for(k=0;k<end-begin;k++)
        {
                ar[k+begin]=temp[k];
        }
        free(temp);
       
}
	
int main()
{
	long long int n,m,i,j,mid,begin,end;
	scanf("%lld %lld",&n,&m);
	long long int *arr=(long long int *)malloc(n*sizeof(long long int));
	long long int max=0;
	for(i=0;i<n;i++)
	{
		scanf("%lld",arr+i);
		max=arr[i]>max?arr[i]:max;
	}
	//mergeSort(0,n,arr);
	long long int total;
	begin=0;
	end=max;
	while(end-begin>1)
	{
		mid=(begin+end)>>1;
		total=0;
		for(i=n-1;i>=0;i--)
		{
			if(arr[i]>mid)
				total+=arr[i]-mid;
			//printf("%lld %lld %lld\n",total,arr[i],mid);
		}
		//printf("\n");
		(total==m)?break:total<m?end=mid:begin=mid;
	}
	long long int h=(end+begin)>>1;
	printf("%lld\n",h);
	return 0;
}





