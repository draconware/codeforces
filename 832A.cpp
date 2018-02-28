#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	long long n,k;
	cin>>n>>k;

	long long ans = (n/k);
	if(ans%2 == 1){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
}