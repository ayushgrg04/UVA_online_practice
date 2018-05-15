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
	while(n--){
		int a,b;
		cin>>a>>b;
		// if(a>b)
		int m=a+b;
		int n=a-b;
		// if(n<0) n = -n;
		if(m>=0 && n >=0 && (m%2)==0 && (n%2)==0){
			cout<<(m/2)<<" "<<(n/2)<<endl;
			
		}
		else cout<<"impossible"<<endl;
	}

	return 0;
		
		
}