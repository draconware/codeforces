#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

LL gcd(LL a,LL b){
	while(a>0){
		LL c = a;
		a = b%a;
		b = c;
	}
	return b;
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
	cin>>n;

	vector<LL> v;
	for(int i=0;i<n;i++){
		LL x;cin>>x;
		v.pb(x);
	}

	LL g = v[0];
	for(int i=1;i<n;i++){
		g = gcd(v[i],g);
	}

	//cout<<g<<endl;

	LL ans=0;

	for(LL i=1;i*i<=g;i++){
		if((g%i)==0){
			if(i == (g/i)){ans++;}
			else{ans+=2;}
		}
	}
	cout<<ans<<endl;
}