#include<bits/stdc++.h>
using namespace std;

#define LL long long 

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	LL n,m;
	cin>>n>>m;

	vector<pair<LL,LL> > v;
	for(int i=0;i<m;i++){
		LL a,b;
		cin>>a>>b;
		v.push_back(make_pair(a,b));
	}

	int sz = (int)v.size();

	LL ans = v[0].first - 1 + v[0].second;
	ans = max(ans,n - v[sz-1].first + v[sz-1].second);

	for(int i=1;i<sz;i++){
		LL x1,x2,x3;
		LL x = (v[i].first - v[i-1].first);
		LL y = (v[i].second - v[i-1].second);

		LL z1 = x+y;
		LL z2 = x-y;
		if(z1%2 == 0){
			x1 = z1/2;
			x2 = z2/2;
			x3 = 0;
		}else{
			x3 = 1;
			z1--;z2--;
			x1 = z1/2;
			x2 = z2/2;
		}
	//	cout<<i<<" ----- "<<x1<<","<<x2<<","<<x3<<endl;
		if((x1>=0) && (x2>=0) && (x3>=0)){
			ans = max(ans,v[i-1].second + x1);
		}else{
			cout<<"IMPOSSIBLE"<<endl;return 0;
		}
	}
	cout<<ans<<endl;
}