#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL arr[2*100009];
LL prefix[2*100009];
pair<LL,int> st[8*100009];

void build(int s,int e,int idx){
	if(s>e){return ;}
	if(s==e){st[idx].first = prefix[s];st[idx].second = s;return ;}
	int m = (s+e)/2;
	build(s,m,2*idx+1);
	build(m+1,e,2*idx+2);
	if(st[2*idx+1].first == st[2*idx+2].first){
		st[idx].first = st[2*idx+1].first;
		st[idx].second = min(st[2*idx+1].second,st[2*idx+2].second);
	}else{
		st[idx].first = max(st[2*idx+1].first,st[2*idx+2].first);
		if(st[idx].first == st[2*idx+1].first){st[idx].second = st[2*idx+1].second;}
		else{st[idx].second = st[2*idx+2].second;}
	}
}

pair<LL,int> query(int s,int e,int idx,int l,int r){
	if(s>e || l>r || s>r || l>e){return make_pair(-1,-1);}
	if(l<=s && r>=e){
		return st[idx];
	}
	int m = (s+e)/2;
	pair<LL,int> left = query(s,m,2*idx+1,l,r);
	pair<LL,int> right = query(m+1,e,2*idx+2,l,r);
//	cout<<s<<","<<m<<" "<<left.first<<","<<left.second<<endl;
//	cout<<m+1<<","<<e<<" "<<right.first<<","<<right.second<<endl;
	if(left.first == right.first){
		return make_pair(left.first,min(left.second,right.second));
	}else{
		if(left.first > right.first){return left;}
		else{return right;}
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

	int n,k;
	cin>>n>>k;

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	LL sum=0;
	for(int i=0;i<k;i++){
		sum = sum + arr[i];
	}

	for(int i=0;i<n-k+1;i++){
		prefix[i] = sum;
		sum = sum - arr[i];
		if(i+k < n){sum = sum + arr[i+k];}
	}
	int m = n-k+1;
	//for(int i=0;i<m;i++){cout<<prefix[i]<<" ";}cout<<endl;

	build(0,m-1,0);
	//cout<<endl;
	
	LL l=0,r=0;
	LL ans = 0;
//	cout<<m<<endl;
	for(int i=0;i<m;i++){
		pair<LL,int> p = query(0,m-1,0,i+k,m-1);
		//cout<<p.first<<" "<<p.second<<" ";
		if(ans < (prefix[i]+p.first)){
			l = i+1;
			r = p.second + 1;
			ans = prefix[i]+p.first;
		}
		//cout<<ans<<endl;
	}
	//cout<<endl;

	cout<<l<<" "<<r<<endl;
}