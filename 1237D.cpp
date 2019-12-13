#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

double arr[100009];
double st[4*100009];

void build(int s,int e,int idx){
	if(s==e){st[idx] = arr[s];return ;}
	int m = (s+e)/2;

	build(s,m,2*idx+1);
	build(m+1,e,2*idx+2);

	st[idx] = min(st[2*idx+1],st[2*idx+2]);
}

int query(int s,int e,int idx,int l,int r,double val,int def){
	if(l>e || r<s){return def;}
	if(l<=s && r>=e){
		if(st[idx]<val){
			if(s!=e){
				int m = (s+e)/2;
				return min(query(s,m,2*idx+1,l,r,val,def),query(m+1,e,2*idx+2,l,r,val,def));
			}else{
				return s;
			}
		}else{
			return def;
		}
	}
	int m = (s+e)/2;
	return min(query(s,m,2*idx+1,l,r,val,def),query(m+1,e,2*idx+2,l,r,val,def));
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

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	build(0,n-1,0);
	// for(int i=0;i<=6;i++){cout<<st[i]<<" ";}cout<<endl;
	vector<int> stop;

	for(int i=0;i<n;i++){
		int ans = 1;
		bool flag=false;
		if((i+1)<n){
			int pos = query(0,n-1,0,i+1,n-1,arr[i]/2,n);
			if(pos != n){stop.push_back(pos);flag=true;}
		}
		if((i-1)>=0 && !flag){
			int pos = query(0,n-1,0,0,i-1,arr[i]/2.0,i);
			if(pos != i){stop.push_back(pos);flag=true;}
		}
		if(!flag){stop.push_back(-1);}
	}

	// for(int i=0;i<n;i++){cout<<stop[i]<<" ";}cout<<endl;
	bool f = false;
	for(int i=0;i<n;i++){
		if(stop[i]!=-1){f=true;break;}
	}
	if(!f){
		for(int i=0;i<n;i++){cout<<"-1"<<" ";}cout<<endl;
		return 0;
	}

	int idx = 0;
	vector<int> ans;
	bool flag=false;
	for(int i=0;i<n;i++){
		if(!flag){
			if(idx<i){idx = i;}
		}
		while(idx<n){
			if(stop[idx]!=-1){break;}
			idx++;
		}
		if(idx==n){
			flag=true;
			idx=0;
			while(idx<n){
				if(stop[idx]!=-1){break;}
				idx++;
			}
		}
		int cnt = 1;
		if(idx>=i){
			cnt+=(idx-i);
			if(stop[idx]<idx){
				cnt+=(n-1-idx);
				cnt+=(stop[idx]);
			}else{
				cnt+=(stop[idx]-1-idx);
			}
		}else{
			cnt+=(n-1-i);
			cnt+=(idx-i);
			if(stop[idx]<idx){
				cnt+=(n-1-idx);
				cnt+=(stop[idx]);
			}else{
				cnt+=(stop[idx]-1-idx);
			}
		}
		ans.push_back(cnt);
	}
	for(int i=0;i<n;i++){cout<<ans[i]<<" ";}cout<<endl;
}