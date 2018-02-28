#include<bits/stdc++.h>
using namespace std;

vector<int> G[30];
bool mark[30][30];
int degree[30];

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

	int total=0;
	memset(degree,0,sizeof(degree));
	memset(mark,0,sizeof(mark));
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
		mark[a][b]=true;mark[b][a]=true;
		total+=2;
		degree[a]++;
		degree[b]++;
	}
	if(2*m == (n*(n-1))){cout<<"0"<<endl;return 0;}

	set<pair<int,int> > s;
	for(int i=1;i<=n;i++){
		s.insert(make_pair(degree[i],i));
	}
	vector<int> res;
	while(!s.empty() && total<(n*(n-1))){
		set<int>::reverse_iterator it = s.rbegin();
		pair<int,int> p = *it;

		
		
		res.push_back(u);
		for(int i=0;i<(int)G[u].size();i++){
			int v = G[u][i];
			if(!mark[u][v]){
				mark[u][v]=false;
				mark[v][u]=false;
				degree[u]++;
				s.erase(s.find(make_pair(degree[v],v)));
				degree[v]++;
				s.insert(make_pair(degree[v],v));
				total+=2;
			}
		}
		for(int i=0;i<(int)G[u].size();i++){
			for(int j=0;j<(int)G[u].size();j++){
				if(i==j){continue;}
				int u1=G[u][i],v1=G[u][j];
				if(!mark[u1][v1]){
					mark[u1][v1]=true;
					mark[v1][u1]=true;
					s.erase(s.find(make_pair(degree[u1],u1)));
					s.erase(s.find(make_pair(degree[v1],v1)));
					degree[u1]++;
					degree[v1]++;
					s.insert(make_pair(degree[u1],u1));
					s.insert(make_pair(degree[v1],v1));
					total+=2;
				}
			}
		}
	}
	cout<<(int)res.size()<<endl;
	for(int i=0;i<(int)res.size();i++){cout<<res[i]<<" ";}cout<<endl;

}