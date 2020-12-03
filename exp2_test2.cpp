//
// Created by ant on 2020/9/30.
//
#include <map>
#include <vector>
#include <iostream>
using namespace std;
int main(){
    map<int,int> mymap; //定义map容器
    map<int,int>::iterator it;//定义map迭代器
    int n ;
    cout << "请输入数组长度:" << endl;
    cin >> n;//n值范围[2,20]
    cout << "请输入元素:"<< endl;
    for(int i=0;i<n;i++){
        int s;
        cin >> s ;
        if(mymap.count(s)){
            mymap[s]+=1;
        }else{
            mymap.insert(map<int,int>::value_type(s,1));
        }
    }
    cout << "打印元素以及其出现次数：" <<endl;
    for(it=mymap.begin();it!=mymap.end();it++){
        cout << it->first << " " << it->second << endl;
    }
    cout << "打印其中出现次数超过所有元素的一半的元素：" <<endl;
    for(it=mymap.begin();it!=mymap.end();it++){
        if(it->second > (n/2)){
            cout << it->first << " 出现次数为：" << it->second << endl;
        }
    }

}