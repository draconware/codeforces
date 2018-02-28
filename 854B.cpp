#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,k;
	cin>>n>>k;
	//cout<<"executed"<<endl;

	if(k==0 || k==n){cout<<"0 0"<<endl;}
	else{
		cout<<"1 ";
		int x = (n)/3;
		if(k>x){cout<<n-k<<endl;}
		else{cout<<2*k<<endl;}
	}
}