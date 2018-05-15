#include <iostream>
#include <stdio.h>
#include <string.h>
// #include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <bitset>
#include <cmath>
#include <stack>
// #include <initializer_list>
using namespace std;


#define ui unsigned int 
#define lli long long int
 

int main(){
	string s;
	int t=1;
	while(1){
		cin>>s;
		if(s=="end") break;
		int dp[10010];
		for(int i=0;i<s.length();i++){
			dp[i]=1;
			for(int j=0;j<i;j++){
				if(s[j]<s[i]){
					dp[i]=max(dp[i], 1+dp[j]);
				}
			}
		}
		int m=0;
		for(int i=0;i<s.length();i++){
			if(dp[i]>m) m=dp[i];
		}
		cout<<"Case "<<(t++)<<": "<<m<<endl;
	}


	return 0;

		
}