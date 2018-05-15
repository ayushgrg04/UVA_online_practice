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
	int hr1, mn1;
	while(scanf("%d:%d", &hr1 , &mn1)!=EOF){
		// cin>>s;
		// if(s=="0:00") break;
		// string s1 = strtok(s,":");
		// string s2 = strtok(NULL, ":");
		if(!hr1 && !mn1) break; 
		// cout<<"s1 "<<s1<<"s2 "<<s2<<endl;

		double hr = double(hr1);double mn=double(mn1);
		hr = (hr*30)+((mn*6)/12.0);
		mn *= 6;
		double res = (hr-mn)>0?(hr-mn):(-hr+mn);
		res = res>180?360-res:res;
		// if(hr-mn<180) (hr-mn)
		// cout<<(round(res*1000.0)/1000.0) << endl;
		printf("%.3lf\n", res);
	}

	return 0;
		
		
}