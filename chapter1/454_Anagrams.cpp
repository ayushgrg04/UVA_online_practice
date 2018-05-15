#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <cctype>
using namespace std;



#define ui unsigned int 

bool comparator(char a, char b){
	if(tolower(a)==tolower(b)) return a<b;
	return tolower(a)<tolower(b);
}


int main(){
	int n;
	cin>>n;
	string s;
	getline(cin, s);getline(cin,s);
	while(n--){
		map<string, vector<string> > mp;
		while(1){
			string ss;
			getline(cin, ss);
			// cout << ss << endl;
			if(ss.length()==0) break;
			string t(ss);
			t.erase(remove(t.begin(), t.end(), ' '), t.end());
			sort(t.begin(), t.end());
			// cout<<"t: " <<t << endl;
			mp[t].push_back(ss);
		}
		// cout<<"###################"<<endl;
		map<string, vector<string> > :: iterator it;
		vector<pair<string, string> > vt;
		for(it=mp.begin();it!=mp.end();it++){
			int len = it->second.size();
			// cout<<"val: "<<it->first<<endl;
			sort((it->second).begin(), (it->second).end());
			for(int i=0;i<len-1;i++){
				// cout << (it->second)[i] << endl;
				for(int j=i+1;j<len;j++){
					vt.push_back(make_pair((it->second)[i], (it->second)[j]));
					 
				}
			}

		}


		// cout<<"###################"<<endl;


		sort(vt.begin(), vt.end());
		int tt = vt.size();
		for(int i=0;i<tt;i++)
			cout<<vt[i].first<<" = "<<vt[i].second<<endl;
		// cout<<"ayush"<<endl;
		if(n!=0)
			cout<<endl;

	}
	// fflush(cout);
	// cout.clear();
	// cout<<"kdfs"<<endl;
	return 0;
		
		
}