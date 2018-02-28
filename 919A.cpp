#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	double m;
	cin>>n>>m;

	double ans = DBL_MAX;
	for(int i=0;i<n;i++){
		double a,b;
		cin>>a>>b;
		ans = min(ans,m*(a/b));
	}
	printf("%.13lf\n",ans);
}