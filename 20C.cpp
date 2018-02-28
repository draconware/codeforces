#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > v[100009];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,m;
	cin>>n>>m;
	//cout<<"executed"<<endl;
	for(int i=0,x,y,w;i<m;i++){
		cin>>x>>y>>w;
		v[x].push_back(make_pair(y,w));
		v[y].push_back(make_pair(x,w));
	}
	int level[n+1];
	bool mark[n+1];
	memset(mark,0,sizeof(mark));
	for(int i=0;i<=n;i++){level[i]=INT_MAX;}
	multiset<pair<int,int> > s;
	s.insert(make_pair(0,1));
	level[1]=0;
	int parent[n+1];
	parent[1]=-1;

	while(!s.empty()){
		pair<int,int> p = *s.begin();s.erase(s.begin());
		int x = p.second,w = p.first;
		if(mark[x]){continue;}
		mark[x]=true;

		for(int i=0;i<v[x].size();i++){
			int y = v[x][i].first,w1 = v[x][i].second;
			if(level[y] > level[x]+w1){
				level[y]=level[x]+w1;
				s.insert(make_pair(level[y],y));
				parent[y]=x;
			}
		}
	}
	//cout<<"executed"<<endl;
	for(int i=0;i<=n;i++){v[i].clear();}
	if(level[n]==INT_MAX){cout<<"-1"<<endl;}
	else{
		vector<int> path;
		int i=n;
		//path.push_back(n);
		for(int i=n;i!=-1;){
			path.push_back(i);
			i=parent[i];
		}
		int size = (int)path.size();
		//cout<<"1"<<" ";
		for(int i=size-1;i>=0;i--){cout<<path[i]<<" ";}cout<<endl;
	}
}