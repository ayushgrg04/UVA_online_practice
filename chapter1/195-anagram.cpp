#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
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
		string tmp;
		cin>>tmp;
		// string tmp(s);
		sort(tmp.begin(), tmp.end(), comparator);
		do{
			cout<<tmp<<endl;
		}while(next_permutation(tmp.begin(), tmp.end(), comparator));
	}

	
	return 0;
		
		
}