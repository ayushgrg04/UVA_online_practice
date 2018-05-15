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
	int tc,d,k,n, tmp, m;
	while(cin>>k){
		vector<pair<int, int>> sol;
		for(int y=k+1;y<=2*k;y++){
			if((k*y)%(y-k)==0)
				sol.push_back(make_pair((k*y)/(y-k), y));
		}

		cout<<sol.size()<<endl;
		for(size_t i=0; i<sol.size();i++){
			cout<<"1/"<<k<<" = 1/"<<sol[i].first<<" + 1/"<<sol[i].second<<endl;
		}
	}
	return 0;
		
}