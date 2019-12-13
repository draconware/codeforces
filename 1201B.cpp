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

	LL sum=0;
	vector<int> v;
	for(int i=0;i<n;i++){
		int x;cin>>x;v.pb(x);
		sum+=x;
	}
	sort(v.begin(),v.end());
	if(sum%2 || (v[n-1]>(sum-v[n-1]))){cout<<"NO"<<endl;}
	else{cout<<"YES"<<endl;}
}