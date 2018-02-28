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

	string s1,s2;
	cin>>s1>>s2;

	string res;
	bool flag=false;
	res.push_back(s1[0]);
	for(int i=1;i<(int)s1.length();i++){
		if(s2[0]<=s1[i]){break;}
		else{res.push_back(s1[i]);}
	}
	res.push_back(s2[0]);
	cout<<res<<endl;
}