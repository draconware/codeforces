#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	LL n,x;
	cin>>n;

	vector<LL> v1,v2;
	v1.push_back(0);v2.push_back(0);
	for(int i=0;i<n;i++){
		cin>>x;
		v1.push_back(x);
		v2.push_back(x);
	}
	sort(v2.begin(),v2.end());
	for(int i=1;i<=n;i++){
		v1[i]+=v1[i-1];
		v2[i]+=v2[i-1];
	}

	LL m;
	cin>>m;

	while(m--){
		LL t,l,h;
		cin>>t>>l>>h;
		if(t==1){
			cout<<v1[h]-v1[l-1]<<endl;
		}else{
			cout<<v2[h]-v2[l-1]<<endl;
		}
	}
	return 0;
}