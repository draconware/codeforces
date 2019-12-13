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

		vector<int> v;
		for(int i=0;i<n;i++){
			int x;cin>>x;v.pb(x);
		}
		if(n==1){cout<<"YES"<<endl;continue;}

		int x = v[0]+1;
		int y = v[0]-1;
		if(x>n){x-=n;}
		if(y<=0){y+=n;}
		if(x==v[1]){
			bool flag=true;
			for(int i=2;i<n;i++){
				int x = v[i-1]+1;
				if(x>n){x-=n;}
				if(x!=v[i]){flag=false;break;}
			}
			if(!flag){cout<<"NO"<<endl;}
			else{cout<<"YES"<<endl;}
		}else if(y==v[1]){
			bool flag=true;
			for(int i=2;i<n;i++){
				int x = v[i-1]-1;
				if(x<=0){x+=n;}
				if(x!=v[i]){flag=false;break;}
			}
			if(!flag){cout<<"NO"<<endl;}
			else{cout<<"YES"<<endl;}
		}else{
			cout<<"NO"<<endl;
		}
	}
}