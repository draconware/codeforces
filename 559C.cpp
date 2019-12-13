#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

LL fact[200009];
LL invfact[200009];
LL M = (LL)(1e9 + 7);
LL val[2009];

LL power(LL a,LL b){
	LL res = 1;
	while(b>0){
		if(b%2){res = (res*a)%M;}
		b/=2;
		a=(a*a)%M;
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

	int h,w,n;
	cin>>h>>w>>n;

	vector<pii> v;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		v.pb(mp(x,y));
	}
	v.pb(mp(h,w));

	sort(v.begin(),v.end());

	fact[0] = 1;
	for(int i=1;i<=h+w;i++){
		fact[i] = (fact[i-1]*i)%M;
	}

	for(int i=0;i<=h+w;i++){
		invfact[i] = power(fact[i],M-2);
	}
	n = (int)v.size();

	for(int i=0;i<n;i++){
		pii p = v[i];
		int x = p.ff;
		int y = p.ss;

		// cout<<"Evaluating --- "<<x<<" "<<y<<endl;

		LL tot = (fact[x+y-2]*invfact[x-1])%M;
		tot = (tot*invfact[y-1])%M;

		for(int j=0;j<i;j++){
			if(x>=v[j].ff && y>=v[j].ss){
				// cout<<"In Range --- "<<v[j].ff<<","<<v[j].ss<<endl;
				LL paths = val[j];
				int x1 = x-v[j].ff;
				int y1 = y-v[j].ss;
				paths = (paths*fact[x1+y1])%M;
				paths = (paths*invfact[x1])%M;
				paths = (paths*invfact[y1])%M;
				// cout<<"paths -- "<<paths<<endl;
				tot = (tot - paths+M)%M;
				// cout<<"total -- "<<tot<<endl;
			}
		}
		val[i] = tot;
	}
	// for(int i=0;i<n;i++){cout<<val[i]<<" ";}cout<<endl;
	cout<<val[n-1]<<endl;
}