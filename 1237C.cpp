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

	map<int,vector<pair<pii,int> > > mp1;
	vector<pii> v;

	for(int i=0;i<n;i++){
		int x,y,z;cin>>x>>y>>z;

		mp1[z].pb(mp(mp(x,y),i+1));
	}

	for(auto x:mp1){
		vector<pair<pii,int> > u = x.second;
		sort(u.begin(),u.end());
		for(int j=1;j<(int)u.size();j+=2){
			cout<<u[j].ss<<" "<<u[j-1].ss<<endl;
		}
		if((int)u.size()%2){
			v.pb(mp(x.first,u[(int)u.size()-1].second));
		}
	}
	sort(v.begin(),v.end());

	for(int i=1;i<(int)v.size();i+=2){
		cout<<v[i].ss<<" "<<v[i-1].ss<<endl;
	}
}