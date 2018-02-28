#include<bits/stdc++.h>
using namespace std;

#define LL long double

LL p[60];

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	LL s,k;
	int q;
	cin>>s>>q>>k;

	for(int i=0;i<q;i++){cin>>p[i];}
	sort(p,p+q);

	LL ans=s;

	for(int i=0;i<q;i++){
		ans = max(ans+k,ans+(ans*(p[i]/100)));
	}
	printf("%.12LF\n",ans);
}