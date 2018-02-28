#include<bits/stdc++.h>
using namespace std;

struct radio{
	int x,r,f;
};

bool comp(struct radio a,struct radio b){
	return a.r > b.r;
}

struct node{
	long long val;
	struct node *left,*right;
};

struct node* freq[10009];

struct node *update(int s,int e,struct node *idx,int p){
	//cout<<"executed"<<endl;
	if(!idx){
		idx = (struct node*)malloc(sizeof(struct node));
		idx->left = NULL;
		idx->right = NULL;
		idx->val = 0;
	}
	if(s>p || e<p || s>e){return idx;}
	if(s==e && s==p){
		idx->val = idx->val +1;
		return idx;
	}
	int m = (s+e)/2;
	idx->left = update(s,m,idx->left,p);
	idx->right = update(m+1,e,idx->right,p);
	idx->val = idx->left->val + idx->right->val;
	return idx;
}

long long query(int s,int e,struct node *idx,int l,int r){
	//cout<<"executed!"<<endl;
	if(!idx){
		return 0;
	}
	if(s>e || s>r || l>e || l>r){return 0;}
	if(l<=s && r>=e){return idx->val;}

	int m = (s+e)/2;
	return query(s,m,idx->left,l,r)+query(m+1,e,idx->right,l,r);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,k;
	cin>>n>>k;

	struct radio arr[n];

	for(int i=0;i<n;i++){
		cin>>arr[i].x>>arr[i].r>>arr[i].f;
	}

	sort(arr,arr+n,comp);

	for(int i=0;i<10009;i++){
		freq[i] = NULL;
	}

	long long ans=0;

	for(int i=0;i<n;i++){
		//cout<<"executed"<<endl;
		for(int j=max(1,arr[i].f-k);j<=min(10000,arr[i].f+k);j++){
			ans = ans + query(1,1000000000,freq[j],max(1,arr[i].x-arr[i].r),min(1000000000,arr[i].x+arr[i].r));
		}
	//	cout<<"executed"<<endl;
		//cout<<ans<<endl;
		freq[arr[i].f] = update(1,1000000000,freq[arr[i].f],arr[i].x);
	}
	cout<<ans<<endl;
}