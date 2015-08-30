#include<stdio.h>
#include<stdlib.h>
int heapsize=0;
void insert(int ar[],int elem)
{
	int temp;
	ar[heapsize++]=elem;
	if(heapsize!=1)
	{
		int loop=heapsize-1;
		while(loop>0)
		{
			temp=ar[loop];
			if(loop%2==0)
			{
				if(ar[loop]>ar[loop/2-1])
				{
					ar[loop]=ar[loop/2-1];
					ar[loop/2-1]=temp;
					loop=loop/2-1;
				}
				else
					break;
			}
			else
			{
				if(ar[loop]>ar[loop/2])
				{
					ar[loop]=ar[loop/2];
					ar[loop/2]=temp;
					loop/=2;
				}
				else
					break;
			}
		}
	}
}

void delete(int ar[])
{
	int temp=ar[heapsize-1];
	ar[--heapsize]=ar[0];
	ar[0]=temp;
	int loop=0;
	while(loop*2+1<heapsize || loop*2+2<heapsize)
	{
			temp=ar[loop];
			if(loop*2+1<heapsize && loop*2+2<heapsize)
			{
				if(ar[loop]<ar[loop*2+1] && ar[loop]<ar[loop*2+2])
				{
					if(ar[loop*2+1]>ar[loop*2+2])
					{
						ar[loop]=ar[loop*2+1];
						ar[loop*2+1]=temp;
						loop=loop*2+1;
					}
					else
					{
						ar[loop]=ar[loop*2+2];
						ar[loop*2+2]=temp;
						loop=loop*2+2;
					}	
				}
				else if(ar[loop]<ar[loop*2+1])
				{
					ar[loop]=ar[loop*2+1];
					ar[loop*2+1]=temp;
					loop=loop*2+1;
				}
				else if(ar[loop]<ar[loop*2+2])
                                {
                                        ar[loop]=ar[loop*2+2];
                                        ar[loop*2+2]=temp;
                                        loop=loop*2+2;
                                }
				else 	
					break;
			}
			else if(loop*2+1<heapsize)
			{
				if(ar[loop]<ar[loop*2+1])
				{
					ar[loop]=ar[loop*2+1];
					ar[loop*2+1]=temp;
					loop=loop*2+1;
				}
				else 
					break;
			}
			else if(loop*2+2<heapsize)
			{
				if(ar[loop]<ar[loop*2+2])
				{
					ar[loop]=ar[loop*2+2];
					ar[loop*2+2]=temp;
					loop=loop*2+2;
				}
				else 	
					break;
			}
	}
}

int main()
{
	int n,i,num;
	scanf("%d",&n);
	int ar[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		insert(ar,num);
	}
	for(i=0;i<n;i++)
		delete(ar);
	for(i=0;i<n;i++)
		printf("%d ",ar[i]);
	printf("\n");
	return 0;
}



