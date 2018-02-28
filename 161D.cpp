#include <bits/stdc++.h>

using namespace std;

int n,k;
long long dp[50005][505];
long long res[50005];
vector<int> adj[50005];

void dfs(int v,int pv)
{
    if(adj[v].size()==1 && v!=pv)
    {
        dp[v][0]=1;
        for(int i=1;i<=k;i++)dp[v][i]=0;
        res[v]=0;
        return;
    }

    for(int x=0;x<(int)adj[v].size();x++)if(adj[v][x]!=pv)dfs(adj[v][x],v);

    for(int i=0;i<=k;i++)dp[v][i]=0;
    res[v]=0;
    dp[v][0]=1;

    for(int x=0;x<(int)adj[v].size();x++){
        for(int i=1;i<=k;i++)dp[v][i]+=dp[adj[v][x]][i-1];
    }

    for(int x=0;x<(int)adj[v].size();x++){
        for(int i=1;i<k;i++)res[v]+=(dp[v][k-i]-dp[adj[v][x]][k-i-1])*dp[adj[v][x]][i-1];
    }
    res[v]/=2;

    for(int x=0;x<(int)adj[v].size();x++)res[v]+=res[adj[v][x]]+dp[adj[v][x]][k-1];
}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if(k==1){
        cout<<n-1<<endl;
        return 0;
    }

    dfs(1,1);

    cout<<res[1]<<endl;
    return 0;
}