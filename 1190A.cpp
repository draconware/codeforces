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

	LL n,k;
	int m;
	cin>>n>>m>>k;

	vector<LL> v;

	for(int i=0;i<m;i++){
		LL x;cin>>x;
		v.push_back(x);
	}

	int ans=0;
	LL discarded=0,r=0;
	int i=0;

	while(i<m){
		r = (v[i] - discarded - 1)/k + 1;
		r = r*k;
		r += discarded;
	//	cout<<v[i]<<" "<<r<<endl;

		while(i<m && v[i]<=r){
			i++;
			discarded++;
		}
		ans++;
	}
	cout<<ans<<endl;
}