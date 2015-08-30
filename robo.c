#include<stdio.h>
#include<stdlib.h>

typedef struct data
{
	double begin;
	double end;
}data;

void mergeSort(int begin,int end,data ar[])
{
        int mid=(end+begin)/2;
        if(begin==end-1 || begin>=end)
                return;
        mergeSort(begin,mid,ar);
        mergeSort(mid,end,ar);
        int k=begin,left=begin,right=mid;
        data *temp=(data *)malloc((end-begin)*sizeof(data));
        while(k<end)
        {
                if(left<mid && right<end)
                {
                        if(ar[left].begin<=ar[right].begin)
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
	int nx,ny,i,j,k,b,e;
	double w,begin,end,pos;
	scanf("%d %d %lf",&nx,&ny,&w);
	while(nx!=0 && ny!=0 && w!=0.0)
	{
		data vertical[nx];
		data horizontal[ny];
		for(i=0;i<nx;i++)
		{
			scanf("%lf",&pos);
			begin=pos-w/2.0<0?0:pos-w/2.0;
			end=pos+w/2.0>75?75:pos+w/2.0;
			vertical[i].begin=begin;
			vertical[i].end=end;

		}
		for(i=0;i<ny;i++)
		{
			scanf("%lf",&pos);
			begin=pos-w/2.0<0?0:pos-w/2.0;
			end=pos+w/2.0>100?100:pos+w/2.0;
			horizontal[i].begin=begin;
			horizontal[i].end=end;
		}
		int flag=1,found=0;
		mergeSort(0,nx,vertical);
		for(i=0;i<nx-1;i++)
		{
			if(vertical[i].end<vertical[i+1].begin)
			{
				flag=0;
				break;
			}
			if(vertical[i].end==75)
				found=1;
		}
		if(found==0 && vertical[i].end==75)
			found=1;
		if(vertical[0].begin!=0)
			flag=0;
		if(flag==0 || found==0)
			printf("NO\n");
		else
		{
			found=0;
			mergeSort(0,ny,horizontal);
                	for(i=0;i<ny-1;i++)
                	{
                        	if(horizontal[i].end<horizontal[i+1].begin)
                        	{
                                	flag=0;
                                	break;
                        	}
				if(horizontal[i].end==100)
					found=1;
                	}
			if(found==0 && horizontal[i].end==100)
				found=1;
                	if(horizontal[0].begin!=0)
                        	flag=0;
			if(flag==0 || found==0)
				printf("NO\n");
			else
				printf("YES\n");
		}
		scanf("%d %d %lf",&nx,&ny,&w);
	}
	return 0;
}

			
