#include<bits/stdc++.h>
using namespace std;
#define LL long long

LL gcd(LL a,LL b){
	while(a>0){
		LL temp = a;
		a = b%a;
		b = temp;
	}
	return b;
}

int main(){
	LL a,b,x,y;
	cin>>a>>b;

	if(a==b){
		cout<<"1"<<endl;
	}else if(a>b){
		x = gcd(b,a);
		y = b/x;
		cout<<y<<endl;
	}else{
		x = gcd(a,b);
		y = (b-a)/x;
		y++;
		cout<<y<<endl;
	}
	return 0;
}