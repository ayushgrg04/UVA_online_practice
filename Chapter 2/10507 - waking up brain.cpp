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
 
int index[30];
bool wake[30];
bool graph[30][30];
int cnt,n,m;

void initialise(){
	for(int i=0;i<30;i++){
		index[i]=0;
		wake[i]=false;
		for(int j=0;j<30;j++)
			graph[i][j]=false;
	}
	cnt=0;
}


int gindex(char u){
	int tt = index[u-'A'];
	if(!tt) tt=index[u-'A']=(++cnt);
	return tt;
}

bool solve(){
	int res=0,tmp=0;
	int bb=0;
	while(1){
		bb=0;
		// res++;
		vector<int> wlist;
		for(int i=1;i<=m;i++){
			int cc=0;
			if(!wake[i]){
				for(int j=1;j<=m;j++){
					if(wake[j] && graph[i][j]){
						cc++;
					}
				}
				if(cc>=3){
					// wake[i]=true;
					wlist.push_back(i);
					bb=1;	
				}
			}
		}

		if(bb){
			res++;
			int cc=0 ;

			for(int i=0;i<wlist.size();i++){
				wake[wlist[i]]=true;
			}
			for(int i=1;i<=m;i++){
				if(!wake[i]) cc++;
			}
			if(!cc){
				tmp=1;break;
			}
		}
		else{
			tmp=0;
			break;
		}


	}


	if(tmp){
		printf("WAKE UP IN, %d, YEARS\n", res);
		return true;
	}
	else return false;
}

int main(){
	// priority_queue<Event> pq;
	// vector<vi> adlist;
	// int arr[100100];
	int tc,p, u, v;
	char s[100];
	// char c;
	// scanf("%d\n", &tc);
	while(scanf("%d %d", &m, &n)!=EOF){
		initialise();
		scanf("%s", &s);
		for(int i=0;i<3;i++){
			p=gindex(s[i]);
			wake[p]=true;
		}

		while(n--){
			scanf("%s", &s);
			u=gindex(s[0]);
			v=gindex(s[1]);
			graph[u][v]=graph[v][u]=true;
		}
		if(m==3) printf("WAKE UP IN, 0, YEARS\n");
		else if(!(solve())) printf("THIS BRAIN NEVER WAKES UP\n");

		
	}

	
	return 0;

		
}