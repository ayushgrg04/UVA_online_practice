#include <iostream>
#include <stdio.h>
// #include <string.h>
// #include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>
// #include <bitset>
// #include <cmath>
#include <stack>
// #include <initializer_list>
using namespace std;


#define ui unsigned int 
#define lli long long int
 


int main(){
	// priority_queue<Event> pq;
	multiset<long> mp;
	multiset<long>:: iterator it;
	multiset<long>:: iterator it1;

	
	int n;
	long ot, pr;
	int t1, t2;

	while(scanf("%d", &n)!=EOF){
			int arr[5]={0};
			queue<int> qu;
	stack<int> st;
	priority_queue<int> pt;
	
		for(int i=0;i<n;i++){
			scanf("%d %d", &t1, &t2);
			if(t1==1){
				st.push(t2);
				pt.push(t2);
				qu.push(t2);
			}
			else{
				if(st.empty() || st.top()!=t2){
					arr[1]=1;
					// printf("bg %d %d\n", st.top(), t2);	
				} 
				if(pt.empty() || pt.top()!=t2){
					// printf("pg %d %d\n", pt.top(), t2);
					arr[2]=1;
				} 
				if(qu.empty() || qu.front()!=t2){
					// printf("qg %d %d\n", qu.front(), t2);
					arr[0]=1;	
				}
				if(!st.empty())
					st.pop();
				if(!pt.empty())
					pt.pop();
				if(!qu.empty())
					qu.pop();
			}
		}

		if((arr[0] & arr[1] & arr[2])==1){
			printf("impossible\n");
		}
		else if(((arr[0] | arr[1])==0) || ((arr[0] | arr[2])==0) || ((arr[2] | arr[1])==0)){
			printf("not sure\n");
		}
		else if(arr[0]==0) printf("queue\n");
		else if(arr[1]==0) printf("stack\n");
		else printf("priority queue\n");
	}
	
	return 0;

		
}