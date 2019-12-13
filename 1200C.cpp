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

	LL n,m;
	int q;
	cin>>n>>m>>q;

	LL g = gcd(n,m);
	n/=g;
	m/=g;
	// cout<<n<<" "<<m<<endl;

	while(q--){
		LL x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;

		LL sec1=0,sec2=0;
		// cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
		if(x1==1){
			sec1 = y1/n;
			if(y1%n){sec1++;}
		}else{
			sec1 = y1/m;
			if(y1%m){sec1++;}
		}
		if(x2==1){
			sec2 = y2/n;
			if(y2%n){sec2++;}
		}else{
			sec2 = y2/m;
			if(y2%m){sec2++;}
		}
		// cout<<sec1<<" "<<sec2<<endl;
		if(sec1 == sec2){cout<<"YES"<<endl;}
		else{cout<<"NO"<<endl;}
	}
}