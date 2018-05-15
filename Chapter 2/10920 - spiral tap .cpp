#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;


#define ui unsigned int 
#define lli long long int

int main(){
	
	lli m,n;
	while(scanf("%lld %lld", &m, &n), m||n){
		
		lli a=1,b=1,rw=(m/2)+1, cl=(m/2)+1;
		while(b<n){
			b+=(a*8);
			a++;
			rw++;cl++;

		}
		if(b==n){
			printf("Line = %lld, column = %lld.\n", rw, cl);

		}
		else{
			rw--;cl--;a--;
			b-=(a*8);
			b++;rw++;
			
			lli fr=a*2+1, fc=a*2+1;
			// printf("case 1 rw cl %d %d\n", rw, cl);
			// printf("fr fc %d %d\n", fr, fc);
			if(b<=n && (b+fc-2)>=n){
				cl = cl-(n-b);
				goto label;
				
			}

			b+=(fc-2);
			cl-=(fc-2);

			// printf("case 2 rw cl %d %d\n", rw, cl);
			if(b<=n && (b+fr-1)>=n){
				rw=rw-(n-b);
				goto label;
			}
			b+=(fr-1);rw-=(fr-1);
			// printf("case 3 rw cl %d %d\n", rw, cl);
			if(b<=n && (b+fc-1)>=n){
				cl = cl + (n-b);
				goto label;
			}

			b+=(fc-1);cl+=(fc-1);
			// printf("case 4 rw cl %d %d\n", rw, cl);
			if(b<=n && (b+fr-1)>=n){
				rw = rw + (n-b);
				goto label;
			}


			label:
			printf("Line = %lld, column = %lld.\n", rw, cl);
		}

	}


	return 0;
		
		
}