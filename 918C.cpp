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

	string s;
	cin>>s;

	int n = (int)s.length();
	int ans=0;

	for(int i=0;i<n;i++){
		int a=0,b=0;
		for(int j=i;j<n;j++){
			if(s[j] == '('){a++;}
			else if(s[j]==')'){
				a--;
				if(a<0){
					if(b>0){b--;a+=2;}
					else{break;}
				}
			}else{
				if(a>0){a--;b++;}
				else{a++;}
			}
			if(a==0){ans++;}
		}
	}
	cout<<ans<<endl;
}