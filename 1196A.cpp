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
		LL a,b,c;
		cin>>a>>b>>c;

		vector<LL> v;
		v.pb(a);v.pb(b);v.pb(c);
		sort(v.begin(),v.end());
		a = v[0];b = v[1];c = v[2];

		if(a >= (b+c)){cout<<(b+c)<<endl;}
		else{
			c -= (a-b);
			a += (c/2);
			cout<<a<<endl;
		}
	}
}