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

	int q;
	cin>>q;

	while(q--){
		int n;
		cin>>n;

		int ans=0;
		if(n%2 == 1){
			if(n<9 || n==11){cout<<"-1"<<endl;}
			else{
				ans++;n-=9;
				ans+=(n/4);
				cout<<ans<<endl;
			}
		}else{
			if(n==2){cout<<"-1"<<endl;}
			else{cout<<n/4<<endl;}
		}
	}
}