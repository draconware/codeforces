#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

LL cost[3][100009];
int deg[100009];

vector<int> G[100009];
bool mark[100009];
int color[100009];

LL dfs(int s,int c1,int c2){
	mark[s] = true;

	LL ans = cost[c2][s];
	for(int i=0;i<(int)G[s].size();i++){
		int v = G[s][i];
		if(!mark[v]){
			for(int j=0;j<3;j++){
				if(c1!=j && c2!=j){
					ans+=dfs(v,c2,j);
				}
			}
		}
	}
	return ans;
}

void coloring(int s,int c1,int c2){
	mark[s] = true;
	color[s] = c2;

	for(int i=0;i<(int)G[s].size();i++){
		int v = G[s][i];
		if(!mark[v]){
			for(int j=0;j<3;j++){
				if(c1!=j && c2!=j){
					coloring(v,c2,j);
				}
			}
		}
	}
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

	for(int i=0;i<3;i++){
		for(int j=1;j<=n;j++){
			cin>>cost[i][j];
		}
	}

	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;

		G[x].pb(y);
		G[y].pb(x);
		deg[x]++;
		deg[y]++;
	}

	for(int i=1;i<=n;i++){
		if(deg[i]>2){cout<<"-1"<<endl;return 0;}
	}

	LL res = LLONG_MAX;

	if(deg[1] == 1){
		int fu,fv;
		int u = 1;
		int v = G[u][0];

		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(i==j){continue;}
				//cout<<"color of 1 --- "<<i<<endl;
				//cout<<"color of "<<v<<" ---- "<<j<<endl;

				LL ans = cost[i][u];
				//cout<<"Initial ans --- "<<ans<<endl;

				memset(mark,0,sizeof(mark));
				mark[1] = true;
				ans += dfs(v,i,j);
				//cout<<"computed ans ---- "<<ans<<endl;
				if(res > ans){
					res = ans;
					fu = i;
					fv = j;
				}
			}
		}
		memset(mark,0,sizeof(mark));
		mark[u] = true;

		color[u] = fu;
		color[v] = fv;

		coloring(v,fu,fv);
	}else{
		int fu,fv1,fv2;
		int u = 1;
		int v1 = G[u][0];
		int v2 = G[u][1];

		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				for(int k=0;k<3;k++){
					if(i!=j && j!=k && k!=i){
						LL ans = cost[i][u];
						memset(mark,0,sizeof(mark));
						mark[1] = true;
						ans+=(dfs(v1,i,j) + dfs(v2,i,k));
						if(res > ans){
							res = ans;
							fu = i;
							fv1 = j;
							fv2 = k;
						}
					}
				}
			}
		}

		color[u] = fu;
		color[v1] = fv1;
		color[v2] = fv2;
		memset(mark,0,sizeof(mark));
		mark[u] = true;

		coloring(v1,fu,fv1);
		coloring(v2,fu,fv2);
	}
	cout<<res<<endl;
	for(int i=1;i<=n;i++){
		cout<<color[i]+1<<" ";
	}cout<<endl;
}