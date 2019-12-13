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
		string x,y;
		cin>>x>>y;

		reverse(x.begin(),x.end());
		reverse(y.begin(),y.end());

		int posy=0,posx=0;
		for(int i=0;i<(int)y.length();i++){
			if(y[i]=='1'){posy=i;break;}
		}
		for(int i=posy;i<(int)x.length();i++){
			if(x[i]=='1'){posx=i;break;}
		}
		if(posx>=posy){cout<<(posx-posy)<<endl;}
		else{cout<<"0"<<endl;}
	}
}