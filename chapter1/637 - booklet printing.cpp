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
	while(cin>>n, n){
		int a,b;
		cout<<"Printing order for "<<n<<" pages:"<<endl;
		int arr[1000][2][2];

		int np = (n+3)/4;

		int lr=1,fb=0,p=1;
		for(int i=1;i<=np;i++){
			// int arr[2][2]={0};
			// pp tmp;
			if(p<=n)
				arr[i][fb][lr]=p++;
			else arr[i][fb][lr]=0;
			fb = 1-fb;
			lr = 1-lr;
			if(p<=n)
				arr[i][fb][lr]=p++;
			else
				arr[i][fb][lr]=0;
			fb=1-fb;
			lr=1-lr;
			// cout<<arr[i][0][1]<<endl;
			 // vt[i]=tmp;
		}

		// cout<<arr[1][0][1]<<endl;
		if(p<=n){
			fb=1;lr=1;
			for(int i=np;i>0;i--){

				if(p<=n)
					arr[i][fb][lr]=p++;
				else arr[i][fb][lr]=0;
				fb = 1-fb;
				lr = 1-lr;
				if(p<=n)
					arr[i][fb][lr]=p++;
				else
					arr[i][fb][lr]=0;
				fb=1-fb;
				lr=1-lr;

			}
		}
		// cout<<arr[1][0][1]<<endl;
		for(int i=1;i<=np;i++){
			// cout<<"auihsh"<<gh(arr[i][0][1])<<endl;
			if(arr[i][0][0] || arr[i][0][1])
				cout<<"Sheet "<<i<<", front: "<<gh(arr[i][0][0])<<", "
					<<gh(arr[i][0][1])<<endl;
			if(arr[i][1][0] || arr[i][1][1])
				cout<<"Sheet "<<i<<", back : "<<gh(arr[i][1][0])<<", "
					<<(arr[i][1][1]?(to_string(arr[i][1][1])):"Blank")<<endl;			
		}
	}

	return 0;
		
		
}