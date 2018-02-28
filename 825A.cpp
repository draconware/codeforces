#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.in","r",stdin);
  	freopen("output.out","w",stdout);
  	#endif

	int n;
	cin>>n;

	string s;
	cin>>s;

	int a=0;
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			a++;
		}else{
			cout<<a;
			a=0;
		}
	}
	cout<<a<<endl;
}