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

		vector<int> temp;
		vector<pair<int,int> > cnt;
		for(int i=0;i<4*n;i++){
			int x;cin>>x;temp.pb(x);
		}
		sort(temp.begin(),temp.end());

		bool flag=true;

		for(int i=0;i<4*n;){
			int j=i,val=0;
			while(j<4*n){
				if(temp[j]==temp[i]){j++;val++;}
				else{break;}
			}
			if(val%2){flag=false;break;}
			while(val>0){
				cnt.pb(make_pair(temp[i],2));
				val-=2;
			}
			i = j;
		}

		if(!flag){cout<<"NO"<<endl;continue;}
		int l=0,r=(int)cnt.size()-1;

		int area = cnt[r].first*cnt[l].first;
		l++;r--;

		while(l<=r){
			if((cnt[l].first*cnt[r].first)==area){l++;r--;}
			else{flag=false;break;}
		}
		if(!flag){cout<<"NO"<<endl;}
		else{cout<<"YES"<<endl;}
	}
}