#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

int st[400009][26];
int lazy[400009][26];
string str;
int cnt[26];

void build(int s,int e,int idx){
	if(s==e){
		st[idx][str[s]-'a']++;
		return ;
	}
	int m = (s+e)/2;

	build(s,m,2*idx+1);
	build(m+1,e,2*idx+2);

	for(int i=0;i<26;i++){
		st[idx][i] = (st[2*idx+1][i] + st[2*idx+2][i]);
	}
}

void update(int s,int e,int idx,int pos,int val,int count){
	for(int i=0;i<26;i++){
		if(lazy[idx][i]!=0){
			st[idx][i]+=lazy[idx][i];
			if(s!=e){
				lazy[2*idx+1][i]+=lazy[idx][i];
				lazy[2*idx+2][i]+=lazy[idx][i];
			}
			lazy[idx][i] = 0;
		}
	}

	if(s>pos || e<pos){return ;}
	if(s==e){
		st[idx][val]+=count;
		return ;
	}
	int m = (s+e)/2;

	update(s,m,2*idx+1,pos,val,count);
	update(m+1,e,2*idx+2,pos,val,count);

	for(int i=0;i<26;i++){
		st[idx][i] = st[2*idx+1][i] + st[2*idx+2][i];
	}
}

void query(int s,int e,int idx,int l,int r){
	for(int i=0;i<26;i++){
		if(lazy[idx][i] != 0){
			st[idx][i] += lazy[idx][i];
			if(s!=e){
				lazy[2*idx+1][i]+=lazy[idx][i];
				lazy[2*idx+2][i]+=lazy[idx][i];
			}
			lazy[idx][i] = 0;
		}
	}

	if(s>r || l>e){return ;}
	if(l<=s && r>=e){
		for(int i=0;i<26;i++){cnt[i]+=st[idx][i];}
		return ;
	}
	int m = (s+e)/2;
	query(s,m,2*idx+1,l,r);
	query(m+1,e,2*idx+2,l,r);

	for(int i=0;i<26;i++){
		st[idx][i] = (st[2*idx+1][i] + st[2*idx+2][i]);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>str;

	int n = (int)str.length();
	build(0,n-1,0);

	int q;
	cin>>q;

	while(q--){
		int t;
		cin>>t;

		if(t==1){
			int pos;
			char c;
			cin>>pos>>c;

			update(0,n-1,0,pos-1,str[pos-1]-'a',-1);
			update(0,n-1,0,pos-1,c-'a',1);
			str[pos-1] = c;
		}else{
			int x,y;
			cin>>x>>y;

			memset(cnt,0,sizeof(cnt));

			query(0,n-1,0,x-1,y-1);

			int ans=0;
			for(int i=0;i<26;i++){
				if(cnt[i]){ans++;}
			}
			cout<<ans<<endl;
		}
		// for(int i=0;i<13;i++){
		// 	// cout<<i<<" ----- "<<endl;
		// 	for(int j=0;j<26;j++){
		// 		cout<<st[i][j]<<" ";
		// 	}
		// 	// cout<<endl;

		// 	for(int j=0;j<26;j++){
		// 		cout<<lazy[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		// cout<<" ---------- "<<endl;
	}
}