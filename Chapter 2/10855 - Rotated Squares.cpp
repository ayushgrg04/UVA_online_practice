#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char big[500][500], sml[500][500];

#define ui unsigned int 
#define lli long long int

int find(int m, int n){
	int ans=0;
	for(int a=0;a<m;a++){
		for(int b=0;b<m;b++){
			if(a+n<=m && b+n<=m){
				for(int c=0;c<n;c++){
					for(int d=0;d<n;d++){
						if(big[a+c][b+d]!=sml[c][d]){
							goto label;
						}
					}
				}
				ans++;

			}
			label:;
		}
	}

	return ans;

}


void rotate(int n){
	int tmp[n][n];

	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			tmp[a][b] = sml[n-1-b][a];
		}
	}

	for(int a=0;a<n;a++)
		for(int b=0;b<n;b++)
			sml[a][b] = tmp[a][b];
	
}

int main(){
	
	int n,m,i;
	while(scanf("%d %d", &m, &n), m||n){
		for(int i=0;i<m;i++)
			scanf("%s", big[i]);
		for(int i=0;i<n;i++)
			scanf("%s", sml[i]);

		for(i=0;i<4;i++){
			if(i) putchar(' ');
			printf("%d", find(m,n));
			rotate(n);
		}	
		puts("");
	}

	return 0;
		
		
}