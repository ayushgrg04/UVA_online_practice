#include <iostream>
#include <stdio.h>
// #include <string.h>
// #include <cstring>
#include <algorithm>
#include <map>
#include <vector>
// #include <bitset>
// #include <cmath>
// #include <stack>
// #include <initializer_list>
using namespace std;


#define ui unsigned int 
#define lli long long int
 

int main(){
	map<int, int> mp;
	map<int, int>:: iterator it;
	
	// vector<int> vt(5);	
	int n;
	scanf("%d", &n);
	while(n--){
		mp.clear();
		int nf;
		scanf("%d", &nf);
		int tt;
		int res=0,max=0;
		for(int i=0;i<nf;i++){
			scanf("%d", &tt);
			if(mp.find(tt)!=mp.end()){
				if(i-mp[tt]<=max) max=i-mp[tt]-1;

			}
			mp[tt]=i;
			max++;
			if(max>res) res=max;
		}
		printf("%d\n", res);


		// mp.clear();
	}


	return 0;

		
}