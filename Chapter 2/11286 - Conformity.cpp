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
	map<vector<int>, int> mp;
	map<vector<int>, int>:: iterator it;
	
	vector<int> vt(5);	
	int n;
	while(scanf("%d", &n), n){
		mp.clear();

		while(n--){
			for(int i=0;i<5;i++)
				scanf("%d", &vt[i]);
			sort(vt.begin(), vt.end());
			mp[vt]++;
		}
		int res=0, max=0;
		for(it=mp.begin();it!=mp.end();it++){
			if(it->second==max) res+=max;
			else if(it->second>max){
				max = it->second;
				res = max;
			}
		}
		printf("%d\n", res);
		// mp.clear();
	}


	return 0;

		
}