#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <locale>
using namespace std;



#define ui unsigned int 

struct st{
	int cnt;
	string s;
};

int main(){
	string s;

	map<string, st> mp;

	while(1){
		cin >> s;
		if(s=="#") break;
		string tmp(s);
		// to_lower(tmp);
		transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
		sort(tmp.begin(), tmp.end());
		// cout<<tmp<<endl;
		if(mp.find(tmp)!=mp.end()){
			mp[tmp].cnt++;
		}
		else{
			st tt = {1, s};
			mp[tmp]=tt;
		}

	}
	// cout<<"########################################"<<endl;
	map<string, st>:: iterator itr;
	vector<string> vt;
	for(itr=mp.begin();itr!=mp.end();itr++){
		if((itr->second).cnt==1) vt.push_back((itr->second).s);
		// cout<<(itr->second).s<<endl;
	}
	// cout<<"######################################"<<endl;
	sort(vt.begin(), vt.end());
	vector<string>:: iterator it;
	for(it=vt.begin();it!=vt.end();it++){
		cout<<*it<<endl;
	}

	return 0;
		
		
}