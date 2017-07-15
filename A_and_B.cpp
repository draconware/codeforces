#include<bits/stdc++.h>
using namespace std;

#define long long

int main(){
    int n,m,p;
    cin>>n;

    m=n;
    vector<int> error,v,temp;

    for(int i=0;i<n;i++){
        cin>>p;
        error.push_back(p);
    }
    m--;
    for(int i=0;i<m;i++){
        cin>>p;
        v.push_back(p);
    }
    sort(v.begin(),v.end());
    temp = v;

    for(int i=0;i<n;i++){
        if(!(binary_search(temp.begin(),temp.end(),error[i]))){
            cout<< error[i] <<endl;
            error.erase(error.begin() + i);
            break;
        }else{
            temp.erase(lower_bound(temp.begin(),temp.end(),error[i]));
        }
    }
    n--;m--;
    v.clear();

    for(int i=0;i<m;i++){
        cin>>p;
        v.push_back(p);
    }
    sort(v.begin(),v.end());
    temp = v;
    for(int i=0;i<n;i++){
        if(!(binary_search(v.begin(),v.end(),error[i]))){
            cout<< error[i] <<endl;
            error.erase(error.begin() + i);
            break;
        }else{
            temp.erase(lower_bound(temp.begin(),temp.end(),error[i]));
        }
    }
    return 0;
}
