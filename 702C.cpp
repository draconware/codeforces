#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	LL d,k,a,b,t;
	cin>>d>>k>>a>>b>>t;

	if(k>=d){
		cout<<a*d<<endl;
	}else{
		LL x = d/k;
		LL y = d%k;

		LL ans = d*b;
		ans = min(ans,k*a + (d-k)*b);
		ans = min(ans,x*k*a + (x-1)*t + y*b);
		ans = min(ans,d*a + x*t);
		cout<<ans<<endl;
	}
}