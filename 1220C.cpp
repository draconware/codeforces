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

	string s;cin>>s;
	int n = (int)s.length();

	char c = 'z';
	for(int i=0;i<n;i++){
		c = min(c,s[i]);
		if(c < s[i]){cout<<"Ann"<<endl;}
		else{cout<<"Mike"<<endl;}
	}
}