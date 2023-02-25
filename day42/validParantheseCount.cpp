// You are using GCC
#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<char> s;
    string str;
    int count=0;
    cin>>str;
    if(str==""){cout<<0;
        return 0;
    }
    for(int i = 0; i<str.size(); i++){
        if(str[i]=='('){
            s.push(str[i]);
        }else {
            if(!s.empty() && s.top()=='('){
                count+=2;
                s.pop();
            }
        }
    }
    cout<<count;
    return 0;
}