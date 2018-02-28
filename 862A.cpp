#include<bits/stdc++.h>
using namespace std;

int main(){
		#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,x;
	cin>>n>>x;

	set<int> s;
	for(int i=0,y;i<n;i++){cin>>y;s.insert(y);}

	int ans=0;
	for(int i=0;i<x;i++){
		if(s.find(i) == s.end()){ans++;}
	}
	if(s.find(x) == s.end()){cout<<ans<<endl;}
	else{cout<<ans+1<<endl;}
}