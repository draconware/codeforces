#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

LL cost[100009];

void solve(){
	int n,k;
	cin>>n>>k;

	vector<LL> v;

	for(int i=0;i<n;i++){
		LL x;cin>>x;
		v.pb(x);
	}
	for(int i=0;i<n;i++){
		cin>>cost[i];
	}

	for(int i=0;i<n;i++){
		cost[i] = cost[i]+v[i];
	}

	set<pair<LL,int> > s,t;
	vector<pair<LL,int> > temp;
	for(int i=0;i<n;i++){
		temp.pb(make_pair(cost[i],i));
	}
	sort(temp.begin(),temp.end());

	for(int i=0;i<k;i++){
		s.insert(temp[i]);
	}
	for(int i=k;i<n;i++){
		t.insert(temp[i]);
	}

	LL ans = LLONG_MAX;

	for(int i=0;i<n;i++){
		if(s.find(make_pair(cost[i],i)) != s.end()){
			s.erase(make_pair(cost[i],i));
		}
	}
}

int main(){
	int t;
	cin>>t;

	for(int i=1;i<=t;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}