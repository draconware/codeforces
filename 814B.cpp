#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n;

    vector<int> a(n),b(n),p(n);
    set<int> s,ini;

    for(int i=1;i<=n;i++){
        ini.insert(i);
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]==b[i]){
            p[i]=a[i];
            s.insert(a[i]);
            ini.erase(a[i]);
        }else{
            p[i]=0;
        }
    }
    for(int i=0;i<n;i++){
        if(p[i]==0){
            if(s.find(a[i]) == s.end()){
                s.insert(a[i]);
                p[i] = a[i];
                ini.erase(a[i]);
            }else if(s.find(b[i]) == s.end()){
                s.insert(b[i]);
                p[i] = b[i];
                ini.erase(b[i]);
            }else{
                m=i;
            }
        }
    }
    set<int>::iterator it=ini.begin();
    if(!ini.empty()){
        p[m] = *it;
    }
    for(int i=0;i<n;i++){
        cout<<p[i]<<" ";
    }
}
