#include<bits/stdc++.h>
using namespace std;

#define LL long long

vector<LL> x,y,z;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	LL n;
	cin>>n;

	LL arr[n],s=0;
	for(LL i=0;i<n;i++){
		cin>>arr[i];
		s+=arr[i];
	}
	if(s%3 != 0){
		cout<<"0"<<endl;
	}else{
		LL m = s/3,temp=0;
		for(LL i=0;i<n-2;i++){
			temp+=arr[i];
			if(temp==m){x.push_back(i);}
		}
		temp=0;
		for(LL i=n-1;i>1;i--){
			temp+=arr[i];
			if(temp==m){y.push_back(i);}
		}
		LL c = y.size();
		for(LL i=c-1;i>=0;i--){z.push_back(y[i]);}
		LL ans=0;
		for(LL i=0;i<x.size();i++){
			if(z.empty()){break;}
			vector<LL>::iterator it = upper_bound(z.begin(),z.end(),x[i]);
			LL size = z.size();
			if(it != z.end()){
				LL l = *it;
				if(l-x[i] > 1){ans += size - (it - z.begin());}
				else{
					it++;
					if(it != z.end()){
						ans += size - (it - z.begin());
					}
				}
			}
			//cout<<x[i]<<","<< *it<<" "<<ans<<endl;
		} 
		cout<<ans<<endl;
	}
	return 0;
}