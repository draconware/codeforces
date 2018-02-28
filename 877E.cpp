#include<bits/stdc++.h>
using namespace std;

#define rep(i,k,n) for(int i=k;i<=n;i++)
#define ll long long
#define elif else if
#define ff first
#define ss second
#define pii pair<ll int,ll int>
#define mp make_pair
#define pb push_back
#define CLEAR(array, value) memset(ptr, value, sizeof(array));
#define si(a)     scanf("%d", &a)
#define sl(a)     scanf("%lld", &a)
#define pi(a)     printf("%d", a)
#define pl(a)     printf("%lld", a)
#define sll2(m,n) scanf("%lld%lld",&(m),&(n))
#define sll3(m,n,o) scanf("%lld%lld%lld",&(m),&(n),&(o))
#define sll4(m,n,o,p) scanf("%lld%lld%lld%lld",&(m),&(n),&(o),&(p))
#define sdd(n) scanf("%lf",&(n))
#define sdd2(m,n) scanf("%lf%lf",&(m),&(n))
#define sdd3(m,n,o) scanf("%lf%lf%lf",&(m),&(n),&(o))
#define sdd4(m,n,o,p) scanf("%lf%lf%lf%lf",&(m),&(n),&(o),&(p))
#define pn        printf("\n")
#define s(a) sort(a.begin(),a.end())
# define INF 0x3f3f3f3f
vector <ll> graph[200005];
ll arr[200005];
ll s[200005];
ll e[200005];
ll order[200005];
ll segtree[10000009];
ll lazy[10000009];
ll t=1;
void dfs(ll root,ll parent)
{
	order[t]=root;
	s[root]=t;
	for(ll i=0;i<graph[root].size();i++)
	{
		if(graph[root][i]!=parent)
		{
			t++;
			dfs(graph[root][i],root);
		}
	}
	e[root]=t;
}
void build(ll node,ll start,ll end)
{
	if(start==end)
	{
		segtree[node]=arr[order[start]];
	}
	else
	{
		ll mid=(start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		segtree[node]=segtree[2*node]+segtree[2*node+1];
	}
}
void update(ll node,ll start,ll end,ll l,ll r)
{
	if(lazy[node]!=0)
	{
		segtree[node]=end-start+1-segtree[node];
		if(start!=end)
		{
			lazy[2*node]^=1;
			lazy[2*node+1]^=1;
		}
		lazy[node]=0;
	}
	if(start>end or start>r or end<l)
		return;
	if(start>=l and end<=r)
	{
		segtree[node]=end-start+1-segtree[node];
		if(start!=end)
		{
			lazy[2*node]^=1;
			lazy[2*node+1]^=1;
		}
		return;
	}
	ll mid=(end+start)/2;
	update(2*node,start,mid,l,r);
	update(2*node+1,mid+1,end,l,r);
	segtree[node]=segtree[2*node]+segtree[2*node+1];

}
ll rangequery(ll node,ll start,ll end,ll l,ll r)
{
	if(start>end || start>r||end<l)
		return 0;
	if(lazy[node]!=0)
	{
		segtree[node]=end-start+1-segtree[node];
		if(start!=end)
		{
			lazy[2*node]^=1;
			lazy[2*node+1]^=1;
		}
		lazy[node]=0;
	}
	if(start>=l and end<=r)
		return segtree[node];
	ll mid=(start+end)/2;
	ll p1=rangequery(node*2,start,mid,l,r);
	ll p2=rangequery(node*2+1,mid+1,end,l,r);
	return p1+p2;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	memset(lazy,0,sizeof(lazy));
	ll n;
	cin>>n;
	rep(i,2,n)
	{
		ll x;
		cin>>x;
		graph[i].pb(x);
		graph[x].pb(i);
	}
	rep(i,1,n)
	{
		cin>>arr[i];
	}
	dfs(1,0);
	/*for(int i=1;i<=n;i++)
		cout<<s[i]<<" "<<e[i]<<endl;
	rep(i,1,n)
		cout<<order[i]<<" ";*/
	build(1,1,n);
	/*rep(i,1,7)
		cout<<i<<" "<<segtree[i]<<endl;*/
	ll q;
	cin>>q;
	while(q--)
	{
		string s2;
		cin>>s2;
		ll p;
		cin>>p;
		if(s2[0]=='g')
		{
			cout<<rangequery(1,1,n,s[p],e[p])<<endl;
		}
		else
		{
			update(1,1,n,s[p],e[p]);
		}

	}
}