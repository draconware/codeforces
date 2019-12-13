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

	int n,l,r;
	cin>>n>>l>>r;

	vector<int> v;

	for(int i=0;i<l;i++){
		v.pb(1<<i);
	}
	for(int i=l;i<n;i++){
		v.pb(1);
	}

	int mini = 0;
	for(int i=0;i<n;i++){mini+=v[i];}
	v.clear();

	for(int i=0;i<r;i++){
		v.pb(1<<i);
	}
	for(int i=r;i<n;i++){
		v.pb(1<<(r-1));
	}
	int maxi = 0;
	for(int i=0;i<n;i++){maxi+=v[i];}
	v.clear();
	cout<<mini<<" "<<maxi<<endl;
}