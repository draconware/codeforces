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
		int n;
		cin>>n;

		LL ep=0,op=0,eq=0,oq=0;
		for(int i=0;i<n;i++){
			int x;cin>>x;
			if(x%2){op++;}
			else{ep++;}
		}

		int m;
		cin>>m;

		for(int i=0;i<m;i++){
			int x;cin>>x;
			if(x%2){oq++;}
			else{eq++;}
		}
		// cout<<n<<" "<<m<<endl;
		// cout<<op<<","<<ep<<" "<<oq<<","<<eq<<endl;

		cout<<(op*oq + eq*ep)<<endl;
	}
}