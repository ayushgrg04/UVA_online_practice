#include <iostream>
#include <stdio.h>
#include <string>
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

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;


#define ui unsigned int 
#define lli long long int

map<string, int> mp;
vector<int> arr;

int gindex(int u){
	if(arr[u]<0) return u;
	else return arr[u]=gindex(arr[u]);
}

int Union(int u, int v){
	int tt = arr[u]+arr[v];
	if(arr[u]>arr[v]){
		arr[u]=v;
		arr[v]=tt;
	}
	else{
		arr[v]=u;
		arr[u]=tt;
	}
	return -tt;
}

int main(){
	// priority_queue<Event> pq;
	// vector<vi> adlist;
	// int arr[100100];
	int tc,p, u, v;
	char s1[30], s2[30];
	
	// char c;
	scanf("%d", &tc);
	while(tc--){
		mp.clear();arr.clear();arr.push_back(0);
		int cnt=0;
		scanf("%d", &p);
		for(int i=0;i<p;i++){
			scanf("%s %s", &s1, &s2);
			u=mp[s1];
			if(u==0){
				u=mp[s1]=++cnt;
				arr.push_back(-1);
			}
			v=mp[s2];
			if(v==0){
				v=mp[s2]=++cnt;
				arr.push_back(-1);
			}

			u=gindex(u);
			v=gindex(v);
			if(u==v) printf("%d\n", -arr[u]);
			else printf("%d\n", Union(u,v));
		
		}
	}

	
	return 0;

		
}