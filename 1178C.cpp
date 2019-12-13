#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

LL M = 998244353;

LL power(LL a,LL b){
	LL res=1;

	while(b>0){
		if(b&1){res = (res*a)%M;}
		b/=2;
		a = (a*a)%M;
	}
	return res;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int w,h;
	cin>>w>>h;

	LL ans = (power(2,w+h))%M;
	cout<<ans<<endl;
}