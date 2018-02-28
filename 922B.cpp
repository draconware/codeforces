#include<bits/stdc++.h>
using namespace std;

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

	int ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=j;k<=n;k++){
				if((i+j)>k){
					//cout<<i<<" "<<j<<" "<<k<<endl;
					if((i^j^k) == 0){ans++;}
				}else{
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
}