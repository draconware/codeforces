#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	long long n,k;
	cin>>n>>k;

	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	if(k>=n-1){
		int ans = INT_MIN;
		for(int i=0;i<n;i++){ans = max(ans,arr[i]);}
		cout<<ans<<endl;
	}else{
		//int ans;
		deque<int> q;
		for(int i=0;i<n;i++){
			q.push_back(arr[i]);
		}
		while(1){
			int y = q.front();q.pop_front();
			int z = q.front();q.pop_front();
			q.push_back(min(y,z));
			int x = k-1;

			while(x>0){
				if(q.front() < max(y,z)){q.push_back(q.front());q.pop_front();x--;}
				else{q.push_front(max(y,z));break;}
			}
			if(x==0){cout<<max(y,z)<<endl;return 0;}
		}
	}
}