#include<bits/stdc++.h>
using namespace std;

#define LL long long
LL M = (LL)(1e9+7);

vector<int> G[200009];
vector<int> RG[200009];
stack<int> st;
bool mark[200009];
bool done[200009];
int edges[200009];
int value;
bool flag;

LL power(LL x,int y){
	LL res=1;
	while(y>0){
		if(y&1){res = (res*x)%M;}
		y/=2;
		x = (x*x)%M;
	}
	return res;
}

void dfs(int s){
	mark[s]=true;
	for(int i=0;i<(int)G[s].size();i++){
		int v = G[s][i];
		if(!mark[v]){
			dfs(v);
		}
	}
	st.push(s);
}

void dfs1(int s){
	value = value+edges[s];
	mark[s]=true;
	for(int i=0;i<(int)RG[s].size();i++){
		int v = RG[s][i];
		if(mark[v] && !done[v]){flag=true;}
		else if(!mark[v]){dfs1(v);}
	}
	done[s]=true;
}

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

	memset(edges,0,sizeof(edges));
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		G[i].push_back(a);
		RG[a].push_back(i);
		edges[i]++;
	}

	memset(mark,0,sizeof(mark));
	for(int i=1;i<=n;i++){
		if(!mark[i]){
			dfs(i);
		}
	}
	memset(mark,0,sizeof(mark));
	memset(done,0,sizeof(done));

	LL ans=1;
	while(!st.empty()){
		int u = st.top();st.pop();
		if(!mark[u]){
			value=0;flag=false;
			dfs1(u);
			//cout<<u<<" "<<value<<endl;
			if(flag){
				ans = (ans * ((power(2LL,value)-2+M)%M))%M;
			}else{
				ans = (ans * power(2LL,value))%M;
			}
		}
	}
	cout<<ans<<endl;
}