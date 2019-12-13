#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

int cnt[3000];

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

		vector<int> v;

		for(int i=0;i<n;i++){
			int x;cin>>x;
			if(x<=2048){v.pb(x);}
		}

		sort(v.begin(),v.end());
		n = (int)v.size();

		memset(cnt,0,sizeof(cnt));

		for(int i=0;i<n;i++){
			cnt[v[i]]++;
		}

		int m = 2048,req=1;
		bool flag=false;
		while(m>0){
			if(cnt[m] >= req){
				flag=true;break;
			}else{
				req-=cnt[m];
				req*=2;
				m/=2;
			}
		}
		if(flag){cout<<"YES"<<endl;}
		else{cout<<"NO"<<endl;}
	}
}