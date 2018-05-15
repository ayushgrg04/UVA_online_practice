#include <iostream>
// #include <stdio.h>
// #include <string.h>
// #include <cstring>
#include <algorithm>
#include <map>
// #include <vector>
// #include <bitset>
// #include <cmath>
// #include <stack>
// #include <initializer_list>
using namespace std;


#define ui unsigned int 
#define lli long long int
 

int main(){
	map<string, int> mp;
	map<string, int>:: iterator it;
		
	string s;
	int n;
	cin>>n;
	// getline(cin,s);
	cin.ignore(2);
	// printf("dfs %d\n",n);
	while(n--){
		
		int cnt=0;
		while(getline(cin, s) && s.length()){
			// printf("sssv %s\n", s);
			// cout<<"sssv "<<s<<endl;
			// if(mp.find(s)!=mp.end()){
				mp[s]++;
			// }
			// else{
			// 	mp[s]=1;
			// }
			cnt++;
		}
		for(it=mp.begin();it!=mp.end();it++){
			double res = (it->second)*100.0/(double)cnt;
			cout<<(it->first)<<" ";
			printf("%.4f\n", res);
		}
		if(n)
			printf("\n");
		mp.clear();
	}


	return 0;

		
}