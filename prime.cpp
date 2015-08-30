#include <iostream>
#include <vector>

using namespace std;

bool isprime[32000];
vector<int> primes;

void sieve()
{
	for(int i=2;i*i<1000000001;++i){
		isprime[i] = true;
	}
	for(int i=2;i*i<1000000001;++i){
		if ( isprime[i] == true){
			primes.push_back(i);
			int j = 2;
			while ( i*j < 31623){
				isprime[i*j] = false;
				j++;
			}
		}
	}
}

int findpower(int divisor,int num)
{
	if ( num%divisor != 0){
		return 0;
	}
	int div = 1,prod = divisor;
	while ( prod < num ){
		//cout<<prod<<"\n";
		prod = prod * divisor;
		if ( prod > num || num%prod != 0){
			break;
		}
		div++;
	}
	return div;
}
int main()
{
    int N,T;
    cin>>T;
    sieve();
    while(T--){
    	cin>>N;
    	if ( N%2 != 0){
    		cout<<"0\n";
    	}
    	else{
    		int prod = 1;
    		for (int i=0;i<primes.size();i++){
    			if ( primes[i] == 2){
    				prod *= findpower(primes[i],N);
    			}
    			else{
    				prod *= findpower(primes[i],N)+1;
    			}
    		}
    		cout<<prod<<"\n";
    	}
    }
    return 0;
}

