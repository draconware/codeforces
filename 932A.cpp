#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin>>s;

	int n = (int)s.length();

	cout<<s;
	for(int i=n-1;i>=0;i--){cout<<s[i];}
	cout<<endl;
}