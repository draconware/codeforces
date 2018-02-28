#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	double r,d;
	cin>>r>>d;

	int m;
	cin>>m;

	int ans=0;
	while(m--){
		double x,y,r1;
		cin>>x>>y>>r1;

		double res = sqrt(x*x + y*y);
		if(res+r1<=r && res-r1>=(r-d)){ans++;}
	}
	cout<<ans<<endl;
}