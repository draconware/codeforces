#include<bits/stdc++.h>
using namespace std;

int pricebuy[100009],pricesell[100009];
vector<int> buy,sell;

bool comp(pair<int,int> x,pair<int,int> y){
	return x.first>y.first;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,s;
	cin>>n>>s;

	for(int i=0;i<n;i++){
		char c;
		cin>>c;

		if(c=='B'){
			int x,y;
			cin>>x>>y;
			if(pricebuy[x]==0){buy.push_back(x);}
			pricebuy[x]+=y;
		}else{
			int x,y;
			cin>>x>>y;
			if(pricesell[x]==0){sell.push_back(x);}
			pricesell[x]+=y;
		}
	}

	vector<pair<int,int> > finalbuy,finalsell;
	for(int i=0;i<(int)buy.size();i++){
		finalbuy.push_back(make_pair(buy[i],pricebuy[buy[i]]));
	}
	for(int i=0;i<(int)sell.size();i++){
		finalsell.push_back(make_pair(sell[i],pricesell[sell[i]]));
	}

	sort(finalbuy.begin(),finalbuy.end(),comp);
	sort(finalsell.begin(),finalsell.end());

	vector<pair<int,int> > buyans,sellans;
	for(int i=0;i<min(s,(int)finalbuy.size());i++){
		buyans.push_back(finalbuy[i]);
	}
	for(int i=0;i<min(s,(int)finalsell.size());i++){
		sellans.push_back(finalsell[i]);
	}

	sort(sellans.begin(),sellans.end(),comp);
	for(int i=0;i<(int)sellans.size();i++){cout<<"S "<<sellans[i].first<<" "<<sellans[i].second<<endl;}
	for(int i=0;i<(int)buyans.size();i++){cout<<"B "<<buyans[i].first<<" "<<buyans[i].second<<endl;}
}