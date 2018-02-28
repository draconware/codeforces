#include<bits/stdc++.h>
using namespace std;

#define LL long long

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

	int s=0,e=n;
	int ans=0;
	while(s<e){
		ans += (e-s);
		e--;s++;
	}
	cout<<ans<<endl;
}