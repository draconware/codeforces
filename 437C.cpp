#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,x,y;
    cin>>n>>m;

    vector<pair<int,int> > temp;
    vector<int> arr(n+9);
    vector<int> v[n+9];
    bool mark[n+9];
    memset(mark,0,sizeof(mark));
    for(int i=0;i<n;i++){cin>>x;temp.push_back(make_pair(x,i+1));}
    sort(temp.begin(),temp.end());
    for(int i=0;i<n;i++){
        arr[temp[i].second]=temp[i].first;
    }

    for(int i=0;i<m;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int ans=0;
    for(int i=n;i>=1;i--){
        pair<int,int> p = temp[i-1];
        mark[p.second]=true;
        for(int j=0;j<v[p.second].size();j++){
            x=v[p.second][j];
            if(!mark[x]){
                ans+=arr[x];
            }
        }
    }
    cout<<ans<<endl;
}
