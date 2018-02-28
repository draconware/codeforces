#include<bits/stdc++.h>
using namespace std;
	
string arr;
pair<int,pair<int,int> > st[4*1000009];

void build(int s,int e,int idx){
	if(s>e){return ;}
	if(s==e){
		int x=0,y=0;
		if(arr[s] == '('){x++;}
		else{y++;}
		st[idx] = make_pair(0,make_pair(x,y));
		return ;
	}
	int m = (s+e)/2;
	build(s,m,2*idx+1);
	build(m+1,e,2*idx+2);

	st[idx].first = st[2*idx+1].first + st[2*idx+2].first + min(st[2*idx+1].second.first,st[2*idx+2].second.second);
	st[idx].second.first = st[2*idx+1].second.first + st[2*idx+2].second.first - min(st[2*idx+1].second.first,st[2*idx+2].second.second);
	st[idx].second.second = st[2*idx+1].second.second + st[2*idx+2].second.second - min(st[2*idx+1].second.first,st[2*idx+2].second.second);
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

	cout<<2*st[0].first<<endl;
}