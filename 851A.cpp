#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	long long n,k,t;
	cin>>n>>k>>t;

	if(t<=k){cout<<t<<endl;return 0;}
	else if(t<=n){cout<<k<<endl;return 0;}
	else if(t<=n+k){cout<<(n+k-t)<<endl;return 0;}
	else{cout<<"0"<<endl;}
}