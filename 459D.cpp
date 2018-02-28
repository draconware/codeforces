#include<bits/stdc++.h>
using namespace std;

#define LL long long

map<int,int> mp;
int prefix[1000009];
LL st[4*1000009];

void update(int s,int e,int idx,int pos,LL val){
	if(s>e || s>pos || e<pos){
		return ;
	}
	if(s==e && s==pos){
		st[idx]+=val;
		return ;
	}
	int m = (s+e)/2;
	update(s,m,2*idx+1,pos,val);
	update(m+1,e,2*idx+2,pos,val);
	st[idx] = st[2*idx+1]+st[2*idx+2];
}

LL query(int s,int e,int idx,int pos){
	if(s>e){return 0;}
	if(e<=pos){return 0;}
	if(s>pos){return st[idx];}
	int m = (s+e)/2;
	return (query(s,m,2*idx+1,pos)+query(m+1,e,2*idx+2,pos));
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

	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		mp[arr[i]]++;
		prefix[i]=mp[arr[i]];
	}

	for(int i=0;i<n-1;i++){
		update(0,1000005,0,prefix[i],1LL);
	}

	mp.clear();
	LL ans = 0;
	for(int i=n-1;i>0;i--){
		mp[arr[i]]++;
		ans = ans + query(0,1000005,0,mp[arr[i]]);
		update(0,1000005,0,prefix[i-1],-1);
	}
	cout<<ans<<endl;
}