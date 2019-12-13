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

	int n;
	cin>>n;

	string s;cin>>s;
	vector<int> v;

	LL ans = (1LL*n*(n-1))/2;

	for(int i=0;i<n;){
		int j = i;
		while(j<n){
			if(s[i]==s[j]){j++;}
			else{break;}
		}
		v.pb(j-i);
		i=j;
	}

	for(int i=0;i<(int)v.size()-1;i++){
		LL x = v[i];
		LL y = v[i+1];

		ans-=x;ans-=y;ans++;
	}
	cout<<ans<<endl;
}