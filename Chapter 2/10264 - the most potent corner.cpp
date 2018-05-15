#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <bitset>
#include <cmath>
// #include <initializer_list>
using namespace std;


#define ui unsigned int 
#define lli long long int


int main(){
	int n;
	while(scanf("%d", &n)!=EOF){
		int tt = (int)pow(2,n);
		// printf("tt %d\n", tt);
		int arr[tt];
		int pt[tt]={0};
		for(int i=0;i<tt;i++){
			scanf("%d", &arr[i]);
		}
		for(int i=0;i<tt;i++){
			int j=0;
			while(j<n){
				int tmp= (i ^ (1<<j));
				pt[i]+=arr[tmp];
				j++;
			}
		}

		// for(int i=0;i<tt;i++){
		// 	printf("pt %d\n", pt[i]);
		// }

		// printf("\n");
		int msum=0;
		for(int i=0;i<tt;i++){
			int j=0;
			while(j<n){
				int tmp= (i ^ (1<<j));
				int sm = pt[i]+pt[tmp];
				if(msum<sm) msum=sm;
				j++;
			}
		}		

		printf("%d\n", msum);

	}

	return 0;

		
}