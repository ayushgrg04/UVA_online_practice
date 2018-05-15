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
char a[105], b[105];
char st[105], w[105];
int len,stk;
 

void dfs(int idx, int in, int out){
	if(in==len && out==len){
		for(int i=0;i<idx;i++){
			if(i) putchar(' ');
			putchar(w[i]);
		}
		puts("");
		return;
	}

	if(in<len){
		st[stk++]=a[in];
		w[idx]='i';
		dfs(idx+1, in+1, out);
		stk--;
	}


	if(out<in){
		if(st[stk-1]==b[out]){
			w[idx]='o';
			stk--;
			dfs(idx+1, in, out+1);
			st[stk]=b[out];
			stk++;
		}
	}
}


int main(){
	while(gets(a)){
		gets(b);
		puts("[");
		len=strlen(a), stk=0;
		if(len==strlen(b)){
			dfs(0,0,0);
		}
		puts("]");
	}

	
	return 0;

		
}