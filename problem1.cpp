#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1,s2,s3,ans;
    cin>>s1>>s2>>s3;
    map<char,int> m;
    for(int i=0;i<s1.length();i++){
        m[tolower(s1[i])]=i;
    }

    for(int i=0;i<s3.length();i++){
        //if(s3[i]-'0' <= 9){ans.push_back(s3[i]);continue;}
        if(tolower(s3[i])>=97 && tolower(s3[i])<=122){
        if(islower(s3[i])){
            ans.push_back(tolower(s2[m[tolower(s3[i])]]));
        }else{
            ans.push_back(toupper(s2[m[tolower(s3[i])]]));
        }
        }else{
        	ans.push_back(s3[i]);
        }
    }
    cout<<ans<<endl;
}
