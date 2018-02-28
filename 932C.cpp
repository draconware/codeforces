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

	int n,a,b;
	cin>>n>>a>>b;

	int x=n;
	int res[n+9];

	int k1=0,k2=0;

	int t = a;
	a = min(a,b);
	b = max(t,b);

	for(k1=0;x>=k1*a;k1++){
		//cout<<k1<<" "<<(x - k1*a)<<endl;
		if((x - k1*a)%b == 0){break;}
	}
	x = x - k1*a;
	//cout<<k1<<" "<<k2<<endl;
	if((x<0) || ((x%b)!=0)){cout<<"-1"<<endl;return 0;}
	k2 = x/b;
	
	int i=1;

	while(k1>0 && i<=n){
		for(int j=i+1;j<(a+i);j++){
			res[j] = j-1;
		}
		res[i] = a+i-1;
		i = i+a;
		k1--;
	}
	while(k2>0 && i<=n){
		for(int j=i+1;j<(i+b);j++){
			res[j] = j-1;
		}
		res[i] = b+i-1;
		i = i+b;
		k2--;
	}
	for(int c=1;c<=n;c++){cout<<res[c]<<" ";}cout<<endl;
}