#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	LL n,e,d;
	cin>>n>>d>>e;

	LL ans = n;

	for(LL i=0;i<=n;i++){
		if(n>=(1LL*5*e*i)){
			ans = min(ans,(n-(1LL*5*e*i))%d);
		}
	}
	cout<<ans<<endl;
}