#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

map<LL,int> mp1;

LL power(LL a,LL b,LL c){
	LL res=1;
	while(b>0){
		if(b%2){
			res = (res*a)%c;
		}
		b/=2;
		a=(a*a)%c;
	}
	return res;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int n;
	LL p,k;
	cin>>n>>p>>k;

	for(int i=1;i<=n;i++){
		LL x;cin>>x;
		LL val = (power(x,4,p) - (k*x)%p + p)%p;
	//	cout<<x<<" "<<val<<endl;
		mp1[val]++;
	}

	map<LL,int>::iterator it=mp1.begin();

	LL ans=0;
	while(it!=mp1.end()){
		LL cnt=it->second;
	//	cout<<cnt<<endl;
		ans+=(cnt*(cnt-1))/2;
		it++;
	}
	cout<<ans<<endl;
}