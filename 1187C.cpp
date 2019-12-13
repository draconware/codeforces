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

	int n,m;
	cin>>n>>m;

	vector<pii> v[2];
	for(int i=0;i<m;i++){
		int a,b,c;cin>>a>>b>>c;

		v[a].pb(mp(c,b));
	}

	sort(v[1].begin(),v[1].end());

	if((int)v[1].size()==0){
		cout<<"YES"<<endl;
		for(int i=n;i>=1;i--){cout<<i<<" ";}cout<<endl;
	}else if((int)v[0].size()==0){
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++){cout<<i<<" ";}cout<<endl;
	}else{
		stack<pii> st;
		st.push(mp(v[0].second,v[0].first));
		for(int i=1;i<(int)v[1].size();i++){
			pii p = v[1][i];
			while(!st.empty()){
				pii p1 = st.top();
				if(p1.second<p.second){
					break;
				}else{
					st.pop();
					p = mp(min(p.second,p1.first),p.first);
				}
			}
			st.push(p);
		}
		vector<pii> processed;
		while(!st.emtpy()){
			processed.pb(st.top());st.pop();
		}
		for(int i=0;i<(int)v[0].size();i++){
			pii p = v[0][i];
			if(intersect(p,processed)){
				cout<<"NO"<<endl;return 0;
			}
		}
		cout<<"YES"<<endl;

	}
	return 0;
}