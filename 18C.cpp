#include<bits/stdc++.h>
using namespace std;

int n;
int arr[100009];
int st[4*100009];

void build(int s,int e,int idx){
	if(s>e){return ;}
	if(s==e){
		st[idx] = arr[s];
		return ;
	}
	int m = (s+e)/2;
	build(s,m,2*idx+1);
	build(m+1,e,2*idx+2);
	st[idx] = st[2*idx+1] + st[2*idx+2];
}

int query(int s,int e,int idx,int l,int r){
	if(s>e || l>r || s>r || l>e){
		return 0;
	}
	if(l<=s && r>=e){return st[idx];}
	int m = (s+e)/2;
	return (query(s,m,2*idx+1,l,r) + query(m+1,e,2*idx+2,l,r));
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

	for(int i=0;i<n;i++){cin>>arr[i];}

	build(0,n-1,0);
	int ans = 0;
	for(int i=0;i<n-1;i++){
		int x = query(0,n-1,0,0,i);
		int y = query(0,n-1,0,i+1,n-1);
		if(x==y){ans++;}
	}
	cout<<ans<<endl;
}