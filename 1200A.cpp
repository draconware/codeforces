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

	string s;
	cin>>s;

	vector<int> res(10,0);

	for(int i=0;i<n;i++){
		char c = s[i];
		if(c=='L'){
			for(int j=0;j<10;j++){
				if(res[j]==0){res[j]=1;break;}
			}
		}else if(c=='R'){
			for(int j=9;j>=0;j--){
				if(res[j]==0){res[j]=1;break;}
			}
		}else{
			int x = c-'0';
			res[x]=0;
		}
	}
	for(int i=0;i<10;i++){cout<<res[i];}cout<<endl;
}