#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct data
{
	long long int index;
	char word[11];
}data;

void mergeSort(long long int begin,long long int end,data ar[])
{
        long long int mid=(end+begin)/2;
        if(begin==end-1 || begin>=end)
                return;
        mergeSort(begin,mid,ar);
        mergeSort(mid,end,ar);
        long long int k=begin,left=begin,right=mid;
        data *temp=(data *)malloc((end-begin)*sizeof(data));
        while(k<end)
        {
                if(left<mid && right<end)
                {
                        if(strcmp(ar[left].word,ar[right].word)<0)
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


long long int mergeCount(data ar[],int begin,int end)
{
        if(end<=begin)
                return 0LL;
        if(end==begin+1)
                return 0LL;
        int mid=(begin+end)/2;
        long long int left=mergeCount(ar,begin,mid);
        long long int right=mergeCount(ar,mid,end);
        long long int count=left+right;
        data *temp=(data *)malloc((end-begin)*sizeof(data));
        int i=begin,j=mid,k=0;
        while(i<mid || j<end)
        {
                if(i<mid && j<end)
                {
                        if(ar[j].index<ar[i].index)
                        {
                                temp[k++]=ar[j++];
                                count+=mid-i;
                        }
                        else
                        {
                                temp[k++]=ar[i++];
                        }
                }
                else if(i>=mid)
                {
                        temp[k++]=ar[j++];
                }
                else
                {
                        temp[k++]=ar[i++];
                }
        }
        k=0;
        while(k<(end-begin))
        {
                ar[begin+k]=temp[k++];
        }
        free(temp);
        return count;
}


int main()
{
        long long int t;
        scanf("%lld",&t);
        data *store=(data *)malloc(t*sizeof(data));
        data *rev=(data *)malloc(t*sizeof(data));
        long long int i,j,k;
        for(i=0;i<t;i++)
        {
        	char str[11];
                scanf("%s",store[i].word);
                store[i].index=i;
        }
        mergeSort(0,t,store);
        for(i=0;i<t;i++)
        {
		//printf("%s\n",store[i].word);
        	rev[i].index=i;
        	k=0;
                for(j=strlen(store[i].word)-1;j>=0;j--)
                	rev[i].word[k++]=store[i].word[j];
                rev[i].word[k]='\0';
        }
	//printf("\n");
        mergeSort(0,t,rev);
	//for(i=0;i<t;i++)
		//printf("%s %lld\n",rev[i].word,rev[i].index);
        printf("%lld\n",mergeCount(rev,0,t));
        return 0;
}
