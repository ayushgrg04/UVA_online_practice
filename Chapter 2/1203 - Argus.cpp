#include <iostream>
#include <stdio.h>
// #include <string.h>
// #include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>
// #include <bitset>
// #include <cmath>
// #include <stack>
// #include <initializer_list>
using namespace std;


#define ui unsigned int 
#define lli long long int
 
struct Event {
	int period, t, ot;

	Event(){}

	Event(int a, int b, int c){
		period = a;
		t=b;
		ot=c;
	}

	bool operator<(Event const &b) const
	{
		if(this->t == b.t) return this->ot > b.ot;
		return this->t > b.t; 
	}

	Event next()
	{
		return Event(period, t+period, ot);
	}

};

int main(){
	priority_queue<Event> pq;

	string s;
	// multiset<int, greater<int> >:: reverse_iterator dt;

	// bool fl=false;
	
	int k, ot, pr;
	
	while(cin>>s){
		if(s=="#") break;
		cin>>ot>>pr;
		pq.push(Event(pr, pr, ot));
	}

	cin>>k;
	while(k--){
		Event top = pq.top();pq.pop();
		pq.push(top.next());

		cout<<top.ot<<endl;
	}

	return 0;

		
}