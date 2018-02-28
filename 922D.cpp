#include<bits/stdc++.h>
using namespace std;

#define LL long long

bool comp(pair<pair<LL,LL>,LL> a,pair<pair<LL,LL>,LL> b){
	LL x = a.first.second*b.first.first;
	LL y = a.first.first*b.first.second;
	return (x>y);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	LL n;
	cin>>n;

	vector<pair<pair<LL,LL>,LL> > v;

	for(int i=0;i<n;i++){
		string s;cin>>s;
		int len = (int)s.length();
		LL x=0,y=0,res=0;
		for(int j=0;j<len;j++){
			if(s[j]=='s'){x++;}
			else{
				res+=x;
				y++;
			}
		}
		v.push_back(make_pair(make_pair(y,x),res));
	}

	sort(v.begin(),v.end(),comp);
	n = (int)v.size();

	long long ans = 0,x=0,y=0;
	
	for(int i=0;i<n;i++){
		ans = ans + v[i].second + x*v[i].first.first;
		x = x + v[i].first.second;
		y = y + v[i].first.first;
		//cout<<ans<<" ";
	}
	cout<<ans<<endl;
}