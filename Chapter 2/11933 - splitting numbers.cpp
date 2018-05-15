#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <bitset>
// #include <initializer_list>
using namespace std;


#define ui unsigned int 
#define lli long long int


int main(){
	int n;
	while(scanf("%d", &n), n){
		int tt=(n & -n);
		int a=0,b=0;
		int res=0;
		while(tt){
			// printf("tt n %d %d\n", tt, n);
			if(res==0){
				a = a | tt;

			}
			else{
				b = b | tt;
			}
			res = 1-res;
			n = (n & ~tt);
			tt = (n & -n);
		}
		printf("%d %d\n", a, b);
	}

	return 0;

		
}