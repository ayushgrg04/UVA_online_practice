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
 
int arr[100100];
int rnk[100100];

int getroot(int a){
	if(arr[a]==a) return a;
	arr[a] = getroot(arr[a]);
	return arr[a];
}


void Union(int u, int v){
	// int tt = arr[u]+arr[v];
	if(rnk[u]>rnk[v]){
		arr[v]=u;
		
	}
	else{
		arr[u]=v;
		if(rnk[u]==rnk[v]) rnk[v]++;
	}
}


int main(){
	// priority_queue<Event> pq;
	// vector<vi> adlist;
	// int arr[100100];
	int m,n,tc,p, u, v;
	char s[10];
	char c;
	scanf("%d\n", &tc);
	while(tc--){
		int dis=0,con=0;
		scanf("%d", &n);
		for(int i=0;i<=n;i++){
			arr[i]=i;rnk[i]=0;
		}
		gets(s);
		while(gets(s) && strlen(s)){
			sscanf(s,"%c %d %d", &c, &u, &v);
			if(c=='c'){
				// u=s[2]-'0'; v =s[4]-'0';
				u = getroot(u); v= getroot(v);
				if(u!=v) Union(u, v);
			}
			else{
				// u=s[2]-'0';v=(int)s[4]-'0';
				// printf("tt %d %d\n", u, v);
				u=getroot(u); v=getroot(v);
				if(u!=v) dis++;
				else con++;
			}
		}
		printf("%d,%d\n", con, dis);
		if(tc) printf("\n");
	}

	
	return 0;

		
}