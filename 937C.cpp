#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cout<<fixed<<setprecision(13);
	LL k,d,t;
	cin>>k>>d>>t;

	if(k%d == 0){
		cout<<t<<endl;return 0;
	}
	//cout<<"executed"<<endl;
	LL a = k/d;a++;
	LL x = a*d + k;
	//cout<<x<<" "<<a<<endl;

	long double ans = 0;
	LL n = (2*t)/x;
	if((2*t)%x == 0){
		cout<<n*a*d<<endl;
		return 0;
	}
	//cout<<"executed"<<endl;

	ans = (long double)(n*a*d);

	long double timeleft = (long double)((2*t) - (n*x));
	//cout<<timeleft<<endl;
	if((timeleft/2.0) <= (long double)k){
		ans = ans + timeleft/2.0;
		cout<<ans<<endl;
		return 0;
	}
	//cout<<"executed"<<endl;

	ans = ans + (long double)k;
	ans = ans + (long double)(timeleft - (long double)(2*k));
	cout<<ans<<endl;
}