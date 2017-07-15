#include<bits/stdc++.h>
using namespace std;

int main(){
    string str,str2="heidi";
    cin>>str;

    if(str.length() == str2.length()){
        if(str == str2){cout<<"YES"<<endl;}
        else{cout<<"NO"<<endl;}

    }else if(str.length() > str2.length()){
        int j=0;
        for(int i=0;i<str.length();i++){
            if(str[i] == str2[j]){
                j++;
            }
        }
        if(j == 5){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }else{
        cout<<"NO"<<endl;
    }

    return 0;
}
