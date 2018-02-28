#include<bits/stdc++.h>
using namespace std;

int st[4*100009];
int mark[100009];
int n;

void build(int s,int e,int idx){
	if(s>e){return ;}
	if(s==e){
		st[idx] = 1;
		return ;
	}
	int m = (s+e)/2;
	build(s,m,2*idx);
	build(m+1,e,2*idx+1);
	st[idx] = max(st[2*idx],st[2*idx+1]);
}

int query(int s,int e,int idx,int l,int r){
	if(s>e || l>r || s>r || l>e){return 0;}
	if(l<=s && r>=e){return st[idx];}
	int m = (s+e)/2;
	return max(query(s,m,2*idx,l,r),query(m+1,e,2*idx+1,l,r));
}

void update(int s,int e,int idx,int pos,int val){
	if(s>e || s>pos || e<pos){return ;}
	if(s==e && s==pos){st[idx] = val;return ;}

	int m = (s+e)/2;
	update(s,m,2*idx,pos,val);
	update(m+1,e,2*idx+1,pos,val);
	st[idx] = max(st[2*idx+1],st[2*idx]);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	build(1,n,1);
	//cout<<"executed"<<endl;

	int minvalue = arr[0];
	int dp[n];
	for(int i=0;i<n;i++){dp[i] = 1;}

	for(int i=1;i<n;i++){
		dp[i] = max(dp[i],1+query(1,n,1,minvalue,arr[i]-1));
		update(1,n,1,arr[i],dp[i]);
		minvalue = min(minvalue,arr[i]);
	}

	int ans = 1;
	for(int i=0;i<n;i++){ans = max(ans,dp[i]);}
	cout<<ans<<endl;
}
