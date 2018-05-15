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
int arr[1010];

int main(){
	int tc,d,k,n, tmp, m;
	scanf("%d", &tc);
	
	while(tc--){
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			scanf("%d", &arr[i]);
		}
		int cnt=0;
		for(int i=1;i<n;i++){
			for(int j=0;j<i;j++){
				if(arr[j]<=arr[i]) cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
		
}