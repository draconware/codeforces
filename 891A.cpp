#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	LL n;
	cin>>n;

	LL total=0;
	for(LL i=0,x;i<n;i++){
		cin>>x;
		total+=x;
	}
	vector<LL> v;
	for(LL i=0,x;i<n;i++){
		cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	LL cap = v[n-1]+v[n-2];
	if(cap>=total){cout<<"YES"<<endl;}
	else{cout<<"NO"<<endl;}
}
