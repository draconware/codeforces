#include<bits/stdc++.h>
using namespace std;

int degree[66000],val[66000];
vector<int> G[66000];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,ans=0;
	cin>>n;

	for(int i=0;i<n;i++){cin>>degree[i]>>val[i];ans+=degree[i];}
	multiset<pair<int,int> > m;
	for(int i=0;i<n;i++){
		m.insert(make_pair(degree[i],i));
	}

	for(int i=0;i<n;i++){
		pair<int,int> p = *m.begin();
		int x = p.second;
		int d = p.first;
		if(d==1){
			G[val[x]].push_back(x);
			m.erase(m.find(make_pair(degree[val[x]],val[x])));
			degree[val[x]]--;val[val[x]] = val[val[x]]^x;
			m.insert(make_pair(degree[val[x]],val[x]));
		}
		m.erase(make_pair(degree[x],x));
	}

	cout<<ans/2<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<G[i].size();j++){
			cout<<G[i][j]<<" "<<i<<endl;
		}
	}
}