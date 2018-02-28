#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int v1,v2,v3,vm;
	cin>>v1>>v2>>v3>>vm;

	if(max(v3,vm)>min(2*v3,2*vm)){cout<<"-1"<<endl;}
	else if(max(v1,2*vm)>=2*v1){cout<<"-1"<<endl;}
	else if(max(v2,2*vnm)>=2*v2){cout<<"-1"<<endl;}
	else{
		cout<<2*v1<<" "<<2*v2<<" "<<min(2*v3,2*vm)<<endl;
	}
}