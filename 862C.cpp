#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,x,p=(int)pow(2,17);
	cin>>n>>x;

	if(n==1){cout<<"YES\n"<<x<<endl;}
	else if(n==2){
		if(x==0){cout<<"NO"<<endl;}
		else{cout<<"YES\n 0 "<<x<<endl;}
	}else{
		cout<<"YES"<<endl;
		int y=0;
		vector<int> res;
		for(int i=1;i<=n-3;i++){res.push_back(i);y^=i;}
		
		if(x==y){res.push_back(p);res.push_back(2*p);res.push_back(p^(2*p));}
		else{
			res.push_back(0);res.push_back(p);res.push_back(x^y^p);
		}
		sort(res.begin(),res.end());
		for(int i=0;i<n;i++){cout<<res[i]<<" ";}cout<<endl;
	}
}