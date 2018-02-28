#include<bits/stdc++.h>
using namespace std;

int arr[500009];
int st[4*500009];
int ans;

int gcd(int a,int b){
	while(a>0){
		int t = a;
		a = b%a;
		b = t;
	}
	return b;
}

void build(int s,int e,int idx){
	if(s>e){return ;}
	if(s==e){
		st[idx] = arr[s];
		return ;
	}
	int m = (s+e)/2;
	build(s,m,2*idx+1);
	build(m+1,e,2*idx+2);

	st[idx] = gcd(st[2*idx+1],st[2*idx+2]);
}

void query(int s,int e,int idx,int l,int r,int x){
	if(ans>1){return ;}
	if(s>e || l>r || s>r || l>e){return ;}
	int m = (s+e)/2;
	if(l<=s && r>=e){
		if(st[idx]%x == 0){return ;}
		else{
			if(s==e){ans++;return;}
			query(s,m,2*idx+1,l,r,x);
			query(m+1,e,2*idx+2,l,r,x);
			return ;
		}
	}
	if(l<=m){query(s,m,2*idx+1,l,r,x);}
	if(r>m){query(m+1,e,2*idx+2,l,r,x);}
}

void update(int s,int e,int idx,int p,int val){
	if(s>e || s>p || e<p){return ;}
	if(s==e && s==p){
		st[idx] = val;
		return ;
	}
	int m =(s+e)/2;
	update(s,m,2*idx+1,p,val);
	update(m+1,e,2*idx+2,p,val);

	st[idx] = gcd(st[2*idx+1],st[2*idx+2]);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	scanf("%d", &n);

	for(int i=0;i<n;i++){scanf("%d", &arr[i]);}
	//for(int i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;

	build(0,n-1,0);

	int q;
	scanf("%d", &q);

	while(q--){
		int type;
		scanf("%d", &type);

		if(type==1){
			int l,r;
			int x;
			scanf("%d", &l);
			scanf("%d", &r);
			scanf("%d", &x);
			l--;r--;
			ans=0;
			query(0,n-1,0,l,r,x);
			//cout<<g.first<<","<<g.second<<endl;
			if(ans<=1){printf("YES\n");}
			else{printf("NO\n");}
		}else{
			int p;
			int x;
			scanf("%d", &p);
			scanf("%d", &x);

			update(0,n-1,0,p-1,x);
		}
	}
	return 0;
}