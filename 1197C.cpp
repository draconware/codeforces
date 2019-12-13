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

	int n,k;
	cin>>n>>k;

	vector<int> v;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		v.pb(x);
	}

	vector<int> u;
	for(int i=1;i<n;i++){
		u.pb(v[i-1]-v[i]);
	}
	sort(u.begin(),u.end());

	int ans = v[n-1]-v[0];
	for(int i=0;i<k-1;i++){
		ans+=(u[i]);
	}
	cout<<ans<<endl;
}