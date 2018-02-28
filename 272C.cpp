#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL arr[100009];
LL st[4*100009];
LL lazy[4*100009];

void build(int s,int e,int idx){
	if(s>e){return ;}
	if(s==e){st[idx] = arr[s];return ;}

	int m = (s+e)/2;
	build(s,m,2*idx+1);
	build(m+1,e,2*idx+2);
	st[idx] = max(st[2*idx+1],st[2*idx+2]);
}

LL query(int s,int e,int idx,int l,int r){
	if(lazy[idx] != 0LL){
		st[idx] = lazy[idx];
		if(s!=e){
			lazy[2*idx+1] = lazy[idx];
			lazy[2*idx+2] = lazy[idx];
		}
		lazy[idx] = 0LL;
	}
	if(s>e || l>r || s>r || l>e){return 0LL;}
	if(l<=s && r>=e){
		return st[idx];
	}
	int m = (s+e)/2;
	return max(query(s,m,2*idx+1,l,r) , query(m+1,e,2*idx+2,l,r));
}

void update(int s,int e,int idx,int l,int r,LL val){
	if(lazy[idx] != 0){
		st[idx] = lazy[idx];
		if(s!=e){
			lazy[2*idx+1] = lazy[idx];
			lazy[2*idx+2] = lazy[idx];
		}
		lazy[idx] = 0;
	}
	if(s>e || l>r || s>r || l>e){return ;}
	if(l<=s && r>=e){
		st[idx] = val;
		if(s!=e){
			lazy[2*idx+1] = st[idx];
			lazy[2*idx+2] = st[idx];
		}
		return ;
	}
	int m = (s+e)/2;
	update(s,m,2*idx+1,l,r,val);
	update(m+1,e,2*idx+2,l,r,val);

	st[idx] = max(st[2*idx+1],st[2*idx+2]);
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

	for(int i=0;i<n;i++){cin>>arr[i];}

	build(0,n-1,0);

	int m;
	cin>>m;

	for(int i=0;i<m;i++){
		int w;
		LL h;
		cin>>w>>h;
		LL ans = query(0,n-1,0,0,w-1);
		update(0,n-1,0,0,w-1,h+ans);
		cout<<ans<<endl;
	}
}