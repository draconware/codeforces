#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,k;
	cin>>n>>k;

	LL cost[n+1];
	for(int i=1;i<=n;i++){cin>>cost[i];}
	
	priority_queue<pair<LL,int> > q;
	for(int i=1;i<=min(n,k+1);i++){
		q.push(make_pair(cost[i],i));
	}
	//cout<<"executed"<<endl;
	int t = k+1;
	LL ans=0;
	vector<int> res(n+1);
	while(!q.empty()){
		pair<LL,int> p = q.top();q.pop();
		ans += (LL)(t-p.second)*(p.first);
		res[p.second] = t;
		t++;
		if(t<=n){
			q.push(make_pair(cost[t],t));
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++){cout<<res[i]<<" ";}cout<<endl;
}