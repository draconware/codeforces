#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif


	int n;
	cin>>n;

	vector<pair<int,int> > v;
	for(int x,y,i=0;i<n;i++){
		cin>>x>>y;
		v.push_back(make_pair(x,y));
	}
	sort(v.begin(),v.end());
	bool flag=true;

	int l1=-1,r1=-1,l2=-1,r2=-1;
	for(int i=0;i<n;i++){
		if(r1 < v[i].first){r1=v[i].second;}
		else if(r2 < v[i].first){r2=v[i].second;}
		else{flag=false;break;}
	}
	if(flag){cout<<"YES"<<endl;}
	else{cout<<"NO"<<endl;}
}