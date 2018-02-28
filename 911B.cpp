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

	int n,a,b;
	cin>>n>>a>>b;

	int ans = 1;
	for(int i=1;i<n;i++){
		ans = max(ans,min(a/i , b/(n-i)));
	}
	cout<<ans<<endl;
}