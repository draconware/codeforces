#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

int deg[100009];

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

	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		deg[a]++;
		deg[b]++;
	}

	for(int i=1;i<=n;i++){
		if(deg[i]==2){cout<<"NO"<<endl;return 0;}
	}
	cout<<"YES"<<endl;
}