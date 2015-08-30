#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;


bool compare(int a,int b){
	return a > b;
}


int main()
{
    int T,N,K;
    cin>>T;
    while(T--){
    	cin>>N>>K;
    	int rows[N],columns[N];
    	for(int i = 0;i<N;++i){
    		rows[i] = 0;
    		columns[i] = 0;
    	}
    	int value;
    	for(int i = 0;i<N;++i){
    		for(int j = 0;j<N;++j){
    			cin>>value;
    			rows[i] += value;
    			columns[j] += value;
    		}
    	}
    	int rowpenalty = 0,columnpenalty = 0,discomfort=0;
    	priority_queue<int,vector<int>,decltype(&compare)> rowq(&compare);
    	priority_queue<int,vector<int>,decltype(&compare)> columnq(&compare);
    	for(int i = 0;i<N;++i){
    		rowq.push(rows[i]);
    		columnq.push(columns[i]);
    	}
    	for(int i=0;i<K;++i){
    		if ( rowq.top() + rowpenalty < columnq.top() + columnpenalty ){
    			int current = rowq.top();
    			discomfort += current + rowpenalty;
    			rowq.pop();
    			rowq.push(current+N);
    			columnpenalty++;
    		}
    		else if ( rowq.top() + rowpenalty > columnq.top() + columnpenalty ){
    			int current = columnq.top();
    			discomfort += current + columnpenalty;
    			columnq.pop();
    			columnq.push(current+N);
    			rowpenalty++;
    		}
		else{
		
		}
    	}
    	cout<<discomfort<<"\n";
    	//cout<<"Done\n";
    }
    return 0;
}

