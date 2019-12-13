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
		int n,m,k;
		cin>>n>>m>>k;
	
		vector<int> v;
	
		for(int i=0;i<n;i++){
			int x;cin>>x;
			v.pb(x);
		}
		// for(int i=0;i<n;i++){
		// 	cout<<v[i]<<" ";
		// }cout<<endl;
	
		bool flag=true;
	
		for(int i=1;i<n;i++){
			// cout<<m<<endl;
			int a = v[i-1];
			int b = v[i];
			// cout<<a<<" "<<b<<endl;
	
			if(a>=b){
				m+=(a-b);
				m+=min(b,k);
			}else{
				int diff = b-a;
				// cout<<"diff --- "<<diff<<endl;
				// cout<<"k ---- "<<k<<endl;
				if(diff>k){
					if(m>=(diff-k)){
						m-=(diff-k);
					}else{
						flag=false;break;
					}
				}else{
					m+=min(v[i-1],(k-diff));
				}
			}
		}
		if(flag){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
}