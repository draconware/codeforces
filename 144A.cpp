#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,ans=0,maxi=INT_MIN,mini=INT_MAX,pos_max,pos_min;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i] > maxi){maxi = arr[i];pos_max = i;}
        if(arr[i] <= mini){mini = arr[i];pos_min = i;}
    }
    ans+=(pos_max-0);
    if(pos_min < pos_max){ans += (n-1-pos_min-1);}
    else{ans+=(n-1-pos_min);}
    cout<<ans<<endl;
}
