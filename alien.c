#include<stdio.h>
#include<stdlib.h>
typedef struct data
{
        int val;
        int price;
}data;
 
int main()
{
        int t,at,bt,i,begin,end,j;
        scanf("%d",&t);
        while(t--)
        {
                scanf("%d %d",&at,&bt);
                int *arr=(int *)malloc(at*sizeof(int));
                for(i=0;i<at;i++)
                        scanf("%d",arr+i);
                data best,temp;
                best.val=0,temp.val=0;
		best.price=0,temp.price=0;
               	j=0;
               	for(i=0;i<at;i++)
               	{
               		if(best.price+arr[i]<=bt)
               		{
               			best.price+=arr[i];
               			best.val++;
               			temp.price+=arr[i];
               			temp.val++;
               		}
               		else
               		{
               			temp.price+=arr[i];
               			temp.val++;
               			break;
               		}
               	}
                while(i<at)
                {
		       //printf("%d before %d\n",temp.price,temp.val);
                       while(j<=i)
                       {
                       		temp.val--;
                       		temp.price-=arr[j];
                       		j++;
                       		if(temp.price<=bt)
                       			break;
                       }
		       //printf("%d after %d\n",temp.price,temp.val);
                       i++;
                       while(i<at)
                       {
                       		if(temp.price+arr[i]<=bt)
                       		{
                       			temp.price+=arr[i];
                       			temp.val++;
                       			i++;
                       		}
                       		else
                       		{
                       			 break;
                       		}
  			}
			//printf("%d compare %d\n",temp.price,temp.val);
  			if(temp.val>best.val)
  			{
  				best.val=temp.val;
  				best.price=temp.price;
  			}
  			else if(temp.val==best.val && temp.price<best.price)
  				best.price=temp.price;
  			if(i!=at)
  			{
  				temp.price+=arr[i];
  				temp.val++;
  			}                     	
                }
                printf("%d %d\n",best.price,best.val);
                free(arr);
        }
        return 0;
}

