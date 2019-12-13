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

	int t;
	cin>>t;

	while(t--){
		LL n,m;
		cin>>n>>m;
		LL val = 0;
		LL sum = 0;
	
		for(int i=1;i<=10;i++){
			val+=m;
			if(n>=val){sum+=(val%10);}
		}
		// cout<<val<<" "<<sum<<endl;
	
		if(val<n){
			LL val2 = n/val;
			val2--;
	
			sum+=(val2*sum);
			val = (n/val)*val;
			val+=m;
			while(n>=val){
				sum+=(val%10);
				val+=m;
			}
		}
		cout<<sum<<endl;
	}
}