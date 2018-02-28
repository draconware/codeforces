#include<bits/stdC++.h>
using namespace std;

#define LL long long

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	LL n,m,k;
	cin>>n>>m>>k;

	LL x,s;
	cin>>x>>s;

	vector<LL> a,ff,b,ss;
	for(int i=0;i<m;i++){
		LL x;
		cin>>x;
		a.push_back(x);
	}
	for(int i=0;i<m;i++){
		LL x;
		cin>>x;
		ff.push_back(x);
	}
	for(int i=0;i<k;i++){
		LL x;
		cin>>x;
		b.push_back(x);
	}
	for(int i=0;i<k;i++){
		LL x;
		cin>>x;
		ss.push_back(x);
	}

	LL ans=n*x;
	for(int i=0;i<m;i++){
		if(s>=ff[i]){ans = min(ans,n*a[i]);}
	}
	for(int i=0;i<k;i++){
		if(s>=ss[i]){ans = min(ans,(n-b[i])*x);}
	}
	for(int i=0;i<m;i++){
		LL x = ff[i];
		vector<LL>::iterator it = upper_bound(ss.begin(),ss.end(),s-x);
		if(it!=ss.begin()){
			it--;
			int j = it-ss.begin();
			ans = min(ans,a[i]*(n-b[j]));
		}
	}
	cout<<ans<<endl;
}