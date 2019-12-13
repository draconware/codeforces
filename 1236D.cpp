#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

vector<int> vr[100009],vl[100009],vu[100009],vd[100009];

LL tot;
int limit_r;
int limit_d;
int limit_l;
int limit_u;

void get_ans(){
	if(tot==0){cout<<"Yes"<<endl;}
	else{cout<<"No"<<endl;}
}

pii move_right(int x,int y){
	vector<int>::iterator it  = lower_bound(vr[x].begin(),vr[x].end(),y);
	if((it == vr[x].end()) || (*it > limit_r)){
		return mp(x,limit_r);
	}else{
		return mp(x,*it - 1);
	}
}

pii move_left(int x,int y){
	auto it = upper_bound(vl[x].begin(),vl[x].end(),y);

	if((it == vl[x].begin())){
		return mp(x,limit_l);
	}else{
		it--;
		if(*it < limit_l){
			return mp(x,limit_l);
		}else{
			return mp(x,*it+1);
		}
	}
}

pii move_up(int x,int y){
	auto it = upper_bound(vu[y].begin(),vu[y].end(),x);
	if(it == vu[y].begin()){
		return mp(limit_u,y);
	}else{
		it--;
		if(*it < limit_u){
			return mp(limit_u,y);
		}else{
			return mp(*it+1,y);
		}
	}
}

pii move_down(int x,int y){
	auto it = lower_bound(vd[y].begin(),vd[y].end(),x);
	if((it == vd[y].end()) || (*it > limit_d)){
		return mp(limit_d,y);
	}else{
		return mp(*it-1,y);
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

	int n,m,k;
	cin>>n>>m>>k;

	map<pii,bool> mp1;
	for(int i=0;i<k;i++){
		int x,y;
		cin>>x>>y;

		mp1[mp(x,y)] = true;
		vr[x].pb(y);
		vl[x].pb(y);
		vu[y].pb(x);
		vd[y].pb(x);
	}
	if(k==0){cout<<"Yes"<<endl;return 0;}

	for(int i=1;i<=n;i++){sort(vr[i].begin(),vr[i].end());sort(vl[i].begin(),vl[i].end());}
	for(int i=1;i<=m;i++){sort(vu[i].begin(),vu[i].end());sort(vd[i].begin(),vd[i].end());}

	int curr_x = 1,curr_y = 1;
	tot = (1LL*n*m - 1LL*k);

	limit_r = m;
	limit_d = n;
	limit_l = 1;
	limit_u = 2;

	while(1){
		pii p = move_right(curr_x,curr_y);
		tot-=(p.second - curr_y + 1);
		curr_x = p.first;
		curr_y = p.second;

		limit_r = min(limit_r,curr_y-1);
		curr_x++;

		if((curr_x > limit_d) || (mp1[mp(curr_x,curr_y)])){
			get_ans();
			break;
		}

		p = move_down(curr_x,curr_y);
		tot-=(p.first - curr_x+1);
		curr_x = p.first;
		curr_y = p.second;

		limit_d = min(limit_d,curr_x-1);
		curr_y--;

		if((curr_y < limit_l) || (mp1[mp(curr_x,curr_y)])){
			get_ans();
			break;
		}

		p = move_left(curr_x,curr_y);
		tot-=(curr_y-p.second+1);
		curr_x = p.first;
		curr_y = p.second;

		limit_l = max(limit_l,curr_y+1);
		curr_x--;

		if((curr_x < limit_u) || (mp1[mp(curr_x,curr_y)])){
			get_ans();
			break;
		}

		p = move_up(curr_x,curr_y);
		tot-=(curr_x - p.first+1);
		curr_x = p.first;
		curr_y = p.second;

		limit_u = max(limit_u,curr_x+1);
		curr_y++;

		if((curr_y > limit_r) || (mp1[mp(curr_x,curr_y)])){
			get_ans();
			break;
		}
	}
}