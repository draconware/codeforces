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

	LL n,p,w,d;
	cin>>n>>p>>w>>d;

	LL g = gcd(w,d);
	if(p%g){cout<<"-1"<<endl;return 0;}

	p/=g;
	w/=g;
	d/=g;

	for(LL x=0;x<=1000000;x++){
		if((p-x*w)>=0 && (p-x*w)%d==0){
			LL y = (p-x*w)/d;
			if((x+y)<=n){cout<<x<<" "<<y<<" "<<n-(x+y)<<endl;return 0;}
		}
		if((p-x*d)>=0 && (p-x*d)%w==0){
			LL y = (p-x*d)/w;
			if((x+y)<=n){cout<<y<<" "<<x<<" "<<n-(x+y)<<endl;return 0;}
		}
	}
	cout<<"-1"<<endl;
}