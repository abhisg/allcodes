#include<stdio.h>
#include<stdlib.h>

void mergeSort(long int begin,long int end,long int ar[])
{
        long int mid=(end+begin)/2;
        if(begin==end-1 || begin>=end)
                return;
        mergeSort(begin,mid,ar);
        mergeSort(mid,end,ar);
        long int k=begin,left=begin,right=mid;
        long int *temp=(long int *)malloc((end-begin)*sizeof(long int));
        while(k<end)
        {
                if(left<mid && right<end)
                {
                        if(ar[left]<=ar[right])
                        {
                                *(temp+k-begin)=ar[left];
                                left++;
                                k++;
                        }
                        else
                        {
                                *(temp+k-begin)=ar[right];
                                right++;
                                k++;
                        }
                }
                else if(left>=mid && right<end)
                {
                        *(temp+k-begin)=ar[right];
                        right++;
                        k++;
                }
                else if(right>=end)
                {
                        *(temp+k-begin)=ar[left];
                        left++;
                        k++;
                }
        }
        for(k=0;k<end-begin;k++)
        {
                ar[k+begin]=*(temp+k);
        }
        free(temp);
}

int main()
{
	long int t,n1,n2,i,j,min,begin,end,mid,mini;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n1);
		long int *ar1=(long int *)malloc(n1*sizeof(long int));
		for(i=0;i<n1;i++)
			scanf("%ld",ar1+i);
		scanf("%ld",&n2);
		long int *ar2=(long int *)malloc(n2*sizeof(long int));
		for(i=0;i<n2;i++)
			scanf("%ld",ar2+i);
		mergeSort(0,n1,ar1);
		mergeSort(0,n2,ar2);
		min=1000000;
		for(i=0;i<n1;i++)
		{
			begin=0;
			end=n2-1;
			mid=(begin+end)/2;
			while(end-begin>1)
			{
				mid=(begin+end)/2;
				if(ar2[mid]==ar1[i])
					break;
				else if(ar2[mid]<ar1[i])
					begin=mid;
				else
					end=mid;
			}
			if(ar2[mid]==ar1[i])
			{
				min=0;
				break;
			}
			else
			{
				long int min1=ar2[begin]>ar1[i]?ar2[begin]-ar1[i]:ar1[i]-ar2[begin];
				long int min2=ar2[end]>ar1[i]?ar2[end]-ar1[i]:ar1[i]-ar2[end];
				mini=min1<min2?min1:min2;
				//printf("mni %ld\n",mini);
				if(mini<min)
					min=mini;
			}
		}
		printf("%ld\n",min);
		free(ar1);
		free(ar2);
	}
	return 0;
}



