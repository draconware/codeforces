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

	vector<int> v;
	int tot=0;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		v.pb(x);
		tot+=x;
	}

	int sum=v[0];
	int i=1;

	vector<int> ans;
	ans.pb(0);

	while(i<n){
		if(2*sum > (tot)){
			break;
		}else{
			if(v[i]*2<=v[0]){
				sum+=v[i];
				ans.pb(i);
			}
		}
		i++;
	}

	if(2*sum > (tot)){
		cout<<(int)ans.size()<<endl;
		for(int i=0;i<(int)ans.size();i++){
			cout<<ans[i]+1<<" ";
		}cout<<endl;
	}else{
		cout<<"0"<<endl;
	}
}