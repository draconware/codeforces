#include<bits/stdc++.h>
using namespace std;

int cnt[100009];

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

	multiset<pair<int,pair<float,int> > > mul;
	float x = m;

	for(int i=1;i<=m;i++){
		mul.insert(make_pair(0,make_pair(abs(((x+1.0)/2.0) - (float)i),i)));
	}

	for(int i=0;i<n;i++){
		pair<int,pair<float,int> > p = *mul.begin();mul.erase(mul.begin());
		//cout<<p.first<<" "<<p.second.first<<" "<<p.second.second<<endl;
		cnt[i] = p.second.second;
		p.first = p.first + 1;
		mul.insert(p);
	}

	for(int i=0;i<n;i++){cout<<cnt[i]<<endl;}
}