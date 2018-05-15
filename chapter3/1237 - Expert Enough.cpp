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

struct car{
	char s[50];
	int low;
	int high;
};

car arr[10010];
int main(){
	int tc,d,k,n, tmp, m;
	scanf("%d", &tc);
	char s[50];
	while(tc--){
		scanf("%d", &n);
		
		for(int i=0;i<n;i++){
			scanf("%s %d %d", &s, &k, &d);
			// car cr={s, k, d};
			strcpy(arr[i].s ,s);
			arr[i].low=k;
			arr[i].high=d;
		}
		scanf("%d", &m);
		
		for(int i=0;i<m;i++){
			scanf("%d", &tmp);
			int cnt=0, cm=0;
			for(int j=0;j<n;j++){
				if(arr[j].low<=tmp && arr[j].high>=tmp){
					cnt++;
					cm=j;
				}
				if(cnt>=2) break;
			}
			if(cnt==0 || cnt>=2) printf("UNDETERMINED\n");
			else printf("%s\n", arr[cm].s);
		}
		if(tc)
		printf("\n");	
	}

	
	return 0;

		
}