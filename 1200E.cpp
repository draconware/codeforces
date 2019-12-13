#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

int compute(string s){
	int n = (int)s.length();

	vector<int> v(n);

	int len = 0;
	int i=1;
	v[0] = 0;

	while(i<n){
		if(s[i]==s[len]){
			len++;
			v[i] = len;
			i++;
		}else{
			if(len!=0){len = v[len-1];}
			else{
				v[i] = 0;
				i++;
			}
		}
	}
	return v[n-1];
}

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

	vector<string> v;

	for(int i=0;i<n;i++){
		string s;cin>>s;
		v.pb(s);
	}

	string ans = v[0];

	for(int i=1;i<n;i++){
		int x = (int)v[i].length();
		int y = (int)ans.length();

		string temp;
		if(x<=y){
			temp = v[i] + ans.substr(y-x,x);
			int z = compute(temp);
			ans = ans + v[i].substr(z,x-z);
		}else{
			temp = v[i].substr(0,y) + ans;
			int z = compute(temp);
			ans = ans + v[i].substr(z,x-z);
		}
	}
	cout<<ans<<endl;
}