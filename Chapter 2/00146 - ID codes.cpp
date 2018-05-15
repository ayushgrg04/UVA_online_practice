#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;


#define ui unsigned int 
#define lli long long int


int main(){
	
	string s;
	while(1){
		cin>>s;
		if(s=="#") break;

		if(next_permutation(s.begin(), s.end())){
			cout<<s<<endl;
		}
		else{
			cout<<"No Successor"<<endl;
		}
	}
		
}