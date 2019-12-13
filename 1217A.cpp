#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin>>t;

	while(t--){
		int s,i,e;
		cin>>s>>i>>e;

		if(e==0){
			if(s>i){cout<<"1"<<endl;}
			else{cout<<"0"<<endl;}
			continue;
		}

		int ans=0;

		int l=0,r=e,idx=r+1;

		while(l<=r){
			int m = (l+r)/2;
			if((s+m)>(i+(e-m))){
				idx = m;
				r = m-1;
			}else{
				l = m+1;
			}
		}
		ans+=((e+1 - idx));
		cout<<ans<<endl;
	}
}