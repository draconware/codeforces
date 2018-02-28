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
	cin>>n;

	int ans = 0;
	for(int i=1;i*i<=n;i++){
		if(n%i == 0){
			if(i!=n){ans++;}
			if(n/i != n && n/i != i){ans++;}
		}
	}
	cout<<ans<<endl;
}