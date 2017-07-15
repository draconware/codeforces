#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    int n;
    cin>>n;

    LL v[n],temp=0,p,count=0;
    for(int i=0;i<n;i++){
        cin>>p;
        temp+=p;

        v[i]=temp;
    }

    LL sum1=0,sum2=0,sum3=0;
    for(int i=0;i<n-1;i++){
        sum1=v[i];
        int low=i+1,high=n-2;

        while(low<=high){
            int mid = (low+high)/2;

            sum2 = (v[mid] - v[i]);
            sum3 = (v[n-1] - v[mid]);

            if(sum1 != sum2){
                if(sum2 > sum3){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }else{
                if(sum2 > sum3){
                    high = mid-1;
                }else if(sum2 < sum3){
                    low = mid+1;
                }else{
                    count++;
                    for(int k=mid+1;k<=high;k++){
                        if(v[k] == v[mid]){
                            count++;
                        }else{
                            break;
                        }
                    }
                    for(int k=mid-1;k>=low;k++){
                        if(v[k] == v[mid]){
                            count++;
                        }else{
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }

    cout<<count<<endl;
    return 0;
}
