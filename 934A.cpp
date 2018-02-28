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

	int n,m;
	cin>>n>>m;

	vector<LL> a,b;
	for(int i=0;i<n;i++){
		LL x;cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	for(int i=0;i<m;i++){
		int x;cin>>x;
		b.push_back(x);
	}
	sort(b.begin(),b.end());

	LL ans1 = LLONG_MIN,ans2=LLONG_MIN;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m;j++){
			ans1 = max(ans1,a[i]*b[j]);
		}
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<m;j++){
			ans2 = max(ans2,a[i]*b[j]);
		}
	}
	cout<<min(ans1,ans2)<<endl;
}