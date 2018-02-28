#include<bits/stdc++.h>
using namespace std;

struct coin{
	int head,tail;
};

struct coin arr[4*100000];
int lazy[4*100000];

void build(int s,int e,int idx){
	if(s>e){return;}
	if(s==e){
		arr[idx].head=0;
		arr[idx].tail=1;
	}else{
		int m = (s+e)/2;
		build(s,m,2*idx+1);
		build(m+1,e,2*idx+2);

		arr[idx].head = arr[2*idx+1].head + arr[2*idx+2].head;
		arr[idx].tail = arr[2*idx+1].tail + arr[2*idx+2].tail;
	}
}

void update(int l,int h,int s,int e,int idx){
	if(lazy[idx]!=0){
		if(lazy[idx]%2 !=0){
			swap(arr[idx].head,arr[idx].tail);
			if(s!=e){
				lazy[2*idx+1]+=lazy[idx];
				lazy[2*idx+2]+=lazy[idx];
			}
		}
		lazy[idx]=0;
	}
	if(s>e || s>h || l>e){return;}
	if(s<=l && e>=h){
		swap(arr[idx].head,arr[idx].tail);
		if(s!=e){
			lazy[2*idx+1]++;
			lazy[2*idx+2]++;
		}
		return;
	}
	int m = (s+e)/2;
	update(l,h,s,m,2*idx+1);
	update(l,h,m+1,e,2*idx+2);
	arr[idx].head = arr[2*idx+1].head + arr[2*idx+2].head;
	arr[idx].tail = arr[2*idx+1].tail + arr[2*idx+2].tail;
}

int query(int l,int h,int s,int e,int idx){
	if(s>e || s>h || l>e){return 0;}
	if(lazy[idx]!=0){
		if(lazy[idx]%2 !=0){
			swap(arr[idx].head,arr[idx].tail);
			if(s!=e){
				lazy[2*idx+1]+=lazy[idx];
				lazy[2*idx+2]+=lazy[idx];
			}
		}
		lazy[idx]=0;
	}
	if(s<=l && e>=h){
		return arr[idx].head;
	}
	int m = (s+e)/2;
	int x = query(l,h,s,m,2*idx+1);
	int y = query(l,h,m+1,e,2*idx+2);
	return (x+y);
}

int main(){
	int n,m;
	cin>>n>>m;

	memset(lazy,0,sizeof(lazy));
	build(0,n-1,0);

	int q;
	cin>>q;

	while(q--){
		int x,a,b;
		cin>>x>>a>>b;
		if(x==1){
			int x = query(a,b,0,n-1,0);
			cout<<x<<endl;			
		}else{
			update(a,b,0,n-1,0);
		}
	}
	return 0;
}