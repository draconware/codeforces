#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

bool mark[100009];

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
		int n,r;
		cin>>n>>r;

		vector<int> v;
		for(int i=0;i<n;i++){
			int x;cin>>x;
			if(!mark[x]){mark[x]=true;v.pb(x);}
		}
		sort(v.begin(),v.end());

		n = (int)v.size();
		for(int i=0;i<n;i++){mark[v[i]]=false;}

		int ans = 0;
		int cnt = 0;
		for(int i=n-1;i>=0;i--){
			cnt++;
			int needed = v[i]/r + ((v[i]%r==0)?0:1);
			//cout<<needed<<","<<cnt<<endl;
			ans = max(ans,min(cnt,needed));
		}
		cout<<ans<<endl;
	}
}