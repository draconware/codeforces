#include<bits/stdc++.h>
using namespace std;

bool comp(pair<pair<int,int>,int> &x,pair<pair<int,int>,int> &y){
	if((x.first.first==y.first.first && x.first.second>y.first.second) || (x.first.first < y.first.first)){
		return true;
	}
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	cin>>n;

	vector<pair<pair<int,int>,int> > v;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		v.push_back(make_pair(make_pair(x,y),i+1));
	}
	sort(v.begin(),v.end(),comp);
	//for(int i=0;i<n;i++){cout<<v[i].first.first <<" "<<v[i].first.second<<endl; }
	int end=-1;
	//bool flag=false;
	for(int i=0;i<n;i++){
		//cout<<end<<endl;
		if(end>=v[i].first.second){
			cout<<v[i].second<<endl;return 0;
		}
		end = max(end,v[i].first.second);
	}
	for(int i=1;i<n-1;i++){
		if(v[i-1].first.second + 1 >= v[i+1].first.first){cout<<v[i].second<<endl;return 0;}
	}
	cout<<"-1"<<endl;return 0;
}