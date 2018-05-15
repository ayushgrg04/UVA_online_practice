#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <string.h>
#include <cctype>
using namespace std;



#define ui unsigned int 

bool comparator(char a, char b){
	if(tolower(a)==tolower(b)) return a<b;
	return tolower(a)<tolower(b);
}

// struct pp{
// 	int arr[2][2];
// };

string gh(int a){
	// cout<<"dds "<<a<<endl;
	int bb=1;
	string s=std::to_string(a);
	string tt="Blank";
	if(a){ return s;}
	else return tt;
	// return "ayush";
}

int main(){
	int n;
	int arr[3000];
	int diff[3010];
	while(scanf("%d", &n)!=EOF){
		int len=0;
		while(n--){
			scanf("%d", &arr[len]);
			len++;
		}
		bool res=true;
		for(int i=0;i<len+5;i++)diff[i]=0;
		for(int i=0;i<len-1;i++){
			int tmp = abs(arr[i+1]-arr[i]);
			if(tmp>=len || tmp==0){
				// printf("a\n");
				res=false;break;
			}
			else{
				if(diff[tmp]){
					// printf("b tmp %d\n", tmp);
					res=false;break;
				}
				else{
					diff[tmp]++;
				}
			} 

		}

		if(res) printf("Jolly\n");
		else printf("Not jolly\n");

	}

	return 0;
		
		
}