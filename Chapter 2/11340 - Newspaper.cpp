#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <string.h>
#include <cctype>
using namespace std;



#define ui unsigned int 
#define lli long long int

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
	cin>>n;
	while(n--){
		// printf("ayush\n");
		int nc;
		cin>>nc;
		map<char, int> mp;
		while(nc--){
			char aa;
			int bb;
			cin>>aa>>bb;
			mp[aa]=bb;

		}
		int nl;
		cin>>nl;
		string s;
		lli res=0;
		getline(cin,s);
		while(nl--){
			getline(cin, s);
			for(int i=0;i<s.length();i++){
				res += mp[s[i]];
			}
		}
		// int 
		double dd = res/100.0;
		printf("%.2lf$\n", dd);
		// cout << res<<"$"<<endl;


	}

	return 0;
		
		
}