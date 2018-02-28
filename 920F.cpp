#include<bits/stdc++.h>
using namespace std;

#define LL long long 
int divisors[1000009];
int MAX = (int)(1e6);
int arr[300009];
pair<LL,int> st[4*300009];

void build(int s,int e,int idx){
	if(s>e){return ;}
	if(s==e){
		st[idx].first = (LL)arr[s];
		st[idx].second = arr[s];
		return ;
	}
	int m = (s+e)/2;
	build(s,m,2*idx+1);
	build(m+1,e,2*idx+2);
	st[idx].first = st[2*idx+1].first+st[2*idx+2].first;
	st[idx].second = max(st[2*idx+1].second,st[2*idx+2].second);
}

void update(int s,int e,int idx,int l,int r){
	if(s>e || s>r || l>e || l>r){return ;}
	if(l<=s && r>=e){
		if(s==e){
			arr[s] = divisors[arr[s]];
			st[idx].first = arr[s];
			st[idx].second = arr[s];
		}else{
			int m = (s+e)/2;
			if(st[2*idx+1].second > 2){
				update(s,m,2*idx+1,l,r);
			}
			if(st[2*idx+2].second > 2){
				update(m+1,e,2*idx+2,l,r);
			}
			st[idx].first = st[2*idx+1].first + st[2*idx+2].first;
			st[idx].second = max(st[2*idx+1].second,st[2*idx+2].second);
		}
		return ;
	}
	int m = (s+e)/2;
	update(s,m,2*idx+1,l,r);
	update(m+1,e,2*idx+2,l,r);
	st[idx].first = st[2*idx+1].first+st[2*idx+2].first;
	st[idx].second = max(st[2*idx+1].second,st[2*idx+2].second);
}

LL query(int s,int e,int idx,int l,int r){
	if(s>e || s>r || l>e || l>r){return 0LL;}
	if(l<=s && r>=e){
		return st[idx].first;
	}
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

	int n,m;
	cin>>n>>m;

	divisors[1] =1;
	for(int i=2;i<=MAX;i++){
		divisors[i] = 2;
	}
	for(int i=2;i<=MAX/2;i++){
		for(int j=2*i;j<=MAX;j+=i){
			divisors[j]++;
		}
	}
	//for(int i=2;i<=10;i++){cout<<divisors[i]<<" ";}cout<<endl;
	for(int i=0;i<n;i++){cin>>arr[i];}

	build(0,n-1,0);
	for(int i=0;i<m;i++){
		int type;
		cin>>type;
		if(type == 1){
			int x,y;
			cin>>x>>y;
			update(0,n-1,0,x-1,y-1);
		}else{
			int x,y;
			cin>>x>>y;
			cout<<query(0,n-1,0,x-1,y-1)<<endl;
		}
	}
}