#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > v[100009];
int val[100009];
bool bakery[100009];
bool mark[100009];
vector<int> flour;

int dfs(int s){
	if(mark[s]){return val[s];}
	mark[s]=true;

	int res=INT_MAX;
	for(int i=0;i<v[s].size();i++){
		if(bakery[v[s][i].first] && !mark[v[s][i].first]){
			res = min(res,v[s][i].second + dfs(v[s][i].first));
		}else if(!bakery[v[s][i].first]){
			res = min(res,v[s][i].second);
		}
	}
	val[s]=res;
	return val[s];
}

int main(){
	int n,m,k;
	cin>>n>>m>>k;

	for(int x,y,w,i=0;i<m;i++){
		cin>>x>>y>>w;
		v[x].push_back(make_pair(y,w));
		v[y].push_back(make_pair(x,w));
	}
	memset(bakery,0,sizeof(bakery));
	memset(val,-1,sizeof(val));
	memset(mark,0,sizeof(mark));

	if(k==0 || k==n){
		cout<<"-1"<<endl;
	}else{
		for(int i=0,x;i<k;i++){
			cin>>x;
			flour.push_back(x);
			bakery[x]=true;
		}

		int best=INT_MAX;
		for(int i=0;i<k;i++){
			if(mark[flour[i]]){best = min(best,val[flour[i]]);}
			else{
				best = min(best,dfs(flour[i]));
			}
		}
		cout<<best<<endl;
	}
}