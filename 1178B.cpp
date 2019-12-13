#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

LL prefix[1000009],suffix[1000009];

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

	string t;

	for(int i=0;i<n;){
		if(s[i]=='o'){
			t.push_back(s[i]);
			i++;
		}else{
			int j=i,cnt=0;
			while(j<n){
				if(s[j]==s[i]){j++;cnt++;}
				else{break;}
			}
			cnt--;
			while(cnt>0){
				t.push_back(s[i]);cnt--;
			}
			i = j;
		}
	}
	// cout<<t<<endl;

	int len = (int)t.length();

	vector<int> pos;
	for(int i=0;i<len;i++){
		if(t[i]=='o'){
			pos.pb(i);
		}
	}

	if((int)pos.size() == 0){cout<<"0"<<endl;return 0;}

	prefix[0] = pos[0];
	for(int i=1;i<(int)pos.size();i++){
		prefix[i] = prefix[i-1] + (pos[i]-pos[i-1]-1);
	}

	suffix[(int)pos.size()-1] = ((int)t.length()-1 - pos[(int)pos.size()-1]);

	for(int i=(int)pos.size()-2;i>=0;i--){
		suffix[i] = suffix[i+1] + (pos[i+1] - pos[i] -1);
	}

	// for(int i=0;i<(int)pos.size();i++){
	// 	cout<<prefix[i]<<" ";
	// }cout<<endl;

	// for(int i=0;i<(int)pos.size();i++){
	// 	cout<<suffix[i]<<" ";
	// }cout<<endl;

	LL ans=0;
	// for(int i=0;i<(int)pos.size();i++){
	// 	cout<<pos[i]<<" ";
	// }cout<<endl;

	for(int i=0;i<(int)pos.size();i++){
		ans+=(prefix[i]*suffix[i]);
	}
	cout<<ans<<endl;
}