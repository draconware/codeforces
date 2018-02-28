#include<bits/stdc++.h>
using namespace std;

#define LL long long 

LL f(LL n,LL x){
	LL l=1,r=n;
	while(l<=r){
		LL m = (l+r)/2;
		if((n/m) == x){return m;}
		else if((n/m) > x){l = m+1;}
		else{r = m-1;}
	}
	return -1;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin>>t;

	while(t--){
		LL x;
		cin>>x;

		bool flag=false;
		if(x==0){cout<<"1 1"<<endl;continue;}
		for(LL i=1;(i*i)<=x;i++){
			if(x%i == 0){
				LL a = i;
				LL b = x/i;
				LL c = a;
				a = min(a,b);
				b = max(c,b);
				if((a+b)%2 == 0){
					LL n = (a+b)/2;
					LL l = (b-a)/2;
					LL m = f(n,l);
					if(m != -1){
						cout<<n<<" "<<m<<endl;flag=true;break;
					}
				}
			}
		}
		if(!flag){cout<<"-1"<<endl;}
	}
}