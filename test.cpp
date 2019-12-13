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

	vector<int> arr;
	vector<pii> v;

	for(int i=0;i<n;i++){
		int x;cin>>x;
		arr.pb(x);
	}
	sort(arr.begin(),arr.end());

	for(int i=0;i<n;){
		int j=i,cnt=0;
		while(arr[j]==arr[i]){
			cnt++;j++;
		}
		v.pb(mp(arr[i],cnt));
		i = j;
	}

	n = (int)v.size();

	LL ans=0;
	for(int c=2;c<n;c++){
		int a=0,b=c-1;
		while(a<b){
			if((v[a].ff + v[b].ff) > (v[c].ff)){
				b--;
			}else if((v[a].ff + v[b].ff) == (v[c].ff)){
				ans += (v[a].ss * v[b].ss * v[c].ss);a++;b--;
			}else{
				a++;
			}
		}
	}
	cout<<ans<<endl;
}