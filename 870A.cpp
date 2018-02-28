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

	int n,m;
	cin>>n>>m;

	int mark[10],marka[10],markb[10],a[n],b[m];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	for(int i=1;i<=9;i++){
		bool f=false,s=false;
		for(int j=0;j<n;j++){if(a[j]==i){f=true;}}
		for(int j=0;j<m;j++){if(b[j]==i){s=true;}}
		if(f && s){cout<<i<<endl;return 0;}
	}
	sort(a,a+n);sort(b,b+m);
	cout<<min(a[0],b[0])<<max(a[0],b[0])<<endl;
}