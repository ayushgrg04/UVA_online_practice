#include <iostream>
// #include<cstdio>
using namespace std;

int lft[100002], rgt[100002];

#define ui unsigned int 
#define lli long long int


int main(){
	
	
	
	int s,b;
	
	while(scanf("%d %d", &s, &b), (s||b)){
		
		// cout<<"s "<<s<<"b "<<b<<endl;
		// if(!s && !b) break;
		for(int i=1;i<=s;i++){
			lft[i]=i-1;
			rgt[i]=i+1;
		}
		lft[1]=-1;
		rgt[s]=-1;

		int l,r,j;
		for(j=0;j<b;j++){
			scanf("%d %d", &l , &r);
			// cout<<"l "<<l<<" r "<<r<<" i "<<j<< endl;
			lft[rgt[r]]=lft[l];
			if(lft[l]!=-1) printf("%d", lft[l]);
			else printf("*");

			rgt[lft[l]] = rgt[r];
			if(rgt[r]!=-1) printf(" %d\n", rgt[r]);
			else printf(" *\n");
			
		}
		
		printf("-\n");

	}

	return 0;
		
		
}