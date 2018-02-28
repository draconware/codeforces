#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL absll(LL x){
	if(x>0){return x;}
	else{return -x;}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,m,q;
	cin>>n>>m>>q;

	LL a[n+1],b[m+1];
	for(int i=1;i<=n;i++){cin>>a[i];}
	for(int i=1;i<=m;i++){cin>>b[i];}
	//for(int i=1;i<=n;i++){cout<<a[i]<<" ";}cout<<endl;
	//for(int i=1;i<=m;i++){cout<<b[i]<<" ";}cout<<endl;

	LL c = 0;
	for(int i=1;i<=n;i++){
		if(i%2 == 0){c = c - a[i];}
		else{c = c+a[i];}
	}
	//cout<<c<<endl;
	LL sum[m-n+1];
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++){
		if(i%2 == 0){sum[0] += b[i];}
		else{sum[0]-=b[i];}
	}
	for(int i=n+1;i<=m;i++){
		sum[i-n] = -b[i-n]-sum[i-n-1];
		if(n%2 == 0){sum[i-n] += b[i];}
		else{sum[i-n] -= b[i];}
	}
	vector<LL> v;
	for(int i=0;i<=m-n;i++){
		v.push_back(sum[i]);
	}
	sort(v.begin(),v.end());
	//for(int i=0;i<=m-n;i++){cout<<v[i]<<" ";}cout<<endl;
	//vector<LL>::iterator it1 = lower_bound(v.begin(),v.end(),-c);
	vector<LL>::iterator it1 = lower_bound(v.begin(),v.end(),-c);
	int j = it1-v.begin();
	LL res;
	if(j > 0 && j<m-n+1){
		res = min(absll(c+v[j]),absll(c+v[j-1]));
	}else if(j==0){
		res = absll(c+v[j]);
	}else if(j==m-n+1){
		res = absll(c+v[j-1]);
	}
	cout<<res<<endl;

	while(q--){
		int l,r,x;
		cin>>l>>r>>x;

		if((r-l+1)%2 != 0){
			if(l%2 == 0){c = c-x;}
			else{c = c+x;}
		}

		vector<LL>::iterator it1 = lower_bound(v.begin(),v.end(),-c);
		int i = it1-v.begin();
		LL ans;
		if(i > 0 && i<m-n+1){
			ans = min(absll(c+v[i]),absll(c+v[i-1]));
		}else if(i==0){
			ans = absll(c+v[i]);
		}else if(i==m-n+1){
			ans = absll(c+v[i-1]);
		}
		cout<<ans<<endl;
	}
	return 0;
}	