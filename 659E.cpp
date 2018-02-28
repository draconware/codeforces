#include<bits/stdc++.h>
using namespace std;

vector<int> v[100009];
int deg[100009];
bool sep[100009];
bool mark[100009];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	memset(deg,0,sizeof(deg));
	memset(sep,0,sizeof(sep));
	memset(mark,0,sizeof(mark));

	int n,m;
	cin>>n>>m;

	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		deg[i] = (int)(v[i].size());
	}
	set<pair<int,int> > s;
	for(int i=1;i<=n;i++){
		if(deg[i]>0){s.insert(make_pair(deg[i],i));}
	}

	while(!s.empty()){
		pair<int,int> p = *s.begin();
		s.erase(s.begin());
		mark[p.second]=true;
		//cout<<"for "<<p.second<<" "<<p.first<<"----- "<<endl;
		for(int i=0;i<v[p.second].size();i++){
			if(!mark[v[p.second][i]] && !sep[p.second]){
				//flag=true;
				sep[p.second]=true;
				s.erase(make_pair(deg[v[p.second][i]],v[p.second][i]));
				deg[v[p.second][i]]--;
				if(deg[v[p.second][i]] > 0){s.insert(make_pair(deg[v[p.second][i]],v[p.second][i]));}
		//		cout<<"1. "<<v[p.second][i]<<endl;
			}else if(!mark[v[p.second][i]]){
				sep[v[p.second][i]]=true;
		//		cout<<"2. "<<v[p.second][i]<<endl;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!sep[i]){ans++;}
	}
	cout<<ans<<endl;
}