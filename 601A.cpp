#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y,n,m;
    cin>>n>>m;

    vector<int> train[n+9],bus[n+9];
    int mark[n+9][n+9];
    memset(mark,0,sizeof(mark));
    for(int i=0;i<m;i++){
        cin>>x>>y;
        train[x].push_back(y);
        train[y].push_back(x);
        mark[x][y]=true;
        mark[y][x]=true;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j){
                if(!mark[i][j]){
                    bus[i].push_back(j);
                }
            }
        }
    }
    bool vis[n+9];
    memset(vis,0,sizeof(vis));
    int ans1=-1,ans2=-1;
    queue< pair<int,int> > q;
    q.push(make_pair(1,0));

    while(!q.empty()){
        pair<int,int> p = q.front();q.pop();
        int x = p.first,w = p.second;
        //cout<<x<<" ";
        vis[x]=true;
        if(x == n){ans1=w;break;}
        for(int i=0;i<train[x].size();i++){
            if(!vis[train[x][i]]){
                q.push(make_pair(train[x][i],w+1));
            }
        }
    }
    for(int i=0;i<n+9;i++){
        train[i].clear();
    }
    if(ans1 == -1){cout<<"-1"<<endl;return 0;}
    memset(vis,0,sizeof(vis));
    queue< pair<int,int> > q1;
    q1.push(make_pair(1,0));
    while(!q1.empty()){
        pair<int,int> p = q1.front();q1.pop();
        int x = p.first,w = p.second;
        //cout<<x<<" ";
        vis[x]=true;
        if(x == n){ans2=w;break;}
        for(int i=0;i<bus[x].size();i++){
            if(!vis[bus[x][i]]){
                q1.push(make_pair(bus[x][i],w+1));
            }
        }
    }
    //cout<<ans1<<" "<<ans2<<endl;
    if(ans1 == -1 || ans2 == -1){
        cout<<"-1"<<endl;
    }else{
        cout<<max(ans1,ans2)<<endl;
    }
}
