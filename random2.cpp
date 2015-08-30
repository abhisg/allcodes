#include <iostream>
using namespace std;

int main()
{
    int T,N,X;
    cin>>T;
    while(T--){
    	cin>>N>>X;
    	unsigned int A[N];
    	for(int i=0;i<N;++i){
    		cin>>A[i];
    	}
    	unsigned int left = 0,right=0,runningSum=0;
    	while(left <= right && right < N){
    		runningSum += A[right];
    		//cout<<runningSum<<"\n";
    		if ( runningSum > X){
    			while(left <= right && runningSum > X){
    				runningSum -= A[left++];
    			}
    			if ( runningSum == X){
    				break;
    			}
    			if ( left > right){
    				right = left;
    				runningSum = 0;
    			}
    		}
    		else if ( runningSum == X){
    			break;
    		}
    		else{
    			right++;
    		}
    	}
    	if ( left > right || right >= N){
    		cout<<"NO\n";
    	}
    	else{
    		cout<<"YES\n";
    	}
    	
    }
    return 0;
}

