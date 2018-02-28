#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int vs,vf,t,d;
	cin>>vs>>vf>>t>>d;

	int ans=vs+vf;
	for(int i=1;i<t-1;i++){
		ans+=(min(vs+i*d,vf+(t-i-1)*d));
	}
	cout<<ans<<endl;
}