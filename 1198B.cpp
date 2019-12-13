#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

int lazy[4*300009],arr[200009];

void update(int s,int e,int idx,int p,int x){
	if(lazy[idx]!=0){
		lazy[2*idx+1] = max(lazy[2*idx+1],lazy[idx]);
		lazy[2*idx+2] = max(lazy[2*idx+2],lazy[idx]);
		lazy[idx] = 0;
	}
	if(s==e){
		lazy[idx] = 0;
		return ;
	}
	int m = (s+e)/2;
	if(p<=m){
		update(s,m,2*idx+1,p,x);
	}else{
		update(m+1,e,2*idx+2,p,x);
	}
}

void solve(int s,int e,int idx){
	if(lazy[idx]!=0){
		lazy[2*idx+1] = max(lazy[2*idx+1],lazy[idx]);
		lazy[2*idx+2] = max(lazy[2*idx+2],lazy[idx]);
	}
	if(s==e){
		arr[s] = max(arr[s] , lazy[idx]);return ;
	}
	int m = (s+e)/2;
	solve(s,m,2*idx+1);
	solve(m+1,e,2*idx+2);
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

	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}

	int q;
	cin>>q;

	while(q--){
		int t;cin>>t;
		if(t==1){
			int p,x;
			cin>>p>>x;

			update(1,n,0,p,x);
			arr[p] = x;
		}else{
			int x;cin>>x;
			lazy[0] = max(lazy[0],x);
		}
		// for(int i=0;i<7;i++){cout<<lazy[i]<<" ";}cout<<endl;
	}

	solve(1,n,0);

	for(int i=1;i<=n;i++){cout<<arr[i]<<" ";}cout<<endl;
}