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
	int n,m;
	while(scanf("%d %d", &n, &m), n||m){
		bitset<1000000> bt;
		bool res=true;
		for(int i=0;i<n;i++){
			int a,b;
			scanf("%d %d", &a, &b);
			for(int rr=a;rr<b;rr++){
				if(bt[rr]!=0){ res=false; break;}
				else bt[rr]=1;
			}

		}
		for(int i=0;i<m;i++){
			int a,b,c;
			scanf("%d %d %d", &a, &b, &c);
			int tt=0;
			while(tt<1000000){

				for(int rr=a;rr<b;rr++){
					int tl = rr+tt;
					if(tl>=1000000) break;
					if(bt[tl]!=0) {res=false; break;}
					else bt[tl]=1;
				}
				tt+=c;
			}

		}

		if(res) printf("NO CONFLICT\n");
		else printf("CONFLICT\n");
	}


	return 0;

		
}