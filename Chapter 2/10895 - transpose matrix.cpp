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

typedef pair<int, int> ii;
typedef vector<ii> vii;


#define ui unsigned int 
#define lli long long int
 


int main(){
	// priority_queue<Event> pq;
	vector<vii> adlist;
	int arr[10010];
	int m, n;
	while(scanf("%d %d", &m, &n)!=EOF){
		int r=0, tmp;
		adlist.assign(n+1, vii());
		for(int i=0;i<m;i++){
			
			scanf("%d", &r);
			if(r==0) continue;
			for(int k=0;k<r;k++){
				scanf("%d", &arr[k]);
			}
			for(int j=0;j<r;j++){
				scanf("%d", &tmp);
				adlist[arr[j]].push_back(ii(i+1, tmp));
			}

		}

		printf("%d %d\n", n, m);
		for(int i=1;i<=n;i++){
			int cnt=0;
			printf("%d", adlist[i].size());

			sort(adlist[i].begin(), adlist[i].end());
			for(int j=0;j<adlist[i].size();j++){
				printf(" ");
				printf("%d", (adlist[i][j]).first);
				
			}
			printf("\n");
			for(int j=0;j<adlist[i].size();j++){
				printf("%d", (adlist[i][j]).second);
				if(j!=adlist[i].size()-1) printf(" ");
			}
			printf("\n");

		}
	}
	return 0;

		
}