#include<bits/stdc++.h>
using namespace std;

int common(vector<int> &n){
    cout<<"executed"<<endl;
    int ans = 0;
    cout<<"executed"<<endl;
    int p = n.size();
    cout<<"executed"<<endl;
    p--;
    cout<<p<<" executed"<<endl;

    for(int i=0;i<p;){
        int j = ( upper_bound(n.begin(),n.end(),n[i]) - n.begin() );

        if(n[j] != n[i]){
            cout<<"executed1"<<endl;
            ans += (j-i-1);
            i=j;
        }else{
            cout<<"executed"<<endl;
            ans += (j-i);
            i = (j+1);
            cout<<i<<endl;
        }
    }
    cout<<"executed"<<endl;
    return ans;
}

int main(){
    int n;
    cin>>n;

    vector< pair<int,int> > points;
    pair<int,int> temp;
    vector<int> x,y;

    for(int i=0;i<n;i++){
        cin>>temp.first;
        cin>>temp.second;

        points.push_back(temp);
        x.push_back(temp.first);
        y.push_back(temp.second);
    }

    sort(x.begin(),x.end());
    sort(y.begin(),y.end());

    int numbers = common(x);
    numbers += common(y);

    cout<<numbers<<endl;

    return 0;

}
