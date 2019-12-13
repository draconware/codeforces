#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

int cnt[100009];

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

	bool flag=false;

	for(int i=0;i<n;i++){
		int x;cin>>x;
		v.pb(x);
		if(x>0){flag=true;}
	}
	if(!flag){cout<<"cslnb"<<endl;return 0;}

	sort(v.begin(),v.end());

	int idx;

	for(int i=0;i<n;){
		int j=i,val=0;
		while(j<n){
			if(v[j]==v[i]){val++;j++;}
			else{break;}
		}
		if(val==2){idx = v[i];}
		if((v[i]==0) && (val>=2)){cout<<"cslnb"<<endl;return 0;}
		i=j;
		cnt[val]++;
	}

	for(int i=3;i<=n;i++){
		if(cnt[i]>0){cout<<"cslnb"<<endl;return 0;}
	}
	if(cnt[2]>1){cout<<"cslnb"<<endl;return 0;}
	if(cnt[2]==1){
		for(int i=0;i<n;i++){
			if(v[i]==idx-1){cout<<"cslnb"<<endl;return 0;}
		}
	}
	if(v[n-1]==n-1){cout<<"cslnb"<<endl;return 0;}
	int par=0;
	for(int i=0;i<n;i++){
		par = (par + (v[i]-i)%2)%2;
	}
	if(par == 1){cout<<"sjfnb"<<endl;}
	else{cout<<"cslnb"<<endl;}
}