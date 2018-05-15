#include <iostream>
#include <stdio.h>
// #include <string.h>
// #include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
// #include <bitset>
// #include <cmath>
// #include <stack>
// #include <initializer_list>
using namespace std;


#define ui unsigned int 
#define lli long long int
 


int main(){
	multiset<int, greater<int> > sg;
	multiset<int, greater<int> > sb;	
	multiset<int, greater<int> >:: iterator it;

	vector<int> vg;
	vector<int> vb;

	bool fl=false;
	
	int n, temp;
	cin>>n;
	while(n--){
		if(fl) cout<<endl;
		fl=true;

		int b, ng, nb;
		cin>>b>>ng>>nb;

		for(int i=0;i<ng;i++){
			cin>>temp;
			sg.insert(temp);
		}

		for(int i=0;i<nb;i++){
			cin>>temp;
			sb.insert(temp);
		}

		while(!sg.empty() && !sb.empty()){
			int ab = min(b, min((int)sg.size(), (int)sb.size()));
			int j=0;
			for(it=sg.begin();j<ab;j++){
				vg.push_back(*it);
				sg.erase(it++);
			}

			j=0;
			for(it=sb.begin();j<ab;j++){
				vb.push_back(*it);
				sb.erase(it++);
			}

			for(int i=0;i<ab;i++){
				if(vg[i]>vb[i]){
					sg.insert(vg[i]-vb[i]);
				}
				else if(vg[i]<vb[i]){
					sb.insert(vb[i]-vg[i]);
				}
			}

			vg.clear();
			vb.clear();
		}

		if(sg.empty() && sb.empty()){
			cout<<"green and blue died"<<endl;
		}
		else if(sg.empty()){
			cout<<"blue wins"<<endl;
			for(it=sb.begin();it!=sb.end();it++){
				cout<<*it<<endl;
			}
		}
		else{
			cout << "green wins"<<endl;
			for(it=sg.begin();it!=sg.end();it++){
				cout<<*it<<endl;
			}	
		}

		sb.clear();
		sg.clear();

	}


	return 0;

		
}