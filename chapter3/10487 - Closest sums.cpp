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
#include <cmath>
#include <stack>
// #include <initializer_list>
using namespace std;

#define ui unsigned int 
#define lli long long int
int arr[1010];

int main(){
	int tc=1,d,k,n, tmp, m;
	
	
	while(scanf("%d", &n), n){
		for(int i=0;i<n;i++){
			scanf("%d", &arr[i]);
		}
		printf("Case %d:\n", tc++);
		// sort(arr, arr+n);
		scanf("%d", &m);
		for(int i=0;i<m;i++){
			scanf("%d", &k);
			// int l=0,h=n-1, l1=0,h1=0,fl=0;
			int sum=1000111222;
			for(int j=0;j<n;j++){
				for(int l=j+1;l<n;l++){
					if(abs(arr[j]+arr[l]-k)<abs(sum-k)) sum=arr[j]+arr[l];
				}
			}
			printf("Closest sum to %d is %d.\n",k,sum);

		}

	}
	return 0;
		
}10487 - Closest sums