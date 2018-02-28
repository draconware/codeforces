#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	int n;
	cin>>n;

	map<string,int> m;
	m["polycarp"]=1;

	int best=1;
	string s1,s2,waste;
	while(n--){
		cin>>s1>>waste>>s2;
		for(int i=0;i<s1.length();i++){
			if((s1[i]>='A' && s1[i]<='Z')){
				s1[i] += 32;
			}
		}
		for(int i=0;i<s2.length();i++){
			if((s2[i]>='A' && s2[i]<='Z')){
				s2[i] += 32;
			}
		}
		m[s1] = m[s2]+1;
		best= max(best,m[s1]);
	}
	cout<<best<<endl;
}