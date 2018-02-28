#include<bits/stdc++.h>
using namespace std;

int sqrtmo;
vector<int> arr;
int mp[100009];
vector<pair<pair<int,int>,int> > q;
int ans = 0;

bool comp(pair<pair<int,int>,int> x,pair<pair<int,int>,int> y){
	int l = x.first.first/sqrtmo;
	int r = y.first.first/sqrtmo;

	if(l==r){
		return (x.first.second < y.first.second);
	}else{
		return (l<r);
	}
}

void add(int x){
	if(mp[x] == x){
		ans--;
		mp[x]++;
	}else{
		mp[x]++;
	}
	if(mp[x] == x){ans++;}
}

void remove(int x){
	if(mp[x] == x){
		ans--;
		mp[x]--;
	}else{
		mp[x]--;
	}
	if(mp[x]==x){ans++;}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,m;
	scanf("%d %d", &n, &m);

	for(int i=0;i<n;i++){
		int a;scanf("%d", &a);
		arr.push_back(a);
	}

	sqrtmo = (int)floor(sqrt(n));

	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d %d", &x, &y);
		q.push_back(make_pair(make_pair(x-1,y-1),i));
	}

	sort(q.begin(),q.end(),comp);

	int moleft = 0,moright = -1;
	int res[m];
	for(int i=0;i<m;i++){
		int l = q[i].first.first;
		int r = q[i].first.second;

		while(moleft < l){
			if(arr[moleft]<=n){remove(arr[moleft]);}
			moleft++;
		}
		while(moleft > l){
			moleft--;
			if(arr[moleft]<=n){add(arr[moleft]);}
		}
		while(moright < r){
			moright++;
			if(arr[moright]<=n){add(arr[moright]);}
		}
		while(moright > r){
			if(arr[moright]<=n){remove(arr[moright]);}
			moright--;
		}
		res[q[i].second] = ans;
	}
	for(int i=0;i<m;i++){printf("%d\n",res[i]);}
}