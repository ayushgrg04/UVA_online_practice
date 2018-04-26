#include <iostream>
using namespace std;
#define ui unsigned int 

int reverse(ui a){
	ui tmp=0;
	while(a){
		tmp=tmp*10+(a%10);
		a/=10;
	}
	return tmp;
}

bool pld(ui tt){
	return (tt==reverse(tt)?true:false);
}


int main(){
	int n;
	cin >> n;
	while(n--){
		ui tt;
		cin >> tt;
		// cout << tt << endl;
		int cnt=0;
		ui tmp;
		// if(pld(tt)){
		// 	cout << cnt << " " << tt << endl;
		// 	continue;
		// }
		while(1){
			ui tmp=reverse(tt);
			// cout<<tt<<endl;
			cnt++;
			tt+=tmp;
			if(pld(tt)){
				cout<<cnt<<" "<<tt<<endl;
				break;
			}
		}
	}

	return 0;
}