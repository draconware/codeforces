#include<bits/stdc++.h>
using namespace std;

vector<int> G[209];
bool mark[100009];
int cnt[100009];

bool comp(int a,int b){
	return a>b ;
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

	vector<int> v;
	int maxi = INT_MIN;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		v.push_back(a);
		maxi = max(maxi,a);
		mark[a] = true;
		cnt[a]++;
	}

	vector<int> cost;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		cost.push_back(a);
	}

	for(int i=0;i<n;i++){
		G[cost[i]].push_back(v[i]);
	}
	for(int i=1;i<=200;i++){
		sort(G[i].begin(),G[i].end());
	}


	int ans = INT_MAX;
	for(int i=1;i<=maxi;i++){
		if(!mark[i]){continue;}
		int sum = 0,x = n;
		for(int j=1;j<=200;j++){
			vector<int>::iterator it = upper_bound(G[j].begin(),G[j].end(),i);
			int k = it - G[j].begin();
			int len = (int)G[j].size();

			sum = sum + (len - k)*j;
			x -= (len - k);
		}

		if(x < 2*cnt[i]){ans = min(ans,sum);}
		for(int j=1;j<=200;j++){
			vector<int>::iterator it = lower_bound(G[j].begin(),G[j].end(),i);
			int k = it - G[j].begin();
			if(k==0){continue;}
			k--;
			int y = x - 2*(cnt[i]);
			if((k+1) > y){
				x-=y;
				sum = sum + (y+1)*j;
				ans = min(ans,sum);
				break;
			}else{
				x-=(k+1);
				sum = sum + (k+1)*j;
			}
			//if(i==3){cout<<j<<" "<<sum<<endl;}
		}
		//cout<<ans<<" ";
	}
	cout<<ans<<endl;
}