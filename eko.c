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
	int n,m,i,j,mid,begin,end;
	scanf("%d %d",&n,&m);
	int *arr=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",arr+i);
	}
	mergeSort(0,n,arr);
	long long int total;
	begin=0;
	end=arr[n-1];
	while(end-begin>1)
	{
		mid=(begin+end)>>1;
		total=0;
		for(i=n-1;i>=0;i--)
		{
			if(arr[i]<=mid)
				break;
			total+=arr[i]-mid;
		}
		if(total==m)
			break;
		else if(total<m)
			end=mid;
		else if(total>m)
			begin=mid;
	}
	int h=(end+begin)>>1;
	printf("%d\n",h);
	return 0;
}



