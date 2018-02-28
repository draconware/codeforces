#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	string s;
	cin>>s;

	vector<int> v1,v2;
	int sum1=0,sum2=0;
	for(int i=0;i<3;i++){
		v1.push_back(s[i]-'0');
		sum1+=v1[i];
	}
	for(int i=3;i<6;i++){
		v2.push_back(s[i]-'0');
		sum2+=(s[i]-'0');
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());

	int ans=0;
	if(sum1 == sum2){ans=0;}
	else if(sum1>sum2){
		int j=0,k=2;
		while(sum1>sum2){
			if(9-v2[j] >= v1[k]){
				sum2+=(9-v2[j]);
				ans++;j++;
			}else{
				sum1-=(v1[k]);
				ans++;k--;
			}
		}
	}else{
		int j=0,k=2;
		while(sum2>sum1){
			if(9-v1[j] >= v2[k]){
				sum1+=(9-v1[j]);
				ans++;j++;
			}else{
				sum2-=(v2[k]);
				ans++;k--;
			}
		}
	}
	cout<<ans<<endl;
}