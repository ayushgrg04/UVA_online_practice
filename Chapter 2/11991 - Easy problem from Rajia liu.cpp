#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
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

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;


#define ui unsigned int 
#define lli long long int
 
int arr[30];

int groot(int a){
	if(arr[a]<0) return a;
	arr[a] = groot(arr[a]);
	return arr[a];
}


void Union(int u, int v){
	int tt = arr[u]+arr[v];
	if(arr[u]>arr[v]){
		arr[u]=v;
		arr[v]=tt;
	}
	else{
		arr[v]=u;
		arr[u]=tt;
	}
}


int main(){
	// priority_queue<Event> pq;
	vector<vi> adlist;
	// int arr[10010];
	int m,n,t,p;
	while(scanf("%d %d", &m, &n)!=EOF){
		// int cnt=1;
		// adlist.clear();
		// for(int i=0;i<m+1;i++){
		// 	adlist.push_back(vi());	
		// }
		adlist.assign(1000010, vi());
		// vector<vi> adlist(m+1);
		for(int i=1;i<=m;i++){
			scanf("%d", &t);
			adlist[t].push_back(i);
		}

		for(int i=0;i<n;i++){
			scanf("%d %d", &t, &p);
			
			int len = adlist[p].size();
			if(len>=t){
				printf("%d\n", adlist[p][t-1]);
			}
			else{
				printf("0\n");
			}
		}
	}

	
	return 0;

		
}