#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <utility>
#include <queue>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    scanf("%d",&T);
    while(T--){
	int N,M,S;
        scanf("%d %d",&N,&M);
        set<pair<int,int> > graph;
	int *dist = (int *)malloc(N * sizeof(int));
        for(int i = 0;i<N;i++){
            dist[i] = 150001;
        }
        for ( int i = 0;i<M;i++){
            int x,y;
            scanf("%d %d",&x,&y);
	    if ( x < y)
	    {
            	graph.insert(make_pair(x,y));
	    }
	    else
	    {
            	graph.insert(make_pair(y,x));
	    }		
        }
        scanf("%d",&S);
        dist[S-1] = 0;
        queue<int> bfs;
        bfs.push(S-1);
        while(!bfs.empty()){
            int vert = bfs.front();
            bfs.pop();
            for (int i = 0;i<N;i++){
		if ( dist[i] != 150001)
			continue;
		if ( vert < i)
		{
                	if ( graph.find(make_pair(vert,i)) == graph.end()){
                    		dist[i] = dist[vert] + 1;
                    		bfs.push(i);     
                	}
		}
		else
                {	
			if ( graph.find(make_pair(i,vert)) == graph.end()){
                    		dist[i] = dist[vert] + 1;
                    		bfs.push(i);     
                	}
		}
            }
        }
        for(int i = 0;i<N;i++){
            if ( i != S-1){
                printf("%d ",dist[i]);
            }
        }
        printf("\n");
	free(dist);
    }
    return 0;
}

