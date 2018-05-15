#include <iostream>
#include <stdio.h>
#include <cstring>
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
	int n,t=0;
	int ch[1005];

	while(scanf("%d", &n), n){
		// if(t){
		// }
		// t=1;
		int i=0;
		while(scanf("%d", &ch[i]), ch[i]){
			for(int j=1;j<n;j++)
				scanf("%d", &ch[j]);
		
			stack<int> st;
			int ti=0,tt=1;
			while(tt<=n){
				st.push(tt);

				while(!st.empty() && st.top()==ch[ti]){
					st.pop();
					ti++;
					if(ti>=n) break;
				}

				tt++;
			}

			if(st.empty()) printf("Yes\n");
			else printf("No\n");

			i=0;
		}
		printf("\n");




	}

	return 0;

		
}