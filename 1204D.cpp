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

	string s;cin>>s;
	int n = (int)s.length();

	stack<int> st;

	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			st.push(i);
		}else{
			if(!st.empty() && s[st.top()]=='1'){st.pop();}
			else{st.push(i);}
		}
	}

	while(!st.empty()){
		s[st.top()] = '0';st.pop();
	}
	cout<<s<<endl;
}