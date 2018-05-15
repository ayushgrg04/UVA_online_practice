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

#define ui unsigned int 
#define lli long long int


int main(){
	int tc,d,k,n;
	scanf("%d", &tc);
	int s[50];
	while(tc--){
		scanf("%d", &n);
		n++;
		for(int i=0;i<n;i++)
			scanf("%d", &s[i]);
		scanf("%d", &d);
		scanf("%d", &k);
		int cnt=1;
		int tt=0;
		while(d<k){
			tt += (d*cnt);
			if(tt>=k) break;
			cnt++;
		}
		// printf("s %s\n d k %d %d\n",s, d, k);
		// printf("cnt %d\n", cnt);
		long long int res=0,hh=1;
		for(int i=0;i<n;i++){
			int gg=s[i];
			// sscanf(s+i, "%d", &gg);
			// printf("(%lld %d %lld)", res, gg, hh);
			res += (hh*gg);
			
			hh*=cnt;
		}
		printf("%lld\n", res);
	}

	
	return 0;

		
}