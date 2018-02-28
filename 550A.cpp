#include<bits/stdc++.h>
using namespace std;

#define EXP 18446744073709551615

int main(){
	string s;
	cin>>s;

	size_t pos = s.find("AB");
	if(pos > s.length()){cout<<"NO"<<endl;}
	else{
		int i=pos;
		cout<<pos<<endl;
	}
}