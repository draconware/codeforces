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

	int n;
	cin>>n;

	vector<pair<int,bool> > v;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		v.pb(mp(x,false));
	}

	sort(v.begin(),v.end());

	int ans=0;

	for(int i=0;i<n;i++){
		if(v[i].ss){continue;}
		ans++;
		int val1 = v[i].ff;
		for(int j=i;j<n;j++){
			if((v[j].ff)%val1 == 0){v[j].ss = true;}
		}
	}
	cout<<ans<<endl;
}