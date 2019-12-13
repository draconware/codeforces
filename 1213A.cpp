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

	int odd=0,even=0;

	for(int i=0;i<n;i++){
		int x;cin>>x;
		if(x%2){odd++;}
		else{even++;}
	}
	cout<<min(odd,even)<<endl;
}