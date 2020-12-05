#include<bits/stdc++.h>
using namespace std;
int n;
int x[100];
int sum=0;
/*
判断第 k 个后能不能放在 x[k]处
两个皇后不能放在统一斜线上：
若 2 个皇后放置的位置分别是（i,j）和（k,l） ,
且 i-j = k -l 或 i+j = k+l，则说明这 2 个皇后处于同一斜线上。
*/
void output(){
    cout << "第" <<sum << "种放置方法为： " << endl;
    for(int i=1;i<=n;i++){
        cout << "(" <<i << "," << x[i] << ")" << endl;
    }
}
int place(int k){
for(int j=1;j<k;j++){
    if(x[j]==x[k] || abs(x[j]-x[k])== abs(j-k))
        return 0;
    }
    return 1;
}
void BackTrace(int t,int n){//递归
    if(t>n){////如果 t>n 说明已经完成一次放置
        sum++;
        output();
    }else{
        for(int i=1;i<=n;i++){
            x[t]=i;
            if(place(t)){// //可以放在 i 位置处，则继续搜索
                BackTrace(t+1,n);
            }
        }
    }
}
void BackTrace1(int n){//非递归
    int k;
    x[1]=0;
    k=1;
    while(k>=1){
        x[k]+=1;////先放在第一个位置
        while((x[k]<=n && !(place(k)))){//如果不能放
            x[k]++;// //放在下一个位置
        }
        if(x[k]<=n){
            if(k==n){// //如果已经放完了 n 个皇后
                sum++;
                output();
            }else{// //没有处理完，让 k 自加，处理下一个皇后
                k++;
                x[k]=0;
            }
        }else{// 当前无法完成放置，则进行剪枝，回溯回去，回到第 k-1 步
                k--;
            }
    }
}
int main()
{
    memset(x,0,sizeof(x));cin >> n;
    cout << n << "皇后的放置方法为" << endl;
    //BackTrace(1,n);
    BackTrace1(n);
    return 0;
}