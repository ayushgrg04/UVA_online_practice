#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;



#define ui unsigned int 


int main(){
	int n;
	cin >> n;
	string s;
	int cnt=1;
	getline(cin,s);
	while(n--){
		cout<<"Case #"<<(cnt++)<<":"<<endl;
		getline(cin,s);
		// cout <<s.length()<<" "<< s<<endl;
		int len=0,j=0;
		while(s[j]){
			if(s[j]>='a' && s[j]<='z') j++;
			else s.erase(j,1);
			// j++;
		}
		// s[len]='\0';
		// cout<<s.length()<<" "<<s<<endl;
		// s[len]=0;
		double tmp = sqrt((double)s.length());
		if(tmp-floor(tmp)!=0){
			cout<<"No magic :("<<endl;
			continue;
		}
		string tt(s);
		reverse(tt.begin(), tt.end());
		if(tt != s){
			cout<<"No magic :("<<endl;
			continue;
		}

		int dim=(int)tmp;
		int tp=0;
		for(int i=0;i<dim;i++){
			for(int j=0;j<dim;j++){
				if(s[i*dim+j]!=s[(dim-1-i)*dim+(dim-1-j)]){
					tp=1;
					goto lbl;
				}
			}	
		}
		lbl:
			tp? (cout<<"No magic :("<<endl) : (cout<<dim<<endl);
		 


	}

	return 0;
		
		
}