#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	cin>>n;
	char c;
	int best=0,temp=0;
	for(int i=0;i<n;i++){
		cin>>c;
		if(c == ' '){best = max(best,temp);temp=0;}
		else{
			if(s[i]>='A' && s[i]<='Z'){temp++;}
		}
	}
	best = max(best,temp);
	cout<<best<<endl;
}