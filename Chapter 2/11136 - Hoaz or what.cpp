#include <iostream>
#include <stdio.h>
// #include <string.h>
// #include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
// #include <bitset>
// #include <cmath>
// #include <stack>
// #include <initializer_list>
using namespace std;


#define ui unsigned int 
#define lli long long int
 


int main(){
	multiset<int> mp;
	multiset<int>:: iterator it;
	// multiset<int, greater<int> >:: reverse_iterator dt;

	bool fl=false;
	
	int n, temp, tt;
	
	while(scanf("%d",&n), n){
		long sum=0;
		for(int i=0;i<n;i++){
			scanf("%d",&temp);
			for(int j=0;j<temp;j++){
				scanf("%d",&tt);
				mp.insert(tt);
			}
			it=mp.end();it--;
			sum+= (*it-*mp.begin());
			mp.erase(mp.begin());
			mp.erase(it);
		}		
		printf("%ld\n",sum);
		mp.clear();

	}


	return 0;

		
}