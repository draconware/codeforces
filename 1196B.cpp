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
		int n,k;
		cin>>n>>k;

		vector<int> v;

		for(int i=0;i<n;i++){
			int x;cin>>x;
			v.pb(x%2);
		}

		bool flag=true;
		vector<pii> ans;

		for(int i=0;i<n;){
			int sum=0;
			int j=i;

			if(k==1){
				while(j<n){
					sum+=v[j];
					j++;
				}
				if(sum%2){ans.pb(mp(i+1,j));}
				else{flag=false;break;}
				i = j;
				k--;
			}else{
				while(j<n && (sum%2 == 0)){
					sum+=v[j];j++;
				}
				if((sum%2 == 0)){
					flag=false;break;
				}
				ans.pb(mp(i+1,j));
				i = j;
				k--;
			}
		}
		if(k>0){cout<<"NO"<<endl;continue;}
		if(!flag){cout<<"NO"<<endl;continue;}
		cout<<"YES"<<endl;
		for(int i=0;i<(int)ans.size();i++){
			cout<<ans[i].second<<" ";
		}
		cout<<endl;
	}
}