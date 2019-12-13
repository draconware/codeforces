#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

LL arr[200009];
LL st[4*200009],lazy[4*200009];
LL inf = (LL)1e16;

void build(int s,int e,int idx){
	if(s==e){st[idx] = arr[s];return ;}
	int m = (s+e)/2;
	build(s,m,2*idx+1);
	build(m+1,e,2*idx+2);

	st[idx] = min(st[2*idx+1],st[2*idx+2]);
}

int query(int s,int e,int idx){
	if(lazy[idx]!=0){
		st[idx] += (lazy[idx]);
		if(s!=e){
			lazy[2*idx+1]+=lazy[idx];
			lazy[2*idx+2]+=lazy[idx];
		}
		lazy[idx] = 0;
	}
	if(s==e){
		return s;
	}
	int m = (s+e)/2;
	if((st[2*idx+2]+lazy[2*idx+2]) == 0){
		return query(m+1,e,2*idx+2);
	}else{
		return query(s,m,2*idx+1);
	}
}

void update(int s,int e,int idx,int l,int r,LL val){
	// cout<<s<<","<<e<<endl;
	if(lazy[idx]!=0){
		st[idx]+=lazy[idx];
		if(s!=e){
			lazy[2*idx+1]+=lazy[idx];
			lazy[2*idx+2]+=lazy[idx];
		}
		lazy[idx] = 0;
	}
	if(e<l || s>r){return ;}
	if(l<=s && r>=e){
		// cout<<l<<","<<r<<" "<<s<<","<<e<<endl;
		st[idx]+=val;
		if(s!=e){
			lazy[2*idx+1]+=val;
			lazy[2*idx+2]+=val;
		}
		return ;
	}
	int m = (s+e)/2;
	update(s,m,2*idx+1,l,r,val);
	update(m+1,e,2*idx+2,l,r,val);
	st[idx] = min(st[2*idx+1],st[2*idx+2]);
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

	build(1,n,0);

	vector<int> ans(n);
	int cnt=1;

	for(int i=1;i<=n;i++){
		int idx = query(1,n,0);
		ans[idx-1] = cnt;
		// cout<<i<<" ------ "<<endl;
		// cout<<idx<<endl;

		update(1,n,0,idx,idx,inf);
		update(1,n,0,idx+1,n,-cnt);

		// for(int j=0;j<9;j++){cout<<st[j]<<" ";}cout<<endl;
		// for(int j=0;j<9;j++){cout<<lazy[j]<<" ";}cout<<endl;
		cnt++;
	}
	for(int i=0;i<n;i++){cout<<ans[i]<<" ";}cout<<endl;
}