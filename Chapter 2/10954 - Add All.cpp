#include <iostream>
#include <stdio.h>
// #include <string.h>
// #include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>
// #include <bitset>
// #include <cmath>
// #include <stack>
// #include <initializer_list>
using namespace std;


#define ui unsigned int 
#define lli long long int
 


int main(){
	// priority_queue<Event> pq;
	multiset<long> mp;
	multiset<long>:: iterator it;
	multiset<long>:: iterator it1;

	
	int n;
	long ot, pr;
	
	while(scanf("%d", &n), n){
		long sum=0;
		for(int i=0;i<n;i++){
			scanf("%ld", &ot);
			mp.insert(ot);	
		}
		if(n!=1)
		while(!mp.empty()){
			// printf("ayush\n");
			long t1 = *mp.begin();
			// printf("t1 %ld ", t1);
			it = mp.begin();
			it1 = it;
			it1++;
			long t2 = *it1;
			// printf("t2 %ld\n", t2);
			it1++;
			mp.erase(it, it1);
			long tt = t1+t2;
			sum +=tt;
			if(mp.empty()) break;
			mp.insert(tt);
		}

		printf("%ld\n", sum);
		mp.clear();
	}
	
	return 0;

		
}