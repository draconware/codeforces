#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL power(LL x,LL y,LL m){
	LL res = 1;
	while(y>0){
		if(y&1){
			res = (res*x)%m;
		}
		y/=2;
		x = (x*x)%m;
	}
	return res;
}

LL inv(LL a,LL m)
{
    LL m0 = m;
    LL y = 0, x = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {
        // q is quotient
        LL q = a / m;
        LL t = m;

        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
       x += m0;

    return x;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	LL a,b,p,x;
	cin>>a>>b>>p>>x;

	LL limit = min(p-1,x);
	LL ans = 0;

	for(int i=1;i<=limit;i++){
		LL y = (LL)power(2,i,p);
		y = (b*inv(y,p))%p;

		LL low = (1-i - ((i-y)*(p-1)));
		low = low/(p*(p-1));
		if(low<=0){low=0;}

		LL high = (x-i - ((i-y)*(p-1)));
		if(high<0){
			high = -1;
		}else{
			high = high/(p*(p-1));
		}
		cout<<i<<","<<y<<" "<<low<<","<<high<<endl;
		if(low<=high){
			ans +=( high-low+1);
		}
	}
	cout<<ans<<endl;
}	