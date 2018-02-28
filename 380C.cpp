#include<bits/stdc++.h>
using namespace std;

string arr;
pair<int,pair<int,int> > st[4*1000009];

void build(int s,int e,int idx){
	if(s>e){return ;}
	if(s==e){
		if(arr[s]=='('){st[idx] = make_pair(0,make_pair(1,0));}
		else{st[idx] = make_pair(0,make_pair(0,1));}
		return ;
	}
	int m = (s+e)/2;
	build(s,m,2*idx+1);
	build(m+1,e,2*idx+2);

	st[idx].first = st[2*idx+1].first + st[2*idx+2].first + min(st[2*idx+1].second.first,st[2*idx+2].second.second);
	st[idx].second.first = st[2*idx+1].second.first + st[2*idx+2].second.first - min(st[2*idx+1].second.first,st[2*idx+2].second.second);
	st[idx].second.second = st[2*idx+1].second.second + st[2*idx+2].second.second - min(st[2*idx+1].second.first,st[2*idx+2].second.second);
}

pair<int,pair<int,int> > query(int s,int e,int idx,int l,int r){
	if(s>e || l>r || s>r || l>e){return make_pair(0,make_pair(0,0));}
	if(l<=s && r>=e){return st[idx];}

	int m = (s+e)/2;
	pair<int,pair<int,int> > left = query(s,m,2*idx+1,l,r);
	pair<int,pair<int,int> > right = query(m+1,e,2*idx+2,l,r);

	pair<int,pair<int,int> > res ;
	res.first = left.first + right.first + min(left.second.first , right.second.second);
	res.second.first = left.second.first + right.second.first - min(left.second.first , right.second.second);
	res.second.second = left.second.second + right.second.second - min(left.second.first , right.second.second);
	return res;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>arr;
	int n = (int)arr.length();

	build(0,n-1,0);

	int q;
	cin>>q;

	while(q--){
		int l,r;
		cin>>l>>r;
		l--;r--;
		cout<<2*query(0,n-1,0,l,r).first<<endl;
	}
}