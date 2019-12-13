#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

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

	string s;cin>>s;

	int x=0,y=0;
	for(int i=0;i<n;i++){
		if(s[i]=='('){x++;}
		else{y++;}
	}

	if(x!=y){cout<<"No"<<endl;}
	else{
		stack<char> st;
		for(int i=0;i<n;i++){
			if(s[i]=='('){st.push(s[i]);}
			else{
				if(!st.empty()){
					char c = st.top();
					if(c=='('){st.pop();}
					else{st.push(')');}
				}else{
					st.push(')');
				}
			}
		}
		if((int)st.size() <= 2){cout<<"Yes"<<endl;}
		else{cout<<"No"<<endl;}
	}
}