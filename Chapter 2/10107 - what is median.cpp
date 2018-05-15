#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
// #include <initializer_list>
using namespace std;


#define ui unsigned int 
#define lli long long int


int main(){
	int arr[10005];
	int n=0;
	while(scanf("%d", &arr[n])!=EOF){
		n++;
		for(int i=n-1;i>0;i--){
			if(arr[i]<arr[i-1]){
				swap(arr[i], arr[i-1]);
			}
			else break;
		}
		if(n%2) printf("%d\n", arr[n/2]);
		else printf("%d\n", (arr[n/2]+arr[(n/2)-1])/2);
	}


	return 0;

		
}