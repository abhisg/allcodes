#include <iostream>
#include <cstdio>

using namespace std;
int opt[100][100][100];
string s;
int Z;

int computeNumber(int i,int j)
{
	int num = 0;
	for(int k = i;k<=j;k++){
		num = num*10 + s[k] - '0';
		if ( num > Z )
			return -1;
	}
	return num;
}

void computeOpt(int i,int j,int k)
{
	if ( j >= s.size() )
		return;
	if ( opt[i][j][k-1] != -100)
		return;
	if ( i > j || k > (j-i+1) )
		opt[i][j][k-1] = -1;
	else if ( k == 1){
		opt[i][j][k-1] = computeNumber(i,j);
	}
	else{
		for ( int iter = i;iter<=j;iter++){
			opt[i][iter][0] = computeNumber(i,iter);
			if(opt[i][iter][0] == -1)
				break;
			computeOpt(iter+1,j,k-1);
			if ( opt[iter+1][j][k-2] != -1 && opt[i][iter][0] + opt[iter+1][j][k-2] > opt[i][j][k-1] ){
				opt[i][j][k-1] = opt[i][iter][0] + opt[iter+1][j][k-2];
			}
		}		
	}
	if ( opt[i][j][k-1] == -100){
		opt[i][j][k-1] = -1;
	}
//	printf("%d %d %d %d\n",i,j,k,opt[i][j][k-1]);
}

int main()
{
    int T,K;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&K,&Z);
		cin>>s;
		for(int i = 0;i<100;i++){
			for ( int j = 0;j<100;j++){
				for(int k =0;k<100;k++){
					opt[i][j][k] = -100;
				}
			}
		}
		computeOpt(0,s.size()-1,K);
		printf("%d\n",opt[0][s.size()-1][K-1]);
		
	}
    return 0;
}

