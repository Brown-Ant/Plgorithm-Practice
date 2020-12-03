//
// Created by ant on 2020/10/6.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<string>
using namespace std;
int CN(int n){
    if(n==1){
        return 1;
    }
    if(n%2==0){
        return CN(n-1)+2;
    }else{
        return CN(n-2)+CN(n-1)-1;
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<"A"<<i<<"="<<CN(i)<<" ";
    }

    return 0;
}

