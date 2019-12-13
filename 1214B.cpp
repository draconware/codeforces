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

	int b,g,n;
	cin>>b>>g>>n;

	int ans=0;
	if(b>=n){
		if(g>=n){
			ans+=(n+1);
		}else{
			ans+=(g+1);
		}
	}else{
		if(g>=n){
			ans+=(b+1);
		}else{
			int i=b,j=n-b;
			ans++;
			while(j!=g){
				if(j<g){j++;}
				else{j--;}
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}