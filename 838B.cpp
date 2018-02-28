#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > v[200009],v1[200009];
vector<pair<pair<int,int>,int> > edges;
int level[200009];
bool mark[200009];

int main(){
	int n,m,x,y,w;
	cin>>n>>m;

	for(int i=0;i<n-1;i++){
		cin>>x>>y>>w;
		v[x].push_back(make_pair(y,w));
		edges.push_back(make_pair(make_pair(x,y),w));
	}
	memset(level,0,sizeof(level));

	queue<int> q;
	q.push(1);
	level[1]=0;

	while(!q.empty()){
		int p = q.front();q.pop();
		if(mark[p]){continue;}
		mark[p]=true;

		for(int i=0;i<v[p].size();i++){
			if(!mark[v[p][i]]){
				level[v[p][i]]=level[p]+1;
				q.push(v[p][i]);
			}
		}
	}
	for(int i=0;i<n-1;i++){
		cin>>x>>y>>w;
		v1[x].push_back(make_pair(y,w));
		edges.push_back(make_pair(make_pair(x,y),w));
	}

	while(q--){
		cin>>x;
		if(x==1){
			cin>>y>>w;
			if(level[y] < level[x]){
				
			}
		}
	}
}