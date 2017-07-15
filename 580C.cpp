#include<bits/stdc++.h>
using namespace std;

vector<int> v[100009];
int val[100009];
bool mark[100009];
int ans=0,m;

void dfs(int s,int curr){
    //cout<<s<<","<<curr<<","<<ans<<endl;
    if(mark[s]){return;}
    mark[s]=true;
    if(curr > m){return;}
    int count=0;
    for(int i=0;i<v[s].size();i++){
        if(!mark[v[s][i]]){
            if(val[v[s][i]]==1){dfs(v[s][i],curr+1);}
            else{dfs(v[s][i],0);}
            count++;
        }
    }
    if(count == 0){ans++;}
}

int main(){
    int n,a,x,y;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    memset(mark,0,sizeof(mark));
    if(val[1]==1){dfs(1,1);}
    else{dfs(1,0);}
    cout<<ans<<endl;
}
