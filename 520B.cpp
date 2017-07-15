#include<bits/stdc++.h>
using namespace std;

int level[20009];
bool mark[20009];

int main(){
    int n,m;
    cin>>n>>m;

    memset(mark,0,sizeof(mark));
    queue<int> q;
    q.push(n);
    level[n]=0;
    while(!q.empty()){
        int p = q.front();q.pop();
        //cout<<p<<endl;
        if(p == m){cout<<level[p]<<endl;break;}
        mark[p]=true;

        if(p>m){
            if(!mark[p-1]){
                q.push(p-1);
                level[p-1]=level[p]+1;
                mark[p-1]=true;
            }
        }else{
            if(!mark[2*p]){
                q.push(2*p);
                level[2*p] = level[p]+1;
                mark[2*p]=true;
            }
            if(!mark[p-1] && p-1>0){
                q.push(p-1);
                level[p-1]=level[p]+1;
                mark[p-1]=true;
            }
        }
    }
    return 0;
}
