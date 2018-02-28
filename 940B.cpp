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

	LL n,k,a,b;

	cin>>n>>k>>a>>b;

	LL ans = (n%k)*a;

	n = n-(n%k);
	
	if(k==1){
		cout<<((n-1)*a)<<endl;
		return 0;
	}

	while(n > 1){
		if(n%k == 0){
			ans = ans + min(b,(n - n/k)*a);
			n = n/k;
		}else{
			ans = ans + (n%k)*a;
			n = n - n%k;
		}
	}
	if(n==0){
		ans = ans - a;
	}
	cout<<ans<<endl;
}