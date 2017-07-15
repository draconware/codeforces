#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    int request[n+1],arr[n+1];
    bool mark[n+1];

    for(int i=1;i<=n;i++){
        mark[i]=false;
    }
    for(int i=1;i<=n;i++){
        request[i]=0;
    }

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        request[arr[i]]++;
    }

    set< pair<int,int> > s;
    set< pair<int,int> >::iterator it;

    int r=0;
    for(int i=1;i<=n;i++){
        it = s.begin();
        if(!mark[arr[i]]){
            mark[arr[i]]=true;
            r++;
            request[arr[i]]--;
            if(s.empty()){
                s.insert(make_pair(request[arr[i]] , arr[i]));
            }else{
                if(s.size() == k){
                    s.erase(*it);
                    mark[ it->second ]=false;
                }
                s.insert(make_pair(request[arr[i]] , arr[i]));
            }
        }else{
            s.erase(make_pair(request[arr[i]] , arr[i]));
            request[arr[i]]--;
            s.insert(make_pair(request[arr[i]] , arr[i]));
        }
    }
    cout<<r<<endl;
}
