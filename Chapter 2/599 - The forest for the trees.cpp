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
	// vector<vii> adlist;
	// int arr[10010];
	int u, v, tc;
	char s[100];
	scanf("%d\n", &tc);
	while(tc--){
		for(int i=0;i<30;i++) arr[i]=-1;
		while(gets(s)){
			if(s[0]=='*') break;
			u=s[1]-64;
			v=s[3]-64;
			// printf("tt %d %d\n",u,v);
			u = groot(u); v=groot(v);
			if(u!=v) Union(u,v);
		}
		gets(s);
		int corn=0, tree=0;
		int len = strlen(s);
		for(int i=0;i<len;i+=2){
			int tt = s[i]-64;
			// printf("i val %d %d\n", i, )
			if(arr[tt]==-1) corn++;
			else if(arr[tt]<0) tree++;
		}
		printf("There are %d tree(s) and %d acorn(s).\n", tree, corn);

	}
	return 0;

		
}