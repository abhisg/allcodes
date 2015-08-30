#include<stdio.h>        
#include<string.h>        
#include<stdlib.h>        


void reverseIP(char*, char*);

int main(int argc, char** argv)
{
        char reverse[256];
        int ip_len = (int) strlen(argv[1]);
        reverseIP(argv[1], reverse);
        //printf("%s\n", reverse);
        return 0;
}
void reverseIP(char *addr, char *tar )
{
        int i,j,count_dots=0,pos=0;
        char buffer[10];
	for(i=strlen(addr)-1;i>=0;i--)
	{
		if(addr[i]=='.')
		{
			for(j=count_dots-1;j>=0;j--)
			{
				*(tar+pos)=buffer[j];
				pos++;
			}
			*(tar+pos)='.';
			pos++;
			count_dots=0;
		}
		else
		{
			buffer[count_dots]=addr[i];
			count_dots++;
		}
	}
	for(j=count_dots-1;j>=0;j--)
	{
		printf("%c\n",buffer[j]);		
		*(tar+pos)=buffer[j];
		pos++;
	}			
        char *arpa = ".in-addr.arpa";
        for(i=0;i<14;i++)
        {
                *(tar+pos) = *arpa;
		pos++;
                arpa++;
        }
}
