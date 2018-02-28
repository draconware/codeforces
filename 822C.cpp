#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > temp[200009];
vector<int> check[200009];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,x,size=0;
	cin>>n>>x;

	vector<pair<pair<int,int>,pair<int,int> > > v;
	for(int i=0,a,b,c;i<n;i++){
		cin>>a>>b>>c;
		v.push_back(make_pair(make_pair(b-a+1,c),make_pair(a,b)));
		temp[b-a+1].push_back(make_pair(b,c));
		size=max(size,b-a+1);
	}
	cout<<"executed"<<endl;
	for(int i=0;i<200009;i++){sort(temp[i].begin(),temp[i].end());}
	//cout<<"executed"<<endl;
	for(int i=0;i<200009;i++){
		for(int j=0;j<(int)temp[i].size();j++){
			check[i][j] = temp[i][j].first;
		}
	}
	//cout<<"executed"<<endl;
	sort(v.begin(),v.end());
	vector<int> l,r,cost;
	for(int i=0;i<n;i++){
		l.push_back(v[i].second.first);
		r.push_back(v[i].second.second);
		cost.push_back(v[i].first.second);
	}
	//for(int i=0;i<n;i++){cout<<l[i]<<" ";}cout<<endl;
	//for(int i=0;i<n;i++){cout<<r[i]<<" ";}cout<<endl;
	//for(int i=0;i<n;i++){cout<<cost[i]<<" ";}cout<<endl;
	//for(int i=0;i<n;i++){cout<<y[i]<<" ";}cout<<endl;
	int best=INT_MAX;
	for(int i=0;i<n;i++){
		int a = v[i].first.first;
		if(a>x){break;}
		int b = x-a;
		vector<int>::iterator it = upper_bound(check[b].begin(),check[b].end(),v[i].second.second);
		if(it != check[b].end()){
			best = min(best,cost[i]+temp[b][it-check[b].begin()].second);
		}
	}
	if(best==INT_MAX){cout<<"-1"<<endl;}
	else{cout<<best<<endl;}

}