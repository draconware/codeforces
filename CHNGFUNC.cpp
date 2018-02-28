#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
	LL a,b,ans=0;
	cin>>a>>b;

	LL c = a*a + b;
	c = (LL)floor(sqrt(c));
	c = c*c;
	for(int i=1;i<=a;i++){
		if(c-(i*i) <= b && c-(i*i)>=0){ans++;}
	} 
	cout<<ans<<endl
}