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

	double h,l;
	cin>>h>>l;

	cout<<fixed<<setprecision(10);
	double ans = (l*l - h*h);
	ans = ans/(2.0*h);
	cout<<ans<<endl;
}