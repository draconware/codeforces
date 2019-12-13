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
		int a,b,n;
		cin>>a>>b>>n;

		if(n%3 == 0){
			cout<<a<<endl;
		}else if((n-1)%3 == 0){
			cout<<b<<endl;
		}else{
			cout<<(a^b)<<endl;
		}
	}
}