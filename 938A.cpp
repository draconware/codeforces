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
	string s;
	cin>>s;

	int x=0;
	for(int i=0;i<n;i++){
		if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='y'){
			if(x==0){cout<<s[i];x=1;}
		}else{
			cout<<s[i];
			x=0;
		}
	}
	cout<<endl;
}