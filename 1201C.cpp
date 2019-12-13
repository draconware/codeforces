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
	LL k;
	cin>>n>>k;

	vector<int> v;

	for(int i=0;i<n;i++){
		int x;cin>>x;
		v.pb(x);
	}

	sort(v.begin(),v.end());

	int idx = n/2;
	int res = v[idx];

	int cnt=0;

	while(idx<n && k>=cnt){
		int j = idx;
		while(j<n){
			if(v[j]==v[idx]){j++;cnt++;}
			else{break;}
		}
		if(j==n){
			res += (k/cnt);
		}else{
			int val2 = v[j];
			int val1 = v[idx];
			int d = val2-val1;
			if(d*cnt <= k){
				k-=(d*cnt);
				res = v[j];
			}else{
				res += (k/cnt);
				break;
			}
		}
		idx = j;
	}
	cout<<res<<endl;
}