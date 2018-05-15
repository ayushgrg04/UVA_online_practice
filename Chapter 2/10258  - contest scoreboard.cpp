#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <map>
// #include <initializer_list>
using namespace std;


#define ui unsigned int 
#define lli long long int

struct stud{
	int ct;
	int np;
	int tm;

};

bool comparesort(stud a, stud b){
	if(a.np!=b.np) return a.np>b.np;
	else{
		if(a.tm!=b.tm) return a.tm<b.tm;
		else return a.ct<b.ct;
	}
}


int main(){
	char in[20];
	int tc;
	scanf("%d", &tc);
	getchar(); getchar();
	int a,b,c;
	char d;
	while(tc--){
		map<int, stud> mp;
		map<int, stud>:: iterator it;
		int arr[110][10]={0};

		while(gets(in) && strlen(in)){
			sscanf(in, "%d %d %d %c", &a, &b, &c , &d);
			// printf("%d %d %d %c\n", a, b, c, d);
			
			if(mp.find(a) != mp.end()){
				// printf("in map %d %d %d %c\n", a, b, c, d);
				if(d=='R' || d=='U' || d=='E') continue;
				else if(d=='C'){
					if(arr[a][b]!=-1){
						mp[a].np++;
						mp[a].tm += (c+arr[a][b]*20);
						arr[a][b]=-1;	
					}
					
				}
				else{
					if(arr[a][b]!=-1)
						arr[a][b]++;
				}
			}
			else{
				// printf("out map %d %d %d %c\n", a, b, c, d);
				if(d=='R' || d=='U' || d=='E'){
					stud ss={a,0,0};
					mp[a]=ss;
				}
				else if(d=='C'){
					if(arr[a][b]!=-1){
						stud ss={a, 1, c};
						mp[a]=ss;
						arr[a][b]=-1;
					}
						
				}
				else{
					if(arr[a][b]!=-1){
						stud ss={a, 0, 0};
						arr[a][b]++;
						mp[a]=ss;	
					}
					
				}
				
			}
		}

		vector<stud> vt;
		for(it=mp.begin(); it!=mp.end(); it++){
			vt.push_back(it->second);
			
		}

		sort(vt.begin(), vt.end(), comparesort);
		vector<stud>:: iterator il;
		for(il=vt.begin();il!=vt.end();il++){
			printf("%d %d %d\n", il->ct, il->np, il->tm);
		}


		if(tc)
			printf("\n");
	}
	
		
}