#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif


	int n;
	cin>>n;

	int m = (int)sqrt(n);
	int ans = (4*m);

	n-=(m*m);
	ans = ans + 2*(int)ceil((float)n/(float)m);
	cout<<ans<<endl;
}